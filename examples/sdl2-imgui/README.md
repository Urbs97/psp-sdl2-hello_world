# Dear ImGui Example for PSP using SDL2


## Resources

## How to Build

To get started, you need to have the PSPSDK installed. Follow the instructions at [PSPSDK on GitHub](https://github.com/pspdev/pspdev) to install it.

Building the project is straightforward. Use the following `make` commands:
- `make` to build the project.
- `make rebuild` to rebuild the project.
- `make clean` to clean up the build files.

## How to Debug on Real Hardware

For debugging on a real PSP device, follow these steps:

1. Build the project with `make debug` to create a debug build.
2. Utilize [PSPLink](http://pspdev.github.io/psplinkusb/) to transmit your homebrew application to your PSP. PSPLink allows for real-time monitoring from your computer.
3. With the debug build, you can effectively track exceptions. The tool `psp-addr2line` will assist you in locating the exact source file and line number where an exception occurred.
4. Note: In some cases, it may be necessary to compile SDL2 from the source as a debug build, particularly if `libSDL2d` (the debug library) is missing.

This setup will provide an environment for both developing and debugging your SDL2 applications on the PSP.
