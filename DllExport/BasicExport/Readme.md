## [/Examples/DllExport/BasicExport](https://github.com/3F/Examples/tree/master/DllExport/BasicExport)

This example illustrates basic communication with managed .NET libraries from unmanaged native C++ (host side).

In the manner of [Conari syntax](https://github.com/3F/Conari):

C++

```cpp
PEModule lib(_T("ClassLibrary1.dll")); // ClassLibrary1.dll is C# project

// call exported function: double AmazingSin(int ofs, double x, double y)
double x1 = lib.call<double, int, double, double>("AmazingSin", 5, 0, 0);

// another way
double x2 = lib.call<double>("AmazingSin", 5, 24.781, (double)11);
...
```

Or via custom wrappers:

```cpp
AlgVB vb(_T("ClassLibrary2.dll")); // ClassLibrary1.dll is VB.NET project

// call exported function: SuperPow(ByVal x As Integer, ByVal y As Integer) As Double
double x = vb.superPow(2, 3);
...
```

Console will show you something like:
```text
.NET ClassLibrary1.dll is ready for requests:

  AmazingSin(5, 0, 0) == -nan(ind)
    Is NaN(AmazingSin(5, 0, 0)): yes
  AmazingSin(5, 24.781, 11) == 5.249363e+00
    Is NaN(AmazingSin(5, 24.781, 11)): no

AlgVB wrapper of .NET ClassLibrary2.dll is ready:

  AlgVB.superPow(2, 3) == 8.000000e+00
```

Find output binaries in `.\bin` folder per architecture (x86 & x64) and configuration (Debug & Release).

## Additional Requirements

* You need C++ compiler compatible with **C++17** standard.
    * MSVC: **/std:c++17**

## Steps

* Open *BasicExport.sln* in Visual Studio  *( **v15+** (VS2017+) is recommended ).*
* And Navigate to *UnmanagedCppConsole* project.
* Debug this at runtime (press F5) to learn code in details.
    * *Please note: this example also provides own **.vcxproj.user** file just to configure something for your environment. Because, seems, this may cause misunderstanding with debugging by default for some users. If you know what you do, please check settings in `Properties` - `Debugging`*

Try also to watch **[this screencast](https://www.youtube.com/watch?v=9Hyg3_WE9Ks)** if you don't understand something. 

## Questions and errors

Ask here: https://github.com/3F/Examples/issues/new


## Feel free

```
// This example has been prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < entry.reg@gmail.com > :: github.com/3F
// Distributed under the MIT License
```

A cup of coffee [ [☕](https://3F.github.io/Donation/) ] or some donations: [![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif)](https://3F.github.io/Donation/) 



