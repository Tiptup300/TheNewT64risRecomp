# Executable target for The New T64ris : Recompiled.
add_executable(TntRecompiled)

set(TNT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/register_overlays.cpp
    ${CMAKE_SOURCE_DIR}/src/stubs.cpp
    ${CMAKE_SOURCE_DIR}/rsp/n_aspMain.cpp
)

# Use the LLD linker: it resolves the circular static-lib dependencies between
# RecompiledFuncs / librecomp / recompui without needing --start-group.
# -rdynamic exports symbols so backtrace() prints function names on a crash.
# (Linux/clang toolchain only; the Windows/clang-cl link is set up below.)
if (NOT WIN32)
    target_link_options(TntRecompiled PRIVATE -fuse-ld=lld -rdynamic)
endif()

target_include_directories(TntRecompiled PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/N64Recomp/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/librecomp/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/ultramodern/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/thirdparty/sse2neon
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/nativefiledialog-extended/src/include
    ${CMAKE_SOURCE_DIR}/lib/RecompFrontend/recompinput/include
    ${CMAKE_SOURCE_DIR}/lib/RecompFrontend/recompui/include
    # recompui's theme API (set_theme_color etc.) lives in an internal header;
    # add its dir so we can theme the launcher/config menus from src/main.cpp.
    ${CMAKE_SOURCE_DIR}/lib/RecompFrontend/recompui/src/elements
    ${CMAKE_CURRENT_BINARY_DIR}
)

# -march=nehalem gives SSSE3/SSE4.1 needed by the RSP VU microcode implementation.
if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    target_compile_options(TntRecompiled PRIVATE -march=nehalem -fno-strict-aliasing -fms-extensions)
else()
    target_compile_options(TntRecompiled PRIVATE -fno-strict-aliasing -fms-extensions)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(SDL2 REQUIRED)
    find_package(X11 REQUIRED)
    find_package(Freetype REQUIRED)
    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

    target_include_directories(TntRecompiled PRIVATE ${SDL2_INCLUDE_DIRS} ${X11_INCLUDE_DIR})
    target_link_libraries(TntRecompiled PRIVATE
        ${X11_LIBRARIES} ${X11_Xrandr_LIB} ${FREETYPE_LIBRARIES}
        "-latomic -static-libstdc++" ${CMAKE_DL_LIBS} Threads::Threads SDL2::SDL2)
endif()

if (WIN32)
    # Use the SDL2 fetched at the top level (${sdl2_SOURCE_DIR}), same as recompui/recompinput.
    target_include_directories(TntRecompiled PRIVATE "${sdl2_SOURCE_DIR}/include")
    target_link_directories(TntRecompiled PRIVATE "${sdl2_SOURCE_DIR}/lib/x64")
    target_link_libraries(TntRecompiled PRIVATE SDL2 Winmm.lib)
    target_link_options(TntRecompiled PRIVATE /OPT:NOICF)
    # No console window in release; main() is the entry point (SDL2main's WinMain
    # is bypassed by /ENTRY, matching BanjoRecomp).
    set_target_properties(TntRecompiled PROPERTIES
        LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
        LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
        LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
        LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    # Ship SDL2 + the DXC runtime DLLs (D3D12 runtime shader compilation) beside the exe.
    add_custom_command(TARGET TntRecompiled POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${sdl2_SOURCE_DIR}/lib/x64/SDL2.dll"
            "${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxil.dll"
            "${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxcompiler.dll"
            $<TARGET_FILE_DIR:TntRecompiled>)
endif()

target_link_libraries(TntRecompiled PRIVATE
    RecompiledFuncs
    recompui
    recompinput
    librecomp
    ultramodern
    rt64
    nfd
)

target_sources(TntRecompiled PRIVATE ${TNT_SOURCES})
set_property(TARGET TntRecompiled PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
