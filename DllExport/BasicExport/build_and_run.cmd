call .\DllExport -hMSBuild -t:restore -t:Build ~c Debug ~p x64
cd bin\x64\Debug\ & cls & UnmanagedCppConsole.exe & dir & pause