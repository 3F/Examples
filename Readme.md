# [3F/Examples](https://github.com/3F/Examples)

[![Default License](https://img.shields.io/badge/Default_License-MIT-74A5C2.svg)](https://github.com/3F/Examples/blob/master/LICENSE.TXT)

This repository contains (or will contain) complete examples for various popular projects like:

* [ [DllExport](https://github.com/3F/DllExport) ]; [ [Conari](https://github.com/3F/Conari) ];  [ [GetNuTool](https://github.com/3F/GetNuTool) ]; [ [vsSolutionBuildEvent](https://github.com/3F/vsSolutionBuildEvent) ]; [ [MvsSln](https://github.com/3F/MvsSln) ]; [ [regXwild](https://github.com/3F/regXwild) ]; [ [hMSBuild](https://github.com/3F/hMSBuild) ]; ...

Also may contain complete examples for some programming languages, frameworks, platforms, ...

It continues idea from: [https://github.com/3F/DllExport/issues/84](https://github.com/3F/DllExport/issues/84)

And complements the old :: **.[sandbox](https://github.com/3F/sandbox).** ::

## Mission

Through complete examples, this repository should provide more related support of various using of some solutions and [public projects](https://github.com/3F), or more.

## Why separate repository?

Additional repository like [https://github.com/3F/Examples](https://github.com/3F/Examples) is less associated to specific license! It just provides more transparent layer in the legal field between each example instead of already used repositories.

Moreover, some specific examples may provide more additional artefacts, unit-tests, and lot of other things that are directly related only to examples and not for their projects.

Feel more free, and/or make your contribution according to your specific rules.

## License

As was stated above, some contributors may provide custom license for each example separately. You should find any related license file inside directory with example. 

However, it will be the [MIT License (MIT)](https://github.com/3F/Examples/blob/master/LICENSE.TXT) by default **if directory with examples** does not provide anything else. 


```
Copyright (c) Authors and contributors of each individual example
```

A cup of coffee [ [☕](https://3F.github.io/Donation/) ] or some donations for github.com/3F: [![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif)](https://3F.github.io/Donation/) 

## Format

### Directory Path

1. Root directory contains folders that are related to specific projects by their names. For example: 

```
[3F/Examples]
    \DllExport
    \Conari
    \MvsSln
```

2. Some special examples are stored inside common root directory (named as `-`). This folder will aggregate examples by their types and related subtype, for example:

```
[3F/Examples]
    \-\lang\CSharp
    \-\lang\CPP
    \-\frameworks\<subtype1>
    \-\platforms\<subtype1>
    \-\<type4>\<subtype1>
    \-\<type4>\<subtype2>
    ...
```

Please note:

* Each root directory should provide **Readme file** to specify at least information about what is it (url of the project home page and so on).
* *`lang` means programming language


### Directory Names

The name shouldn't contain any whitespace characters. Use [Pascal case](https://en.wikipedia.org/wiki/Pascal_case), or underscore `_` characters, or dot `.` characters instead if you're contributing something. For example:

* `Without_Whitespace_Name`
* `WithoutWhitespaceName`
* `Namespace.For.Everyting`

### Directory files

Unspecified format. However, each root example should provide at least **Readme** file.

### Readme file

Inside each directory with example (its root folder) should be presented the **Readme** file. It should describe something about placed example, and some additional related information.

If you're contributing something, please follow this rule to provide at least short description and some accompanying notes for your example. Name it as **Readme.md** file because it will allow to use [markdown syntax](https://help.github.com/articles/basic-writing-and-formatting-syntax/) inside.

### License file

The **License file** is optional for each example. That is, an example is licensed under default [MIT License](#license) if any License file does not exist at all.

But, again, you can optionaly also specify your custom license and copyright for your example if you're contributing this to us.

## How to contribute

1. Place your files of the new example in relevant folder [under structure](#format).
2. Please specifiy **Readme** file to provide at least short description about your example.
    * The **Readme.md** name is recomended because of support the [markdown syntax](https://help.github.com/articles/basic-writing-and-formatting-syntax/) inside. 
3. License file is optional if you want to use our default license.
4. Use [PR (pull requests)](https://help.github.com/articles/about-pull-requests/) to push your example on [https://github.com/3F/Examples](https://github.com/3F/Examples).

## Ask a question or discuss this

This is new repository and the new way at all. So we want to hear more of your opinions, or your suggestions:

* [https://github.com/3F/Examples/issues/new](https://github.com/3F/Examples/issues/new)

## _

We're waiting your amazing examples like for beginners and for professionals.