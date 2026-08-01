cmake_minimum_required(VERSION 3.20)

project(TntRecompiled LANGUAGES C CXX)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(RT64_STATIC TRUE)
set(RT64_SDL_WINDOW_VULKAN TRUE)
add_compile_definitions(HLSL_CPU)

# On Linux, make the RT64/plume window handle an SDL_Window* (SDL-Vulkan integration),
# matching what recompui's rt64_render_context.cpp expects. BanjoRecomp sets these too.
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    add_compile_definitions(PLUME_SDL_VULKAN_ENABLED RT64_SDL_WINDOW_VULKAN)
endif()

# SDL2 is needed by rt64, recompui and recompinput. On Linux, find_package sets
# SDL2_INCLUDE_DIRS (consumed by recompui/recompinput) and the SDL2::SDL2 target.
# On Windows, reuse the SDL2 that rt64 bundles (mupen64plus-win32-deps) so the
# frontend libs get their headers without a separate SDL2 install.
if (WIN32)
    add_compile_definitions(NOMINMAX)
    # recompui/recompinput reference ${sdl2_SOURCE_DIR} on Windows, so SDL2 must be
    # provided via FetchContent under the name "sdl2" (this is what BanjoRecomp does).
    # This also sets SDL2_INCLUDE_DIRS for anything else that consumes it.
    include(FetchContent)
    if (DEFINED ENV{SDL2_VERSION})
        set(SDL2_VERSION $ENV{SDL2_VERSION})
    else()
        set(SDL2_VERSION "2.30.3")
    endif()
    FetchContent_Declare(sdl2
        URL https://github.com/libsdl-org/SDL/releases/download/release-${SDL2_VERSION}/SDL2-devel-${SDL2_VERSION}-VC.zip)
    FetchContent_MakeAvailable(sdl2)
    set(SDL2_INCLUDE_DIRS "${sdl2_SOURCE_DIR}/include")
else()
    find_package(SDL2 REQUIRED)
endif()

# ROM file picker: use the XDG desktop portal (via D-Bus) instead of GTK for
# nativefiledialog-extended (pulled in by rt64). The portal works on non-GTK and
# immutable desktops (e.g. Fedora COSMIC Atomic) and removes the hard GTK3
# dependency from the binary. Requires xdg-desktop-portal at runtime (present on
# any modern desktop session); the TNT_ROM=/path env fallback covers the rest.
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(NFD_PORTAL ON CACHE BOOL "nfd: use xdg-desktop-portal instead of GTK" FORCE)
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/rt64 ${CMAKE_BINARY_DIR}/rt64)

set(BUILD_SHARED_LIBS OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime)

target_include_directories(rt64 PRIVATE ${CMAKE_BINARY_DIR}/rt64/src)

# RecompiledFuncs - the primary recompiler output for The New T64ris
add_library(RecompiledFuncs STATIC)
target_compile_options(RecompiledFuncs PRIVATE
    -fno-strict-aliasing
    -Wno-unused-variable
    -Wno-implicit-function-declaration
)
target_include_directories(RecompiledFuncs PRIVATE
    ${CMAKE_SOURCE_DIR}/RecompiledFuncs
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/ultramodern/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/librecomp/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/N64Recomp/include
)
file(GLOB_RECURSE FUNC_C_SOURCES ${CMAKE_SOURCE_DIR}/RecompiledFuncs/*.c)
file(GLOB_RECURSE FUNC_CXX_SOURCES ${CMAKE_SOURCE_DIR}/RecompiledFuncs/*.cpp)
target_sources(RecompiledFuncs PRIVATE ${FUNC_C_SOURCES} ${FUNC_CXX_SOURCES})

# DXC (HLSL->SPIR-V) — recompui compiles its own InterfaceVS/PS.hlsl using rt64's
# build_*_shader helpers, which need the DXC variable defined in this scope.
# (BanjoRecomp duplicates this block for the same reason.)
set (DXC_COMMON_OPTS "-I${PROJECT_SOURCE_DIR}/src")
set (DXC_DXIL_OPTS "-Wno-ignored-attributes")
set (DXC_SPV_OPTS "-spirv" "-fspv-target-env=vulkan1.0" "-fvk-use-dx-layout")
set (DXC_PS_OPTS "${DXC_COMMON_OPTS}" "-E" "PSMain" "-T ps_6_0" "-D DYNAMIC_RENDER_PARAMS")
set (DXC_VS_OPTS "${DXC_COMMON_OPTS}" "-E" "VSMain" "-T vs_6_0" "-D DYNAMIC_RENDER_PARAMS" "-fvk-invert-y")
set (DXC_CS_OPTS "${DXC_COMMON_OPTS}" "-E" "CSMain" "-T cs_6_0")
set (DXC_GS_OPTS "${DXC_COMMON_OPTS}" "-E" "GSMain" "-T gs_6_0")
set (DXC_RT_OPTS "${DXC_COMMON_OPTS}" "-D" "RT_SHADER" "-T" "lib_6_3" "-fspv-target-env=vulkan1.1spirv1.4" "-fspv-extension=SPV_KHR_ray_tracing" "-fspv-extension=SPV_EXT_descriptor_indexing")
if (WIN32)
    set (DXC "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxc.exe")
else()
    set (DXC "LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/x64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxc-linux")
endif()

# RecompFrontend (recompui + recompinput) — must be added after rt64.
set(RECOMP_FRONTEND_N64MODERNRUNTIME_PATH ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime)
set(RECOMP_FRONTEND_RT64_PATH ${CMAKE_SOURCE_DIR}/lib/rt64)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/RecompFrontend)

# The executable (src/ glue) is added below once the game glue is written.
include(${CMAKE_SOURCE_DIR}/executable.cmake OPTIONAL)
