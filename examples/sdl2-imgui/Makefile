.PHONY: clean debug run new_all

TARGET = Tutorial
OBJS := $(patsubst src/%.cpp,src/%.o,$(wildcard src/*.cpp))

CFLAGS =
CXXFLAGS = $(CFLAGS) -std=c++17 -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
INCDIR += ./libs

BASE_LIBS = $(IMGUI_LIB) -lpthread -lstdc++ -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lGL -lpspvram -lpspaudio -lpspvfpu -lpsphprm -lpspgu -lpng -ljpeg -lz -lpspdebug -lpspdisplay -lpspge -lpspctrl -lpspnet -lpspnet_apctl

# Default SDL library
SDL_LIB = -lSDL2

IMGUI_DIR := ./libs/imgui
IMGUI_SRC := $(wildcard $(IMGUI_DIR)/*.cpp)
IMGUI_OBJS := $(IMGUI_SRC:.cpp=.o)
IMGUI_LIB := $(IMGUI_DIR)/libimgui.a
IMGUI_CXXFLAGS := -Wall -std=c++17 # IMGUI-specific flags

LIBS = $(SDL_LIB) $(BASE_LIBS)


# PSP Stuff
PSP_FW_VERSION = 500
BUILD_PRX = 1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Tutorial

new_all: $(IMGUI_LIB) all

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak


$(IMGUI_DIR)/%.o: $(IMGUI_DIR)/%.cpp
	psp-g++ $(IMGUI_CXXFLAGS) -c $< -o $@

$(IMGUI_LIB): $(IMGUI_OBJS)
	ar rcs $@ $(IMGUI_OBJS)

run: debug
	flatpak run org.ppsspp.PPSSPP $(CURDIR)/EBOOT.PBP

# Debug target
debug: CFLAGS += -g3 -DDEBUG -O0
debug: SDL_LIB := -lSDL2d
debug: LIBS := $(SDL_LIB) $(BASE_LIBS)
debug: all

clean:
	rm -f *.elf *.SFO *.PBP *.prx $(OBJS) $(IMGUI_LIB) $(IMGUI_OBJS)
