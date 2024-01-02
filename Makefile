TARGET = Tutorial
OBJS := $(patsubst src/%.cpp,src/%.o,$(wildcard src/*.cpp))
 
CFLAGS = 
CXXFLAGS = $(CFLAGS) -std=c++17 -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS= -lstdc++ -lpspgum -lpspgu -lm
 
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