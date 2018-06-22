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
# like running tests and linterss
# check-local: <TARGETS>
# 	$(MAKE) $(AM_MAKEFLAGS) ...
# 

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

# set flags to be later used
AM_CFLAGS = 
AM_LDFLAGS = 

# include glib as dependency
AM_CFLAGS += $(GLIB_CFLAGS)
AM_LDFLAGS += $(GLIB_LIBS)

# check code style via cpplint
CPPLINT_OPTIONS =
Pipfile.lock: Pipfile
if HAVE_CPPLINT
	$(PIPENV) install
endif
.PHONY: check-cpplint
check-cpplint: Pipfile.lock
if HAVE_CPPLINT
	find $(top_srcdir)/src $(top_srcdir)/test -type f -name "*.cc" -or -name "*.cpp" -or -name "*.cu" -or -name "*.cuh" -or -name "*.h" -or -name "*.hpp" | xargs $(PIPENV) run cpplint --extensions=cc,cpp,cu,cuh,h,hpp --counting=detailed $(CPPLINT_OPTIONS)
endif

# run pre-built tests
.PHONY: check-test
check-test: test/whine/whine_test
	test/whine/whine_test

# run unit tests
.PHONY: check-unittest
check-unittest:
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) check-test

#-fprofile-arcs -ftest-coverage
# sanitizer specs
.PHONY: check-sanity-leak check-sanity-address check-sanity-undefined check-sanity-thread check-sanity-memory
check-sanity-leak:
if HAVE_LEAK_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=leak" CXXFLAGS="$(CXXFLAGS) -fsanitize=leak" check-test 
endif
check-sanity-address:
if HAVE_ADDRESS_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=address" CXXFLAGS="$(CXXFLAGS) -fsanitize=address" check-test 
endif
check-sanity-undefined:
if HAVE_UNDEFINED_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=undefined" CXXFLAGS="$(CXXFLAGS) -fsanitize=undefined" check-test 
endif
check-sanity-thread:
if HAVE_THREAD_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=thread" CXXFLAGS="$(CXXFLAGS) -fsanitize=thread" check-test 
endif
check-sanity-memory:
if HAVE_MEMORY_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=memory" CXXFLAGS="$(CXXFLAGS) -fsanitize=memory" check-test 
endif

# run all sanitizers
.PHONY: check-sanity
check-sanity: | check-sanity-leak check-sanity-address check-sanity-undefined check-sanity-thread check-sanity-memory

# define extensions to "make check"
check-local: | check-cpplint check-unittest check-sanity

# define extensions to "make clean"
clean-local:
	rm -f *.gcno

# define whine library
lib_LTLIBRARIES = libwhine-1.la
libwhine_1_la_SOURCES = \
	src/whine/whine.c \
	src/whine/whine.h
libwhine_1_la_LDFLAGS = -version-info 1:0:0
include_HEADERS = \
	src/whine/whine.h \
	config.h
# define test for whine library
check_PROGRAMS = test/whine/whine_test 
test_whine_whine_test_SOURCES = test/whine/whine_test.c
test_whine_whine_test_LDADD = $(lib_LTLIBRARIES)
#test_whine_whine_test_CFLAGS = $(AM_CFLAGS) -fsanitize=address \
#	-fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer
#test_whine_whine_test_race_SOURCES = $(test_whine_whine_test_SOURCES)
#test_whine_whine_test_race_CFLAGS = $(AM_CFLAGS) -fsanitize=thread -fno-omit-frame-pointer


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
