CC=/usr/local/bin/gcc-4.9
CFLAGS=-Wall
LDFLAGS=-lm

AUTOMAKE_OPTIONS = foreign
AC_CONFIG_AUX_DIR = ./config/aux
#AC_CANONICAL_TARGET
SUBDIRS = src
EXTRA_DIST = autogen.sh
INCLUDE = -I./src/lib #-I./src/include
TARGET = ./bin/$(shell basename `readlink -f .`)
OBJDIR = ./tmp/.obj

#all: clean $(TARGET)
#clean: distclean
#       find . -name Makefile.in -exec \rm -f {} \;
#       find . -name Makefile -exec \rm -f {} \;

#OBJECTS=./src/lib/list.o
#SOURCE=example.c
#target: $(OBJECTS)
#	    $(CC) $(CFLAGS) $(OBJECTS) -o target $(LDFLAGS)

