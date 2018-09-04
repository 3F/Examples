# Sample 2 

## v1.6.1207 via GetNuTool

*It will be automatically distributed on another machines (where any of our program is not installed at all) via [GetNuTool](https://github.com/3F/GetNuTool).*

* The 'Sample2.sln' is ready for VS2013 & VS2015. Open it in your IDE and click Rebuild.
* The all 'build_*.bat' is ready for MSBuild v12.0 & v14.0. Simply click it and watch similar as in result above.
* Similar script for other project types - native C++, etc.


[![](https://img.shields.io/badge/build-passing-brightgreen.svg?style=flat)](https://ci.appveyor.com/project/3Fs/ci-msbuild-demo/build/build-9) :: build-9: 9f3658e0

* [Artifacts](https://ci.appveyor.com/project/3Fs/ci-msbuild-demo/build/build-9/artifacts)

Tested on:

* CI.MSBuild: 
    * `v1.6.0.3805 [ 48df3db ]`
* vsSolutionBuildEvent: 
    * `v0.12.7.3805 [ 48df3db ]`

This is a simple example for work with - CI.MSBuild / vsSolutionBuildEvent. You will see next features:

* Generate the unique label for all project as version of this or similar.
* Create the archives of binaries from projects:
* Create the common 'bin' folder if needed and put the following artifacts:

```
├───bin
│       ClassLibrary1_2016.02.07_12;45;49.1366_[5EAFE1F]_[net45].7z
│       ConsoleApplication1_2016.02.07_12;45;49.1366_[5EAFE1F]_[net45].tar.xz
│       Release_notes.txt
│       Sample2_2016.02.07_12;45;49.1366_[5EAFE1F]_[net45].zip
│
```

Where:

* '.7z', '.tar.xz', '.zip' the final archives which is created by [SevenZipComponent](http://vssbe.r-eg.net/doc/Scripts/SBE-Scripts/Components/SevenZipComponent/)
* 'Release_notes.txt' - as a summary of this, for example:

```
This assembled from:

* Configuration:   'Debug'
* .NET version:     v4.5 (net45);
* MSBuild Tools:    v14.0;
* Label:            2016.02.07_12;45;49.1366_[5EAFE1F];
* Sha1:             5EAFE1FBA3BEDAA59302AB42D7E9210AC4566C6C;
```