# UEFI Fundamental Projects

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

#Complete Step by Step 

How to Clone, Build, and Run the UEFI Projects

1️⃣ Clone the GitHub Repository
Open Git Bash / Terminal and run:
Shellgit clone https://github.com/<your-username>/uefi-beginner-projects.git``Show more lines
Go into the folder:
Shellcd uefi-beginner-projectsShow more lines
✅ This repo contains only your UEFI apps and drivers.

2️⃣ Clone EDK2 (Required)
Go one level above your repo (recommended):
Shellcd ..git clone https://github.com/tianocore/edk2.gitShow more lines
Now copy your projects into EDK2:
Shellcopy /Y /E uefi-beginner-projects\MyPkg edk2\MyPkgShow more lines
(Linux: cp -r uefi-beginner-projects/MyPkg edk2/)
✅ Important:
You do NOT commit full EDK2 to GitHub.

3️⃣ Setup EDK2 Build Environment
A. Go to edk2 directory
Shellcd edk2``Show more lines
B. Initialize submodules
Shellgit submodule update --initShow more lines
C. Setup build environment
Windows
Shelledksetup.batShow more lines
Linux
Shellsource edksetup.shShow more lines

4️⃣ Set Target Architecture (Recommended)
Edit:
Conf/target.txt

Set:
ShellACTIVE_PLATFORM = MdeModulePkg/MdeModulePkg.dscTARGET_ARCH     = X64TOOL_CHAIN_TAG  = VS2022   # or GCC5``Show more lines

5️⃣ Build the Projects
Run:
ShellbuildShow more lines
✅ If build succeeds, EFI binaries will be generated.

6️⃣ Locate the Generated EFI Files
After build, binaries are found in:
Build/MyPkg/DEBUG_*/X64/

Example:
HelloUEFI.efi
SystemInfo.efi
TimerApp.efi
KeyInput.efi
FileRead.efi
PciEnum.efi

DXE Driver:
SimpleDxe.efi


7️⃣ Run UEFI Applications (UEFI Shell)
A. Prepare USB (FAT32)
Create this structure:
EFI/
 └── BOOT/
     ├── HelloUEFI.efi
     ├── SystemInfo.efi
     ├── TimerApp.efi
     ├── KeyInput.efi
     ├── FileRead.efi
     └── PciEnum.efi

B. Boot into UEFI Shell
At shell prompt:
Plain Textfs0:HelloUEFI.efi``Show more lines
Repeat for other apps.

8️⃣ Special Notes Per Project
✅ Hello UEFI
Plain TextHello UEFI World!Show more lines
✅ System Info
Prints:

Firmware Vendor
UEFI Version

✅ Timer App
Plain TextWaiting for 3 seconds...Timer expired!``Show more lines
✅ Key Input
Waits for key press and prints scan code.
✅ File Read App

Put test.txt in same USB folder
App prints file contents

9️⃣ Run PCI Enumeration App
From UEFI Shell:
Plain TextPciEnum.efi``Show more lines
✅ Sample output:
Bus 00 Dev 1f Func 00 | Vendor ID: 8086 Device ID: A2AF


🔟 DXE Driver – How It Runs
✅ DXE drivers do NOT run from shell

Loaded automatically during DXE phase
Output visible in:

Serial console
Debug log
Emulator console (QEMU)

✅ You don’t manually execute SimpleDxe.efi.

✅ Common Errors & Fixes

IssueFixBuild failsRun edksetup againNo EFI fileCheck MyPkg is inside edk2/FileRead failsEnsure FAT32 & test.txt existsDXE not visibleCheck debug output

✅ Final Checklist
✔ GitHub repository cloned
✔ EDK2 setup done
✔ Build successful
✔ UEFI Apps running
✔ DXE Driver loaded
✔ PCI devices enumerated

🔥 Next Level Options
If you want, I can help you with:

DXE driver protocol install
PCI BAR enumeration
UEFI Shell commands
Secure Boot demo
Firmware interview prep
