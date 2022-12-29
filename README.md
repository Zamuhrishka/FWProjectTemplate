# Firmware Project Template

This set of utils, folders, config files which can be used as template for each new firmware project.
This template based on [Ceedling Build System](https://github.com/ThrowTheSwitch/Ceedling). This build system used for build as firmware and tests.

## Table of Contents

- [Firmware Project Template](#firmware-project-template)
  - [Table of Contents](#table-of-contents)
  - [Getting Started](#getting-started)
  - [Project Structure](#project-structure)
  - [Usage](#usage)
    - [CLI](#cli)
    - [VSCode Tasks](#vscode-tasks)
  - [Third-party software](#third-party-software)

## Getting Started

If you decide use this template in your firmware project then you need do next steps:

- Copy this project to your local machine;
- [Install](https://github.com/ThrowTheSwitch/Ceedling) Ceedling on your machine;
- Add your firmware source code into `src\` folder;
- Add your unit tests into `test\src` folder;

## Project Structure

- [.vscode](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/.vscode) - VSCode config files
- __build__ - frimware builds
- [docs](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/docs) - projects documentations
- [linker](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/linker) - linker scripts
- [options](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/options) - config files for ceedling build system
  - [debug.yml](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/options/debug.yml) - build options for debug configuration
  - [release.yml](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/options/release.yml) - build options for release configuration
- [src](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/src) - source code of project
- [test](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test) - folder which contain all necessary for unit testing
  - [fake](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/fake) - using a system that behaves very similar to the real one, but avoids costly or destructive actions
  - [mock](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/mock) - using a system with the same interface as the real one, but which in addition registers interactions for subsequent monitoring and verification statements
  - [src](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/src) - source code of unit tests
  - [stubs](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/stubs) - using a predefined value as a response instead of receiving a response from a live system
  - [support](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/support) - various functions, macros to extend the functionality of the basic framework
- [tools](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/tools) - several useful binary utils
  - [clang-format](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/tools/clang-format) - tool to automatically format C/C++/Objective-C code
  - [clang-tidy](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/tools/clang-tidy) - clang-based C++ “linter” tool
  - [pvs-studio](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/tools/pvs-studio) - static analyser for C/C++
- [vendor](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/vendor) -  binaries utils of ceedling framework
- [.clang-format](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/.clang-format) - config file for clang-format util
- [.gitignore](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/..gitignore) - config file for git ignoring
- [ceedling.cmd](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/ceedling.cmd) - command script for Ceedling build system
- [Doxygen.conf](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/Doxygen.conf) - config file for doxygen document generator
- [project.yml](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/project.yml) - config file for Ceedling build system (Common)
- [project_pic32.yml](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/project_pic32.yml) - config file for Ceedling build system (PIC32)
- [project_stm32.yml](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/project_stm32.yml) - config file for Ceedling build system (STM32)
- [project_x86.yml](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/project_x86.yml) - config file for Ceedling build system (x86)
- [pvs-studio.bat](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/pvs-studio.bat) - script for running PVStudio static analyzer
- [PVS-Studio.cfg](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/PVS-Studio.cfg) - config file for PVStudio static analyzer
- [rakefile.rb](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/rakefile.rb) - config and tasks file for Ceedling build system

## Usage

### CLI

**Build and program the firmware**

```bash
#Build pic32 release firmware
ceedling project:project_pic32 options:release release

#Build pic32 debug firmware
ceedling project:project_pic32 options:debug release

#Build stm32 release firmware
ceedling project:project_stm32 options:release release

#Build stm32 debug firmware
ceedling project:project_stm32 options:debug release

#Build x86 release firmware
ceedling project:project_x86 options:release release

#Build x86 debug firmware
ceedling project:project_x86 options:debug release

#Build Clean
ceedling clean
```

**Build and run the unit tests**

```bash
#Build and run all unit tests
ceedling test:all
```

**Build and run gcov coverage**

```bash
#Build and run gcov coverage
ceedling gcov:all utils:gcov
```

**Other utils**

```bash
#Run Static Analyser (PVStudio)
ceedling pvstudio

#Run documents generator
ceedling doxygen

#Run linter
ceedling linter
```

**Flash firmware**

```bash
#PIC32MX Erase Flash
ipecmd.exe -TPPK3 -{device} -E -OL

#PIC32MX Write Flash
ipecmd.exe -TPPK3 -{device} -F${file} -M -OL

#PIC32MX Read Flash
ipecmd.exe -TPPK3 -{device} -GF${file}

#PIC32MX Reset
ipecmd.exe -TPPK3 -{device} -OL

#STM32 Write Flash
st-flash write ${file} ${addr} & st-flash reset

#STM32 Erase Flash
st-flash erase & st-flash reset

#STM32 Read Flash
st-flash --area=option read ${file}

#STM32 Reset
st-flash reset

#Openocd Run
openocd -f ${file}.cfg

#STM32 Write Flash
JLink.exe -Device {device} -If SWD -Speed 4000 ${file}.jlink
```
### VSCode Tasks

```bash
PIC32 Release Build
PIC32 Debug Build
x86 Release Build
x86 Debug Build
STM32 Release Build
STM32 Debug Build
Clean
Run Unit Tests
Add PVS-Studio Special Comment
Run Static Analyzer
Generate Documentation
Run Linter
PIC32MX Erase Flash
STM32 Debug Build
PIC32MX Write Flash
PIC32MX Read Flash
PIC32MX Reset
STM32 Write Flash
STM32 Erase Flash
STM32 Read Flash
STM32 Reset
Openocd Run
```
## Third-party software

  - [Ceedling Test Framework](https://github.com/ThrowTheSwitch/Ceedling)
  - [PVStudio](https://pvs-studio.com/ru/pvs-studio/)
  - [VSCode](https://code.visualstudio.com/)
  - [Clang-tidy](https://clang.llvm.org/extra/clang-tidy/)
  - [Clang-format](https://clang.llvm.org/docs/ClangFormat.html)
