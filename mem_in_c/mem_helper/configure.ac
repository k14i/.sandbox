#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([mem_helper], [0.0.0], [keithseahus-at-gmail.com])
#AC_CONFIG_SRCDIR([src/mem_helper.c])
AC_CONFIG_SRCDIR([src/example.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE
LT_INIT
#AM_CONFIG_HEADER()
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
#AC_PROG_LIBTOOL
#AC_PROG_CXX
#AC_PROG_AWK
AC_PROG_CC
#AC_PROG_CPP
#AC_PROG_INSTALL
#AC_PROG_LN_S
#AC_PROG_MAKE_SET
#AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/lib/Makefile])
AC_OUTPUT
