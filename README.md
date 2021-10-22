# Firmware Project Template

This set of utils, folders, config files which can be used as template for each new firmware project.
This template based on [Ceedling Test Framework](https://github.com/ThrowTheSwitch/Ceedling). This build system used for build as firmware and tests.

## Table of Contents

* [Getting Started](#getting-started)
* [Usage](#usage)
  * [CLI](#cli)
  * [VSCode Tasks](#vscode-tasks)
* [Project Structure](#project-structure)
* [Third-party software](#third-party-software)

## Getting Started

If you decide use this template in your firmware project then you need do next steps:

- Copy this project to your local machine;
- [Install](https://github.com/ThrowTheSwitch/Ceedling) Ceedling on your machine;
- Add your firmware source code into `src\` folder;
- Add your unit tests into `test\src` folder;

## Project Structure

* __.vscode__ - Folder with VSCode config files
* __build__ - Folder with builds frimware
* __docs__ - Folder with project documentation
* __linker__ - Folder with linker scripts
* __options__ - Folder store config files for ceedling build system
* __src__ - Folder with source code of project
* __test__ - Folder which contain all necessary for unit testing
    * __fake__ - using a system that behaves very similar to the real one, but avoids costly or destructive actions
    * __mock__ - using a system with the same interface as the real one, but which in addition registers interactions for subsequent monitoring and verification statements
    * __src__ - source code of unit tests
    * __stubs__ - using a predefined value as a response instead of receiving a response from a live system
    * __support__ - various functions, macros to extend the functionality of the basic framework
* __tools__ - Folder with several useful binary utils
    * __clang-format__ - Tool to automatically format C/C++/Objective-C code
    * __clang-tidy__ - Clang-based C++ “linter” tool
    * __pvs-studio__ - Static analyser for C/C++
* __vendor__ - Folder store binaries utils of ceedling framework
* _.clang-format_ - Config file for clang-format util
* _.gitignore_ - Config file for git ignoring
* _ceedling.cmd_ - Command script for Ceedling build system
* _Doxygen.conf_ - Config file for doxygen document generator
* _project.yml_ - Config file for Ceedling build system (Common)
* _project_pic32.yml_ - Config file for Ceedling build system (PIC32)
* _project_stm32.yml_ - Config file for Ceedling build system (STM32)
* _project_x86.yml_ - Config file for Ceedling build system (x86)
* _pvs-studio.bat_ - Script for running PVStudio static analyzer
* _PVS-Studio.cfg_ - Config file for PVStudio static analyzer
* _rakefile.rb_ - Config and tasks file for Ceedling build system

## Usage

### CLI

**Build and program the firmware**

| Command      | Description |
| :---  | :---  |
| `ceedling project:project_pic32 options:release release`     | Build pic32 release firmware       |
| `ceedling project:project_pic32 options:debug release`   | Build pic32 debug firmware        |
| `ceedling project:project_stm32 options:release release`   | Build stm32 release firmware        |
| `ceedling project:project_stm32 options:debug release`   | Build stm32 debug firmware        |
| `ceedling project:project_x86 options:release release`   | Build x86 release firmware        |
| `ceedling project:project_x86 options:debug release`   | Build x86 debug firmware        |
| `ceedling clean`   | Build Clean        |

**Build and run the unit tests**

| Command      | Description |
| :---  | :---  |
| `ceedling test:all`     | Build and run all unit tests       |

**Other utils**

| Command      | Description |
| :---  | :---  |
| `ceedling pvstudio`     | Run Static Analyser (PVStudio)       |
| `ceedling doxygen`   | Run documents generator        |
| `ceedling linter`   | Run linter        |

**Flash firmware**

| Command      | Description |
| :---  | :---  |
| `ipecmd.exe -TPPK3 -{device} -E -OL`     | PIC32MX Erase Flash      |
| `ipecmd.exe -TPPK3 -{device} -F${file} -M -OL`   | PIC32MX Write Flash        |
| `ipecmd.exe -TPPK3 -{device} -GF${file}`   | PIC32MX Read Flash        |
| `ipecmd.exe -TPPK3 -{device} -OL`   | PIC32MX Reset        |
| `st-flash write ${file} ${addr} & st-flash reset`   | STM32 Write Flash         |
| `st-flash erase & st-flash reset`   | STM32 Erase Flash         |
| `st-flash --area=option read ${file}`   | STM32 Read Flash         |
| `st-flash reset`   | STM32 Reset         |
| `openocd -f ${file}.cfg`   | Openocd Run         |
| `JLink.exe -Device {device} -If SWD -Speed 4000 ${file}.jlink`   | STM32 Write Flash         |

### VSCode Tasks

| Task      | Description |
| :---  | :---  |
| `PIC32 Release Build`     |       |
| `PIC32 Debug Build`   |         |
| `x86 Release Build`   |         |
| `x86 Debug Build`   |         |
| `STM32 Release Build`   |         |
| `STM32 Debug Build`   |         |
| `Clean`   |         |
| `Run Unit Tests`   |         |
| `Add PVS-Studio Special Comment`   |         |
| `Run Static Analyzer`   |         |
| `Generate Documentation`   |         |
| `Run Linter`   |         |
| `PIC32MX Erase Flash`   |         |
| `STM32 Debug Build`   |         |
| `PIC32MX Write Flash`   |         |
| `PIC32MX Read Flash`   |         |
| `PIC32MX Reset`   |         |
| `STM32 Write Flash`   |         |
| `STM32 Erase Flash`   |         |
| `STM32 Read Flash`   |         |
| `STM32 Reset`   |         |
| `Openocd Run`   |         |

## Third-party software

  - [Ceedling Test Framework](https://github.com/ThrowTheSwitch/Ceedling)
  - Clang-tidy
  - Clang-format
  - PVStudio
  - VSCode

