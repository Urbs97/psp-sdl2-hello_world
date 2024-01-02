TARGET = Tutorial
OBJS := $(patsubst src/%.cpp,src/%.o,$(wildcard src/*.cpp))
 
CFLAGS = 
CXXFLAGS = $(CFLAGS) -std=c++17 -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS= -lstdc++ -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lg -lGL -lpspvram -lpspaudio -lpspvfpu -lpsphprm -lpspgu -lpng -lpng16 -ljpeg -lturbojpeg -lz

 
# PSP Stuff
BUILD_PRX = 1
PSP_FW_VERSION = 500
 
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Tutorial
#PSP_EBOOT_ICON = ICON0.PNG 
 
PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

run: all
	flatpak run org.ppsspp.PPSSPP $(CURDIR)/EBOOT.PBP