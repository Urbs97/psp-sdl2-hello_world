TARGET = Tutorial
OBJS := $(patsubst src/%.cpp,src/%.o,$(wildcard src/*.cpp))

CFLAGS =
CXXFLAGS = $(CFLAGS) -std=c++17 -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =

BASE_LIBS = -lstdc++ -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lGL -lpspvram -lpspaudio -lpspvfpu -lpsphprm -lpspgu -lpng -ljpeg -lz -lpspdebug -lpspdisplay -lpspge -lpspctrl -lpspnet -lpspnet_apctl

# Default SDL library
SDL_LIB = -lSDL2

LIBS = $(SDL_LIB) $(BASE_LIBS)

# PSP Stuff
PSP_FW_VERSION = 500
BUILD_PRX = 1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Tutorial

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

run: debug
	flatpak run org.ppsspp.PPSSPP $(CURDIR)/EBOOT.PBP

# Debug target
debug: CFLAGS += -g3 -DDEBUG -O0
debug: SDL_LIB := -lSDL2d
debug: LIBS := $(SDL_LIB) $(BASE_LIBS)
debug: all
