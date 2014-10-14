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