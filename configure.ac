# Perfect docs:
# https://autotools.io

AC_INIT([sample_app], [0.1.0], [info@ucoder.ir])
# auto autoconf version
# this works for ubuntu xenial 16.04 or newer
AC_PREREQ([2.69])

# check file exists
AC_CONFIG_SRCDIR([hello.c])

# make config header
AC_CONFIG_HEADERS([config.h])

# auxiliary files go here
AC_CONFIG_AUX_DIR([build-aux])

# change macro directory to ./m4
# also don't forget to put following
# lines in Makefile.am file
#
# ACLOCAL_AMFLAGS = -I m4 --install
# EXTRA_DIST = m4/NOTES
AC_CONFIG_MACRO_DIR([m4])

# init automake
# version works for ubuntu xenial 16.04 or newer
#  -Werror: Report warnings as errors
#  subdirs-objects: create objects in sub-directories
AM_INIT_AUTOMAKE([1.15 -Wall -Werror subdir-objects])

# configure makes Makefile
AC_CONFIG_FILES([Makefile])

# find and probe C compiler
# AC_PROG_CC
# AC_PROG_CC([clang gcc])
AC_PROG_CC([clang])

# find and probe C++ compiler
# AC_PROG_CXX
# AC_PROG_CXX([clang++ g++])
# AC_PROG_CXX

# find flex/lex
# AC_PROG_LEX

# find bison/yacc
# AC_PROG_YACC

## BEGIN Put various checks and such here
## END

# use pkg-config to find libraries
# syntax: PKG_CHECK_MODULES(prefix, list-of-modules, action-if-found, action-if-not-found)
# NOTE: that Makefile.am has to be modified to include:
#    AM_CFLAGS = $({prefix}_CFLAGS)
#    AM_LIBS = $({prefix}_LIBS)
# examples:
# PKG_CHECK_MODULES([FOO], [foo >= 3])
# PKG_CHECK_MODULES([BAR], [bar < 4])
# PKG_CHECK_MODULES([BAZ], [baz = 2])
#####
# Optional modules:
# AC_ARG_WITH([gtk], AS_HELP_STRING([--with-gtk], [Build with the GTK+ interface]))
# 
# AS_IF([test "x$with_gtk" = "xyes"], [
#    PKG_CHECK_MODULES([GTK], [gtk+-2.0])
# ])
# 
# PKG_CHECK_MODULES([GLIB], [glib-2.0])
#####
# Alternative modules:
# PKG_CHECK_MODULES([UDEV], [libudev],
#    [AC_DEFINE([HAVE_UDEV], [1], [Use UDEV])],
#    [PKG_CHECK_MODULES([HAL], [hal],
#        [AC_DEFINE([HAVE_HAL], [1], [Use HAL])
#     ])
# ])
#####

# create configure file
AC_OUTPUT

