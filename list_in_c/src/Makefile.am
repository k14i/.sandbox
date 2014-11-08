SUBDIRS = lib

bin_PROGRAMS = list_in_c

list_in_c_LDFLAGS = -L./lib
list_in_c_LDADD = -llist

list_in_c_CFLAGS = -I ./lib

list_in_c_DEPENDENCIES = ./lib/liblist.la

list_in_c_SOURCES = example.c
#list_in_c_LDADD = ./lib/liblist.la

AM_CFLAGS = -Wall
