# Package TntRecompiled into a Windows zip: TheNewT64ris/ with the exe, the
# SDL2 + DXC runtime DLLs (copied next to the exe by the build), and assets/.
# No game data is included; the user supplies their ROM at runtime.
$ErrorActionPreference = "Stop"
$root  = Split-Path -Parent $PSScriptRoot
$bin   = Join-Path $root "build-cmake\TntRecompiled.exe"
$stage = Join-Path $root "dist\TheNewT64ris"

if (-not (Test-Path $bin)) { throw "binary not found: $bin" }

Remove-Item -Recurse -Force $stage -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force -Path $stage | Out-Null

Copy-Item $bin (Join-Path $stage "TheNewT64ris.exe")
Copy-Item (Join-Path $root "build-cmake\*.dll") $stage
Copy-Item -Recurse (Join-Path $root "assets") (Join-Path $stage "assets")
Copy-Item (Join-Path $root "packaging\RUN.txt") $stage -ErrorAction SilentlyContinue

# Sanity checks.
foreach ($f in @("TheNewT64ris.exe", "SDL2.dll", "assets\fonts\primary.ttf")) {
    if (-not (Test-Path (Join-Path $stage $f))) { throw "missing from package: $f" }
}

$zip = Join-Path $root "dist\TheNewT64ris-windows-x64.zip"
if (Test-Path $zip) { Remove-Item $zip }
Compress-Archive -Path $stage -DestinationPath $zip
Write-Host "packaged: $zip"
Get-ChildItem $stage | Format-Table Name, Length
