# RM2020 Internal Competition Code Base

> There will be drivers update to this repo later.
> 
> Please clone this instead of downloading a zip.

* Board: STM32F103C8 (BluePill)
* OS: ChibiOS
* Debugger: JLink
* Compiler toolchain: Arm GNU toolchain (2017 Q2)

## Directory Structure
* `board`: Board hardware configuration
* `build`: Build output (the output elf is `RM20.elf`)
* `chibios`: ChibiOS library (RTOS)
* `CMSIS`: CMSIS library 
* `config`: ChibiOS config
* `datasheets`: Datasheets useful for development
* `openocd`: OpenOCD scripts
* `src`: User source code

## Compile
```
make
```

* `make -j` could make compilation process faster by utilizing multiple core on your computer.


## General Environment Setup
* Install [GNU Arm toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) **2017 Q2**
* Install GNU Make
* Install [Segger Ozone](https://www.segger.com/downloads/jlink/#Ozone)

### Windows Specific

* Install [MSYS2](https://www.msys2.org/) and add the `C:\msys64\usr\bin` to your path. (assuming you install it in `C:\msys64`)

### Unix System (Linux and Mac)

1. Download Linux/Mac 64-bit GNU Arm toolchain 2017 Q2
2. Unpack it (`tar -xjf`) into current directory (make sure it is in an empty directory)
3. Add the path in your `~/.bashrc` or `~/.zshrc`:

   ```bash
   export PATH=$PATH:(path to bin directory of the file)
   ```

   Example:

   ```bash
   export PATH=$PATH:$HOME/arm-gcc-2017-q2/bin
   ```

