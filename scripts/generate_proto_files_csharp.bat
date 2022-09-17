SET BATCH_ORIG_DIR=%~dp0

set PROTO_SRC_DIR=%BATCH_ORIG_DIR%..\proto\
set SRC_DIR=%BATCH_ORIG_DIR%..\src\csharp_sample\
set OUT_DIR=%SRC_DIR%proto_gen_files\
set PROTO_EXE_DIR=%BATCH_ORIG_DIR%..\src\dependencies\bin\

cd /d %SRC_DIR%
mkdir proto_gen_files

cd %PROTO_EXE_DIR%

protoc.exe -I=%PROTO_SRC_DIR% --csharp_out=%OUT_DIR% %PROTO_SRC_DIR%test.proto

cd %BATCH_ORIG_DIR%