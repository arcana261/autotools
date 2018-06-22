# Perfect docs:
# https://autotools.io

# List of macros
# https://www.gnu.org/software/autoconf-archive/The-Macros.html

# You can output error messages by:
# AC_MSG_ERROR([[this is an error message]])

# you can manually include a m4 file
# m4_include([m4/libuv-check-flags.m4])

# conditional programming:
# AS_IF([AS_CASE([$host_os],[openedition*],  [false], [true])], [
#   CC_CHECK_CFLAGS_APPEND([-pedantic])
# ])
#
# AM_CONDITIONAL([AIX], [AS_CASE([$host_os],[aix*], [true], [false])])
#
# AS_IF([test x$HAVE_PYTHON = x1 -a "x$PYTHON" != "x" -a "x$PIP" != "x" -a "x$PIPENV" != "x"], .........

# variables at disposal:
# CFLAGS
# CPPFLAGS <- c preprocessor flags
# LDFLAGS
# LIBS

# auto autoconf version
# this works for ubuntu xenial 16.04 or newer
AC_PREREQ([2.69])

AC_INIT([sample_app], [0.1.0], [https://github.com/arcana261/autotools/issues])

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
#  foreign: relax some checks that otherwise are fixed by hacks
#			a good example is files NEWS, COPYING, AUTHORS, ChangeLog, README
#  gnu: (default) standard flavor of automake
#  dist-gzip, dist-bzip2, dist-xz, dist-zip, ... : specify format of distribution zip file
AM_INIT_AUTOMAKE([1.14 -Wall -Werror foreign subdir-objects])

# required for defining options like -DDEBUG=1
# AM_PROG_CC_C_O

# <<< required for creating *.la libraries >>>
# <<< COMMENT THIS LINE IF NO *.la IS NEEDED >>>
AM_PROG_AR
# <<< >>>

# find and probe C compiler
# AC_PROG_CC
# AC_PROG_CC([clang gcc])
AC_PROG_CC

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

# check support for required compiler flags for sanity checkings
AX_CHECK_COMPILE_FLAG([-fsanitize=leak], [SANITY_LEAK=true], [SANITY_LEAK=false])
AX_CHECK_COMPILE_FLAG([-fsanitize=address], [SANITY_ADDRESS=true], [SANITY_LEAK=false])
AX_CHECK_COMPILE_FLAG([-fsanitize=undefined], [SANITY_UNDEFINED=true], [SANITY_UNDEFINED=false])
AX_CHECK_COMPILE_FLAG([-fsanitize=thread], [SANITY_THREAD=true], [SANITY_THREAD=false])
AX_CHECK_COMPILE_FLAG([-fsanitize=memory], [SANITY_MEMORY=true], [SANITY_MEMORY=false])
AM_CONDITIONAL([HAVE_LEAK_SANITIZER], [test x$SANITY_LEAK = xtrue])
AM_CONDITIONAL([HAVE_ADDRESS_SANITIZER], [test x$SANITY_ADDRESS = xtrue])
AM_CONDITIONAL([HAVE_UNDEFINED_SANITIZER], [test x$SANITY_UNDEFINED = xtrue])
AM_CONDITIONAL([HAVE_THREAD_SANITIZER], [test x$SANITY_THREAD = xtrue])
AM_CONDITIONAL([HAVE_MEMORY_SANITIZER], [test x$SANITY_MEMORY = xtrue])

# Checks for existence of coverage tools and define variables for reporting coverage
AX_COVERAGE

# run and check compilation of additional source files
# AC_LANG_SOURCE([[int main() { return 0; }]])

# find flex/lex
# AC_PROG_LEX

# find bison/yacc
# AC_PROG_YACC

# find awk
# AC_PROG_AWK

### cpplint ###
# check availability of cpplint
AC_PATH_PROG([CPPLINT],[cpplint])
# export variable CPPLINT
AC_SUBST([CPPLINT])
# define conditional
AM_CONDITIONAL([HAVE_CPPLINT], [test x$CPPLINT != x])

# required for finding installation directory, $(INSTALL)
AC_PROG_INSTALL

## handling libraries
# 1. initialize libtool
#   LT_INIT
# 2. AM_PROG_AR to find archiver (add under AM_INIT)
# 3. define library in Makefile.am
LT_INIT

## BEGIN Put various checks and such here

# check for existence of certain header files
# AC_CHECK_HEADERS([sys/ahafs_evProds.h])

# check for compilability
# AC_COMPILE_IFELSE(input, [action-if-true], [action-if-false])

## END

# Check for pthreads library.
# ACX_PTHREAD([have_pthread=yes], [heve_pthread=no])

# use pkg-config to find libraries
# syntax: PKG_CHECK_MODULES(prefix, list-of-modules, action-if-found, action-if-not-found)
# NOTE: that Makefile.am has to be modified to include:
#    AM_CFLAGS = $({prefix}_CFLAGS)
#    AM_LDFLAGS = $({prefix}_LIBS)
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
# For other libraries who do not provide a pkg-config file
#
# AC_CHECK_LIB([nsl], [gethostbyname])
#

# resolve glib-2.0
PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.40])

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

AC_MSG_RESULT([
Configure Information:
  C Compiler        : $CC
    DEFS            :   $DEFS
    CPPFLAGS        :   $CPPFLAGS
    CFLAGS          :   $CFLAGS

  C++ Compiler      : $CXX
    DEFS            :   $DEFS
    CPPFLAGS        :   $CPPFLAGS
    CXXFLAGS        :   $CXXFLAGS

  Linker            : $LD
    LDFLAGS         :   $LDFLAGS
    LIBS            :   $LIBS

glib:
	CFLAGS          : $GLIB_CFLAGS
	CPPFLAGS        : $GLIB_CPPFLAGS
	CXXFLAGS        : $GLIB_CXXFLAGS
	LIBS            : $GLIB_LIBS

Development:
	Linter                        : $CPPLINT
	Leak Sanitizer Checking       : $SANITY_LEAK
	Address Sanitizer Checking    : $SANITY_ADDRESS
	Undefined Sanitizer Checking  : $SANITY_UNDEFINED
	Thread Sanitizer Checking     : $SANITY_THREAD
	Memory Sanitizer Checking     : $SANITY_MEMORY

Coverage Reports      : $COVERAGE_SUPPORT
    gcov                : $GCOV
      COVERAGE_CFLAGS   : $COVERAGE_CFLAGS
      COVERAGE_CXXFLAGS : $COVERAGE_CXXFLAGS
      COVERAGE_OPTFLAGS : $COVERAGE_OPTFLAGS
      COVERAGE_LDFLAGS  : $COVERAGE_LDFLAGS
      COVERAGE_LIBS     : $COVERAGE_LIBS
    lcov                : $LCOV
])
