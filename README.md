# Vcov

[![cmake-build](https://github.com/wissem01chiha/vccov/actions/workflows/cmake.yaml/badge.svg?branch=master)](https://github.com/wissem01chiha/vccov/actions/workflows/cmake.yaml)
[![Build status](https://ci.appveyor.com/api/projects/status/yv33leemcnm7v5sq?svg=true)](https://ci.appveyor.com/project/wissem01chiha/vcov)
![GitHub License](https://img.shields.io/github/license/wissem01chiha/vccov)
[![CodeFactor](https://www.codefactor.io/repository/github/wissem01chiha/vcov/badge)](https://www.codefactor.io/repository/github/wissem01chiha/vcov)
[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/wissem01chiha/vcov/master.svg)](https://results.pre-commit.ci/latest/github/wissem01chiha/vcov/master)

## Overview
 
Vcov is a free and open‑source C/C++ code coverage tool for [Visual Studio](https://learn.microsoft.com/en-us/visualstudio/ide/solutions-and-projects-in-visual-studio?view=visualstudio) solutions on Windows. It is actively maintained as a fork of the [OpenCppCoverage](https://github.com/OpenCppCoverage/OpenCppCoverage) project.
Since the original project is no longer actively maintained, Vcov continues its development and improvement.

Its primary use case is unit test coverage, but it can also be used to track executed lines in a program for debugging purposes.

This tool is constantly evolving, and contributions are always welcome! Learn how to get started with our [packaging tutorial]() and [maintainer guide](./CONTRIBUTING.md).

## Get Started

First, follow one of our quick start guides.

- Windows Vista or higher
- Microsoft Visual Studio 2008 or higher (all editions, **including Express edition**) , It may also work with earlier versions of Visual Studio.

## Use Vcov

You can run Vcov with the following command:

```bash
vcov.exe --sources MySourcePath* -- YourProgram.exe arg1 arg2
```

For example, *MySourcePath* can be *MyProject*, if your sources are located in *C:\Dev\MyProject*.

See [Getting Started](https://github.com/OpenCppCoverage/OpenCppCoverage/wiki) for more information about the usage.
You can also have a look at [Command-line reference](https://github.com/OpenCppCoverage/OpenCppCoverage/wiki/Command-line-reference).

## Key features

- [Visual studio support](https://visualstudio.microsoft.com/)  Support compiler with [program database file](https://learn.microsoft.com/en-us/visualstudio/debugger/debug-interface-access/querying-the-dot-pdb-file?view=visualstudio)
- [Non intrusive]()  Just run your program with vccov, no need to recompile your application.
- [HTML reporting]()
- [Line coverage]().
- [Visual Studio Plugin](https://github.com/OpenCppCoverage/OpenCppCoveragePlugin)
- [Jenkins support](https://github.com/OpenCppCoverage/OpenCppCoverage/wiki/Jenkins)  
- [Support optimized build]().
- [Exclude a line based on a regular expression]().
- [Child processes coverage]().
- [Coverage aggregation](): Run several code coverages and merge them into a single report.

## Contribute

vcov is an open source project, and is thus built with your contributions. Here are some ways you can contribute:

* [Submit issues](https://github.com/wissem01chiha/vcov/issues)
* [Submit fixes](https://github.com/wissem01chiha/vcov/pulls)
  
Please refer to our [maintainer guide](.github/CONTRIBUTING.md) for more details.

## Resources

* Docs: [Wiki](https://github.com/wissem01chiha/vcov/wiki)
* Source code: [vcov](../../releases)
* Email: [Contact](mailto:chihawissem08@gmail.com)

## License

The code in this repository is licensed under the GPL-3.0 License.
