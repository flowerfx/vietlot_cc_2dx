echo off

pushd "%cd%\.."

set DATA_RAW=Resources
set DATA_COPY_TO=..\proj.win32\vietlot_win32_Debug.win32\cpp-empty-test

echo ================copy data ==================:

xcopy /s/y %DATA_RAW% 	%DATA_COPY_TO%

popd