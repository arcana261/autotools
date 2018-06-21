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

#############################################

# use custom m4 macro directory
ACLOCAL_AMFLAGS = -I m4 --install

# Lists programs to be installed
# in "bin" directory
bin_PROGRAMS = hello

# list source files required to
# generate target "hello"
hello_SOURCES = hello.c

# clean files for test suits
# CLEANFILES = *.log *.sum
