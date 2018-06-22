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
	autogen.sh \
	whine.pc \
	CPPLINT.cfg \
	pkg/postinst.sh \
	pkg/postrm.sh \
	pkg/preinst.sh \
	pkg/prerm.sh

# define root as include dir
AM_CPPFLAGS = -I$(top_srcdir)/src

# set flags to be later used
AM_CFLAGS = 
AM_LDFLAGS = 

# include glib as dependency
AM_CFLAGS += $(GLIB_CFLAGS)
AM_LDFLAGS += $(GLIB_LIBS)

# check code style via cpplint
.PHONY: lint
if HAVE_CPPLINT
lint:
	find $(top_srcdir)/src -type f -name "*.cc" -or -name "*.c" -or -name "*.cpp" -or -name "*.cu" -or -name "*.cuh" -or -name "*.h" -or -name "*.hpp" | xargs $(CPPLINT) --counting=detailed
endif

# run pre-built tests
.PHONY: check-test
check-test: test/whine/whine_test
	test/whine/whine_test

# run unit tests
.PHONY: unittest
unittest:
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) check-test

#-fprofile-arcs -ftest-coverage
# sanitizer specs
.PHONY: sanity-leak sanity-address sanity-undefined sanity-thread sanity-memory
sanity-leak:
if HAVE_LEAK_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=leak -O0" CXXFLAGS="$(CXXFLAGS) -fsanitize=leak" check-test 
endif
sanity-address:
if HAVE_ADDRESS_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=address -O0" CXXFLAGS="$(CXXFLAGS) -fsanitize=address" check-test 
endif
sanity-undefined:
if HAVE_UNDEFINED_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=undefined -O0" CXXFLAGS="$(CXXFLAGS) -fsanitize=undefined" check-test 
endif
sanity-thread:
if HAVE_THREAD_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=thread -O0" CXXFLAGS="$(CXXFLAGS) -fsanitize=thread" LDFLAGS="$(LDFLAGS) -shared" check-test 
endif
sanity-memory:
if HAVE_MEMORY_SANITIZER
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) CFLAGS="$(CFLAGS) -fsanitize=memory -O0" CXXFLAGS="$(CXXFLAGS) -fsanitize=memory" check-test 
endif

# run all sanitizers
.PHONY: sanity
sanity: | sanity-leak sanity-address sanity-undefined sanity-thread sanity-memory

# run code coverage
# notable outputs
# Summary coverage rate:
#  lines......: 40.0% (2 of 5 lines)
#  functions..: 50.0% (1 of 2 functions)
#  branches...: no data found
# Overall coverage rate:
#  lines......: 40.0% (2 of 5 lines)
#  functions..: 50.0% (1 of 2 functions)
.PHONY: coverage
coverage:
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) \
		CFLAGS="$(CFLAGS) $(COVERAGE_CFLAGS) $(COVERAGE_OPTFLAGS)" \
		CXXFLAGS="$(CXXFLAGS) $(COVERAGE_CXXFLAGS) $(COVERAGE_OPTFLAGS)" \
		LDFLAGS="$(LDFLAGS) $(COVERAGE_LDFLAGS)" \
		LIBS="$(LIBS) $(COVERAGE_LIBS)" \
		check-test
	$(LCOV) --capture \
		--directory "$(top_builddir)/src" \
		--base-directory "$(abspath $(top_builddir))" \
		--output-file $(top_builddir)/coverage.info \
		--gcov-tool "$(GCOV)" \
		--compat-libtool --checksum
	$(LCOV) \
		--extract $(top_builddir)/coverage.info "$(abspath $(top_srcdir))/src/*" \
		--gcov-tool $(GCOV) \
		--output-file $(top_builddir)/coverage.info
	$(GENHTML) \
		--prefix "$(abspath $(top_srcdir))" \
		--output-directory $(top_builddir)/coverage \
        --title $(PACKAGE_NAME) \
		--legend --show-details \
		$(GENHTML_OPTIONS) \
		$(top_builddir)/coverage.info

clean-coverage:
	find $(top_builddir) -name *.gcda -exec rm -f {} +
	find $(top_builddir) -name *.gcno -exec rm -f {} +
	find $(top_builddir) -name *.gcov -exec rm -f {} +
	rm -f $(top_builddir)/coverage.info
	rm -rfv $(top_builddir)/coverage

# debian packaging
if HAVE_DEBIAN_PACKAGING
deb:
	$(MAKE) $(AM_MAKEFLAGS) dist-gzip
	rm -rf $(distdir)
	GZIP=$(GZIP_ENV) gzip -dc $(distdir).tar.gz | $(am__untar)
	$(MKDIR_P) $(distdir)/_build/DEBIAN
	install_base=`$(am__cd) $(distdir)/_build && pwd` \
		&& $(am__cd) $(distdir) \
		&& ./configure $(AM_CONFIGURE_FLAGS) --prefix="$$install_base" \
		&& $(MAKE) $(AM_MAKEFLAGS) \
		&& $(MAKE) $(AM_MAKEFLAGS) install
	cat pkg/preinst.sh | $(SED) "s/__VERSION__/${VERSION}/g" > $(distdir)/_build/DEBIAN/preinst
	cat pkg/prerm.sh | $(SED) "s/__VERSION__/${VERSION}/g" > $(distdir)/_build/DEBIAN/prerm
	cat pkg/postinst.sh | $(SED) "s/__VERSION__/${VERSION}/g" > $(distdir)/_build/DEBIAN/postinst
	cat pkg/postrm.sh | $(SED) "s/__VERSION__/${VERSION}/g" > $(distdir)/_build/DEBIAN/postrm
	chmod +x $(distdir)/_build/DEBIAN/preinst
	chmod +x $(distdir)/_build/DEBIAN/postinst
	chmod +x $(distdir)/_build/DEBIAN/prerm
	chmod +x $(distdir)/_build/DEBIAN/postrm
	arch=`echo $(host_cpu) | $(SED) "s/x86_64/amd64/g"` && \
		name=`echo $(PACKAGE_NAME) | $(SED) "s/_/-/g"` && \
		cat pkg/debian.in | \
		$(SED) "s/__VERSION__/${VERSION}/g" | \
		$(SED) "s/__NAME__/$$name/g" | \
		$(SED) "s/__ARCHITECTURE__/$$arch/g" \
		> $(distdir)/_build/DEBIAN/control
	$(DPKG_DEB) --build $(distdir)/_build
	$(am__mv) $(distdir)/_build.deb $(distdir).deb
endif

# define extensions to "make check"
check-local: | check-test

# define extensions to "make clean"
clean-local: | clean-coverage

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
