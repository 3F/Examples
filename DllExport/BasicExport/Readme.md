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
.NET ClassLibrary1.dll is ready for requests:                           #
                                                                         #
  AmazingSin(5, 0, 0) == -nan(ind)                                       #
    Is NaN(AmazingSin(5, 0, 0)): yes                                    #
  AmazingSin(5, 24.781, 11) == 5.249363e+00                           #
    Is NaN(AmazingSin(5, 24.781, 11)): no                          #    #
                                                                #        #
        (5, 24.781, 27.0) == 1.288480e+01                    #           #
        (6, 24.781, 27.0) == 1.348346e+01                 #             #
        (7, 24.781, 27.0) == 1.321995e+01              #              #
        (8, 24.781, 27.0) == 1.211111e+01           #              #
        (9, 24.781, 27.0) == 1.022785e+01         #             #
        (10, 24.781, 27.0) == 7.690583e+00      #            #
        (11, 24.781, 27.0) == 4.661560e+00     #          #
        (12, 24.781, 27.0) == 1.334461e+00     #       #
        (13, 24.781, 27.0) == -2.077966e+00     #   #
        (14, 24.781, 27.0) == -5.357522e+00      ##
        (15, 24.781, 27.0) == -8.294501e+00     #   #
        (16, 24.781, 27.0) == -1.070110e+01    #       #
        (17, 24.781, 27.0) == -1.242344e+01    #          #
        (18, 24.781, 27.0) == -1.335139e+01     #           #
        (19, 24.781, 27.0) == -1.342560e+01      #              #
        (20, 24.781, 27.0) == -1.264134e+01         #              #
        (21, 24.781, 27.0) == -1.104875e+01            #             #
        (22, 24.781, 27.0) == -8.749674e+00               #            #
        (23, 24.781, 27.0) == -5.891111e+00                 #            #
        (24, 24.781, 27.0) == -2.655852e+00                     #        #
        (25, 24.781, 27.0) == 7.492310e-01                         #     #
        (26, 24.781, 27.0) == 4.106406e+00                           # #
        (27, 24.781, 27.0) == 7.201003e+00                           # #
        (28, 24.781, 27.0) == 9.835146e+00                         #     #
        (29, 24.781, 27.0) == 1.184040e+01                     #         #
        (30, 24.781, 27.0) == 1.308854e+01                  #            #
        (31, 24.781, 27.0) == 1.349976e+01                #            #
        (32, 24.781, 27.0) == 1.304775e+01            #              #
        (33, 24.781, 27.0) == 1.176144e+01          #              #
        (34, 24.781, 27.0) == 9.723061e+00       #             #
        (35, 24.781, 27.0) == 7.062958e+00      #           #
        (36, 24.781, 27.0) == 3.951228e+00     #          #
        (37, 24.781, 27.0) == 5.868432e-01     #      #
        (38, 24.781, 27.0) == -2.815066e+00     #   #
        (39, 24.781, 27.0) == -6.036971e+00      ##
        (40, 24.781, 27.0) == -8.872853e+00     #   #
        (41, 24.781, 27.0) == -1.114138e+01    #       #
        (42, 24.781, 27.0) == -1.269748e+01    #           #
        (43, 24.781, 27.0) == -1.344168e+01     #            #
        (44, 24.781, 27.0) == -1.332636e+01       #             #
        (45, 24.781, 27.0) == -1.235892e+01         #              #
        (46, 24.781, 27.0) == -1.060121e+01            #              #
        (47, 24.781, 27.0) == -8.165623e+00                #            #
        (48, 24.781, 27.0) == -5.207901e+00                  #           #
        (49, 24.781, 27.0) == -1.917169e+00                     #        #
        (50, 24.781, 27.0) == 1.496152e+00                         #    #
        (51, 24.781, 27.0) == 4.813805e+00                            ##
        (52, 24.781, 27.0) == 7.823648e+00                           #  #
        (53, 24.781, 27.0) == 1.033322e+01                        #      #
        (54, 24.781, 27.0) == 1.218206e+01                     #         #
        (55, 24.781, 27.0) == 1.325193e+01                  #           #
        (56, 24.781, 27.0) == 1.347444e+01               #             #
        (57, 24.781, 27.0) == 1.283534e+01            #              #
        (58, 24.781, 27.0) == 1.137552e+01         #              #
        (59, 24.781, 27.0) == 9.188304e+00       #             #
        (60, 24.781, 27.0) == 6.413562e+00      #           #
        (61, 24.781, 27.0) == 3.228716e+00     #         #
        (62, 24.781, 27.0) == -1.625840e-01    #      #
        (63, 24.781, 27.0) == -3.543488e+00        #
        (64, 24.781, 27.0) == -6.697810e+00      #
        (65, 24.781, 27.0) == -9.423853e+00     #
        (66, 24.781, 27.0) == -1.154731e+01    #
        (67, 24.781, 27.0) == -1.293239e+01    #
        (68, 24.781, 27.0) == -1.349053e+01
        (69, 24.781, 27.0) == -1.318604e+01

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
    * *Please note: this example also provides own **.vcxproj.user** file just to configure something for your environment. Because, seems, this may cause misunderstanding with debugging by default for some users. Override this in `Properties` - `Debugging` if you know what you do.*

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



