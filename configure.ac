# Perfect docs:
# https://autotools.io

# List of macros
# https://www.gnu.org/software/autoconf-archive/The-Macros.html

# You can output error messages by:
# AC_MSG_ERROR([[this is an error message]])

AC_INIT([sample_app], [0.1.0], [info@ucoder.ir])
# auto autoconf version
# this works for ubuntu xenial 16.04 or newer
AC_PREREQ([2.69])

# check file exists
AC_CONFIG_SRCDIR([src/hello.c])

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
#  subdirs-objects: create objects in sub-directories instead of project root
AM_INIT_AUTOMAKE([1.15 -Wall -Werror subdir-objects])

# required for defining options like -DDEBUG=1
# AM_PROG_CC_C_O

# <<< required for creating *.la libraries >>>
# <<< COMMENT THIS LINE IF NO *.la IS NEEDED >>>
AM_PROG_AR
# <<< >>>

# find and probe C compiler
# AC_PROG_CC
# AC_PROG_CC([clang gcc])
AC_PROG_CC([clang])

# find and probe C++ compiler
# AC_PROG_CXX
# AC_PROG_CXX([clang++ g++])
# AC_PROG_CXX

# optionally check for c++11
#   ext: use extended mode (e.g. -std=gnu++11)
#   noext: use non-extended mode (e.g. -std=c++11)
# AX_CXX_COMPILE_STDCXX_11([ext|noext], [mandatory|optional])
# AX_CXX_COMPILE_STDCXX_14([ext|noext], [mandatory|optional])

# check for support of language
# AC_LANG([C++], [C])
AC_LANG([C])

# run and check compilation of additional source files
# AC_LANG_SOURCE([[int main() { return 0; }]])

# find flex/lex
# AC_PROG_LEX

# find bison/yacc
# AC_PROG_YACC

# find awk
# AC_PROG_AWK

### cpplint ###
# check availability of python
AC_PATH_PROG([PYTHON],[python])
# export variable PYTHON
AC_SUBST([PYTHON])
# check python version (works for ubuntu xenial 16.04)
AX_PROG_PYTHON_VERSION([2.7.0])

# required for finding installation directory, $(INSTALL)
AC_PROG_INSTALL

## handling libraries
# 1. initialize libtool
#   LT_INIT
# 2. AM_PROG_AR to find archiver (add under AM_INIT)
# 3. define library in Makefile.am
LT_INIT

## BEGIN Put various checks and such here
## END

# Check for pthreads library.
# ACX_PTHREAD([have_pthread=yes], [heve_pthread=no])

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

### OUTPUTS ###

# make variable available in output
# AC_SUBST([GTEST_LIBS])

# generate config.h file
AC_CONFIG_HEADERS([config.h])
# generate Makefile
AC_CONFIG_FILES([Makefile])
# create pkg-config file
AC_CONFIG_FILES([whine.pc])

# generate all files
AC_OUTPUT

