# PSP-HelloWorld

## How to build
Install [PSPSDK](https://github.com/pspdev/pspdev).  
Use make to build:
- make
- make rebuild
- make clean
- make run (PPSSPP flatpak needs to be installed)

## How to get includes in VSCode
Set the following lines in the include path:
```
${workspaceFolder}/**
${PSPDEV}/include
${PSPDEV}/psp/include
${PSPDEV}/psp/sdk/include
```
