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
AX_CHECK_COMPILE_FLAG([-fsanitize=leak], [SANITY_LEAK=1], [AC_MSG_WARN([can not perform memory leak sanity checking])])
AX_CHECK_COMPILE_FLAG([-fsanitize=address], [SANITY_ADDRESS=1], [AC_MSG_WARN([can not perform address sanity checking])])
AX_CHECK_COMPILE_FLAG([-fsanitize=undefined], [SANITY_UNDEFINED=1], [AC_MSG_WARN([can not perform undefined sanity checking])])
AX_CHECK_COMPILE_FLAG([-fsanitize=thread], [SANITY_THREAD=1], [AC_MSG_WARN([can not perform thread sanity checking])])
AX_CHECK_COMPILE_FLAG([-fsanitize=memory], [SANITY_MEMOTY=1], [AC_MSG_WARN([can not perform memory sanity checking])])
AM_CONDITIONAL([HAVE_LEAK_SANITIZER], [test x$SANITY_LEAK = x1])
AM_CONDITIONAL([HAVE_ADDRESS_SANITIZER], [test x$SANITY_ADDRESS = x1])
AM_CONDITIONAL([HAVE_UNDEFINED_SANITIZER], [test x$SANITY_UNDEFINED = x1])
AM_CONDITIONAL([HAVE_THREAD_SANITIZER], [test x$SANITY_THREAD = x1])
AM_CONDITIONAL([HAVE_MEMORY_SANITIZER], [test x$SANITY_MEMORY = x1])

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
AS_IF([test "x$PYTHON" = "x"], [AC_MSG_WARN([python not found, disabling cpplint])])
# export variable PYTHON
AC_SUBST([PYTHON])
# check python version (works for ubuntu xenial 16.04)
AX_PROG_PYTHON_VERSION([2.7.0], [HAVE_PYTHON=1])
AS_IF([test x$HAVE_PYTHON = x], [AC_MSG_WARN([python version lesser than 2.7.0, disabling cpplint])])
# check availability of pip
AC_PATH_PROG([PIP],[pip])
AS_IF([test "x$PIP" = "x"], [AC_MSG_WARN([pip not found, disabling cpplint])])
# export variable PIP
AC_SUBST([PIP])
# check availability of pipenv
AC_PATH_PROG([PIPENV],[pipenv])
AS_IF([test "x$PIPENV" = "x"], [AC_MSG_WARN([pipenv not found, disabling cpplint])])
# export variable PIPENV
AC_SUBST([PIPENV])
AS_IF([test x$HAVE_PYTHON = x1 -a "x$PYTHON" != "x" -a "x$PIP" != "x" -a "x$PIPENV" != "x"], [
	CPPLINT=1
], [AC_MSG_WARN([cpplint disabled])])
AM_CONDITIONAL([HAVE_CPPLINT], [test x$CPPLINT = x1])

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

# resolve glib-2.0
PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.48])

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
])
