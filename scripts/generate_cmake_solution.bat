SET BATCH_ORIG_DIR=%~dp0

set SRC_DIR=%BATCH_ORIG_DIR%..\src\

cd %SRC_DIR%

cmake -G "Visual Studio 16 2019" -S . -B ../build/ 

cd %BATCH_ORIG_DIR%