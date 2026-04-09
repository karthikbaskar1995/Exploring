# UEFI Beginner Projects

This repository contains 5 simple UEFI applications built using EDK2.
Each project demonstrates a core UEFI concept.

## Projects Included
1. Hello UEFI App
2. System Information App
3. Timer App
4. Key Input App
5. File Read App

## Prerequisites
- EDK2 source code
- Build tools (Visual Studio / GCC)
- UEFI Shell or QEMU
- FAT32 USB drive (for testing)

## Build Steps
1. Clone edk2:
   git clone https://github.com/tianocore/edk2.git

2. Copy `MyPkg` into edk2 folder

3. Setup build environment

4. Build:
   build

## Output
Generated `.efi` files will be located in:
Build/MyPkg/DEBUG_*/X64/

## Purpose
Learn UEFI application development step by step.
