# General syntax:
# {WHERE}_{PRIMARY} = targets...
# {WHERE}:
#   "bin": $(bindir) for executables, default $(prefix)/bin
#   "lib": $(libdir) for libraries, default $(prefix)/lib
#   "noinst" = not installed
#   "check" = for "make check"
# {PRIMARY}: the type of file
#   PROGRAMS = executable binary files
#   SCRIPTS = executable scripts
#   DATA = data files

# some variables
# AM_CPPFLAGS: default C preprocessor flags
# AM_CFLAGS: default C compiler flags
# AM_CXXFLAGS: default C++ compiler flags
# AM_LIBS: libraries

# NOTE for using pkg-config:
# suppose we have in our configure.ac:
#   PKG_CHECK_MODULES([DEPS], [list-of-libs...])
# then we do:
# AM_CFLAGS = $(DEPS_CFLAGS)
# AM_LIBS = $(DEPS_LIBS)

# target specific variables
# {TARGET}_{SPECIFICS} = ...
# good specifics:
# SOURCES: list of source files
# LDADD: extra objects for program
# CPPFLAGS: this target's C preprocessor flags

# handling libraries:
# 1. DO NOT FORGET to add LT_INIT to configure.ac
#
# lib_LTLIBRARIES = libwhine-1.la
# libwhine_1_la_SOURCES = src/whine.c src/whine.h
# libwhine_1_la_LDFLAGS = -version-info 1:0:0
# include_HEADERS = src/whine.h
#
# if library is used by a program:
#   hello_LDADD = $(lib_LTLIBRARIES)
# 

# define custom targets for check
# like running tests and linters
# .PHONY: check-test
#   $(MAKE) $(AM_MAKEFLAGS) ...

# define pkgconfig destination
# pkgconfiglibdir = $(libdir)/pkgconfig
# pkgconfiglib_DATA = autotools-unittest.pc

# check building of libraries (like test)
# check_LTLIBRARIES = \
#   lib/gmock/libgmock.la \
#   lib/gmock/libgmock_main.la

# check building of binaries
# check_PROGRAMS = test/sample_test

#############################################

# change macro directory to ./m4
ACLOCAL_AMFLAGS = -I m4 --install

# some extra files which are not source files
EXTRA_DIST = \
	m4/NOTES \
	autogen.sh \
	whine.pc

# define root as include dir
AM_CPPFLAGS = -I$(top_srcdir)/src

# define whine library
lib_LTLIBRARIES = libwhine-1.la
libwhine_1_la_SOURCES = \
	src/whine/whine.c \
	src/whine/whine.h
libwhine_1_la_LDFLAGS = -version-info 1:0:0
include_HEADERS = \
	src/whine/whine.h \
	config.h

# define pkgconfig
pkgconfiglibdir = $(libdir)/pkgconfig
pkgconfiglib_DATA = whine.pc

# Lists programs to be installed
# in "bin" directory
bin_PROGRAMS = hello

# list source files required to
# generate target "hello"
hello_SOURCES = src/hello.c

# hello uses our whine lib!
hello_LDADD = $(lib_LTLIBRARIES)

# clean files for test suits
# CLEANFILES = *.log *.sum
