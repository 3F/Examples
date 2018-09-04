`[[ The Sample 1 for native C++ projects ]]`

* The 'Sample1.sln' is ready for VS2013 & VS2015. Open it in your IDE and try to Rebuild for Debug & Release configurations.
* The all 'build_*.bat' is ready for MSBuild v12.0 & v14.0. Simply click it, and watch similar as in result above.
    * ./build_v14.0_[Release].bat - [![](https://img.shields.io/badge/build-passing-brightgreen.svg?style=flat)](https://ci.appveyor.com/project/3Fs/ci-msbuild-demo/build/build-4) :: build-4: 9e1cd110
* See also Sample 1 with .NET projects in /Sample1/.NET/

Tested on:

* CI.MSBuild: 
    * `v1.6.0.3805 [ 48df3db ]`
    * `v1.5.0.2692 [ 8bde22a ]`
* vsSolutionBuildEvent: 
    * `v0.12.7.3805 [ 48df3db ]`
    * `v0.12.3.2692 [ 8bde22a ]`

You can read about this:

* Here: https://visualstudiogallery.msdn.microsoft.com/0d1dbfd7-ed8a-40af-ae39-281bfeca2334/
* Or here: http://vssbe.r-eg.net


Note to Sample 1:

* The 'result.log' should appear after the all operations and will be opened automatically for Debug configuration.
* Confirmation dialog is also used only in Debug configuration.
* All content from 'result.log' will be displayed in stdout for all configurations.