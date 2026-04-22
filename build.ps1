# LibreAI Windows build script
# Requirements: Qt6, LibreOffice SDK, CMake, MSVC or MinGW
param(
    [switch]$Install
)

$ErrorActionPreference = "Stop"
$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path

Write-Host "==> Configuring..." -ForegroundColor Cyan
cmake -S $ScriptDir -B "$ScriptDir\build" -DCMAKE_BUILD_TYPE=Release
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "==> Compiling..." -ForegroundColor Cyan
cmake --build "$ScriptDir\build" --config Release --parallel $env:NUMBER_OF_PROCESSORS
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Copy-Item "$ScriptDir\build\Release\libreai.dll" "$ScriptDir\libreai.dll" -Force

Write-Host "==> Packaging libreai.oxt..." -ForegroundColor Cyan
$oxt = "$ScriptDir\libreai.oxt"
if (Test-Path $oxt) { Remove-Item $oxt }

Push-Location $ScriptDir
Compress-Archive -Path `
    "META-INF", `
    "description.xml", `
    "description-en.txt", `
    "Addons.xcu", `
    "Jobs.xcu", `
    "libreai.dll", `
    "icons" `
    -DestinationPath $oxt
Pop-Location

Write-Host "==> Built: $oxt" -ForegroundColor Green

if ($Install) {
    Write-Host "==> Installing..." -ForegroundColor Cyan
    $unopkg = "$env:PROGRAMFILES\LibreOffice\program\unopkg.com"
    & $unopkg remove org.libreai 2>$null
    & $unopkg add -f $oxt
    Write-Host "==> Done. Restart LibreOffice to activate." -ForegroundColor Green
}
