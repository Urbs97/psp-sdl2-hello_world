# PSP-HelloWorld

## How to Build
Install [PSPSDK](https://github.com/pspdev/pspdev).  
Use make to build:
- make
- make rebuild
- make clean

## How to Debug on Real Hardware
Build using `make debug`.  
Then use [PSPLink](http://pspdev.github.io/psplinkusb/) to send your homebrew to your psp while it's being monitored on your computer.  
You will be able to see exceptions and thanks to the debug build you will also be able to find the source file + line of where the exception occurred using `psp-addr2line`.  
You might also need to compile SDL2 from source as debug incase the libSDL2d is missing.

## SDL2
https://wiki.libsdl.org/SDL2/README/psp  
https://github.com/libsdl-org/SDL/tree/SDL2

## PSPSDK Documentation
https://pspdev.github.io/pspsdk/

## How to get Includes in VSCode
Set the following lines in the include path:
```
${workspaceFolder}/**
${PSPDEV}/include
${PSPDEV}/psp/include
${PSPDEV}/psp/sdk/include
```
