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
      - [Build and program the firmware](#build-and-program-the-firmware)
      - [Build and run the unit tests](#build-and-run-the-unit-tests)
      - [Build and run gcov coverage](#build-and-run-gcov-coverage)
      - [Other utils](#other-utils)
      - [Flash firmware](#flash-firmware)
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
- [options](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/options) - config files for Ceedling build system
  - [debug.yml](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/options/debug.yml) - build options for debug configuration
  - [release.yml](https://github.com/Zamuhrishka/FWProjectTemplate/blob/develop/options/release.yml) - build options for release configuration
- [scripts](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/scripts) - a collection of useful scripts for the project
  - [githooks](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/scripts/githooks) - git hooks scripts
  - [add_firmware_version.py](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/scripts/add_firmware_version.py) - python script for creating `version.h` file which contain several definitions for version firmware store
  - [format_all_files.py](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/scripts/format_all_files.py) - bat script formatting all files in `src` folder
- [src](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/src) - source code of project
- [test](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test) - folder which contain all necessary for unit testing
  - [fake](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/fake) - are a working implementation, but usually substitute their dependencies with something simpler and easier for a test environment
  - [mock](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/mock) - are an implementation that is controlled by the unit test. They can be pre-programmed with return values, check values of arguments, and help verify that functions are called
  - [src](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/src) - source code of unit tests
  - [stubs](https://github.com/Zamuhrishka/FWProjectTemplate/tree/develop/test/stubs) - are a trivial implementation that returns canned values, generally always returning valid or invalid values
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

#### Build and program the firmware

- Build pic32 release firmware:

```bash
ceedling project:project_pic32 options:release release
```

- Build pic32 debug firmware:

```bash
ceedling project:project_pic32 options:debug release
```

- Build stm32 release firmware:

```bash
ceedling project:project_stm32 options:release release
```

- Build stm32 debug firmware:

```bash
ceedling project:project_stm32 options:debug release
```

- Build x86 release firmware:

```bash
ceedling project:project_x86 options:release release
```

- Build x86 debug firmware:

```bash
ceedling project:project_x86 options:debug release
```

- Build Clean

```bash
ceedling clean
```

#### Build and run the unit tests

```bash
ceedling gcov:all utils:gcov
```

#### Build and run gcov coverage

```bash
ceedling gcov:all utils:gcov
```

#### Other utils

- Run Static Analyser (PVStudio):

```bash
ceedling clean
```

- Run documents generator:

```bash
ceedling doxygen

```

- Run linter:

```bash
ceedling linter
```

#### Flash firmware

- PIC32MX Erase Chip:

```bash
ipecmd.exe -TPPK3 -{device} -E -OL
```

- PIC32MX Write Chip:

```bash
ipecmd.exe -TPPK3 -{device} -F${file} -M -OL
```

- PIC32MX Read Chip:

```bash
ipecmd.exe -TPPK3 -{device} -GF${file}
```

- PIC32MX Reset Chip

```bash
ipecmd.exe -TPPK3 -{device} -OL
```

- STM32 Write Chip:

```bash
st-flash write ${file} ${addr} & st-flash reset
```

- STM32 Erase Chip:

```bash
st-flash erase & st-flash reset
```

- STM32 Read Chip:

```bash
st-flash --area=option read ${file}
```

- STM32 Reset Chip:

```bash
st-flash reset
```

- Openocd Run:

```bash
openocd -f ${file}.cfg
```

- STM32 Write Flash:

```bash
JLink.exe -Device {device} -If SWD -Speed 4000 ${file}.jlink
```

### VSCode Tasks

Inside `.vscode` folder you can find `tasks.json` file which contain description for several helpful tasks which lets you run build, testing, flashing etc. using VSCode instead CLI.

- PIC32 Release Build:

```bash
PIC32 Release Build
```

- PIC32 Debug Build:

```bash
PIC32 Debug Build
```

- x86 Release Build:

```bash
x86 Release Build
```

- x86 Debug Build:

```bash
x86 Debug Build
```

- STM32 Release Build:

```bash
STM32 Release Build
```

- STM32 Debug Build:

```bash
STM32 Debug Build
```

- Build Clean:

```bash
Clean
```

- Run Unit Tests:

```bash
Run Unit Tests
```

- Run PVS-Studio Static Analyzer:

```bash
Run Static Analyzer
```

- Generate Doxygen Documentation:

```bash
Generate Documentation
```

- Run Clang-format Linter:

```bash
Run Linter
```

- Erase/Write/Read/Reset PIC32 chip:

```bash
PIC32MX Erase Flash
PIC32MX Write Flash
PIC32MX Read Flash
PIC32MX Reset
```

- Erase/Write/Read/Reset STM32 chip:

```bash

STM32 Write Flash
STM32 Erase Flash
STM32 Read Flash
STM32 Reset
```

## Third-party software

- [Ceedling Test Framework](https://github.com/ThrowTheSwitch/Ceedling)
- [PVStudio](https://pvs-studio.com/en/pvs-studio/)
- [VSCode](https://code.visualstudio.com/)
- [Clang-tidy](https://clang.llvm.org/extra/clang-tidy/)
- [Clang-format](https://clang.llvm.org/docs/ClangFormat.html)
