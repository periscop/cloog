#
#   /**-------------------------------------------------------------------**
#    **                              CLooG                                **
#    **-------------------------------------------------------------------**
#    **                           makefile.in                             **
#    **-------------------------------------------------------------------**
#    **                   First version: october 25th 2001                **
#    **-------------------------------------------------------------------**/
#
# makefile.in (or makefile if generated) of CLooG, the Chunky LOOp Generator.
# makefile.in is not a makefile, you must run the 'configure' shellscript to
# generate the makefile thanks to this file.

#/*****************************************************************************
# *               CLooG : the Chunky Loop Generator (experimental)            *
# *****************************************************************************
# *                                                                           *
# * Copyright (C) 2001 Cedric Bastoul                                         *
# *                                                                           *
# * This library is free software; you can redistribute it and/or             *
# * modify it under the terms of the GNU Lesser General Public                *
# * License as published by the Free Software Foundation; either              *
# * version 2.1 of the License, or (at your option) any later version.        *
# *                                                                           *
# * This library is distributed in the hope that it will be useful,           *
# * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
# * Lesser General Public License for more details.                           *
# *                                                                           *
# * You should have received a copy of the GNU Lesser General Public          *
# * License along with this library; if not, write to the Free Software       *
# * Foundation, Inc., 51 Franklin Street, Fifth Floor,                        *
# * Boston, MA  02110-1301  USA                                               *
# *                                                                           *
# * CLooG, the Chunky Loop Generator                                          *
# * Written by Cedric Bastoul, Cedric.Bastoul@inria.fr                        *
# *                                                                           *
# *****************************************************************************/
if BUNDLED_ISL
    MAYBE_ISL = isl
    ISL_LA = $(top_builddir)/isl/libisl.la
endif

if BUNDLED_OSL
    MAYBE_OSL = osl
    OSL_LA = $(top_builddir)/osl/libosl.la
endif

AUTOMAKE_OPTIONS = subdir-objects
SUBDIRS = $(MAYBE_ISL) $(MAYBE_OSL) .
DIST_SUBDIRS = $(MAYBE_ISL) $(MAYBE_OSL) .

ACLOCAL_AMFLAGS = -I m4

FORCE:
isl/libisl.la: FORCE
	cd isl; $(MAKE) $(AM_MAKEFLAGS) libisl.la

if NO_ISL
CLOOG =
LIBCLOOG =
else
CLOOG = cloog
LIBCLOOG = libcloog-isl.la
endif
bin_PROGRAMS = $(CLOOG)
lib_LTLIBRARIES = $(LIBCLOOG)

if NEED_GET_MEMORY_FUNCTIONS
GET_MEMORY_FUNCTIONS=source/mp_get_memory_functions.c
endif

SOURCES_CORE = \
	$(GET_MEMORY_FUNCTIONS) \
	source/block.c \
	source/clast.c \
	source/matrix.c \
	source/state.c \
	source/input.c \
	source/int.c \
	source/loop.c \
	source/names.c \
	source/options.c \
	source/pprint.c \
	source/program.c \
	source/statement.c \
	source/stride.c \
	source/union_domain.c \
	source/util.c \
	source/version.c

AM_CPPFLAGS = -I. -I$(top_builddir)/include -I$(top_srcdir)/include
AM_CFLAGS = $(CFLAGS_WARN)
libcloog_isl_la_CPPFLAGS = -I. -I$(top_builddir)/include -I$(top_srcdir)/include @ISL_CPPFLAGS@ @OSL_CPPFLAGS@
libcloog_isl_la_LDFLAGS = -version-info @versioninfo@ \
	-rpath $(libdir) @ISL_LDFLAGS@ @OSL_LDFLAGS@
libcloog_isl_la_LIBADD = @ISL_LIBS@ @OSL_LIBS@ $(ISL_LA) $(OSL_LA)
libcloog_isl_la_SOURCES = \
	$(SOURCES_CORE) \
	source/isl/domain.c \
	source/isl/constraints.c \
	source/isl/backend.c
LDADD = libcloog-isl.la
cloog_DEPENDENCIES = libcloog-isl.la
cloog_SOURCES = source/cloog.c

pkginclude_HEADERS = \
	include/cloog/block.h \
	include/cloog/clast.h \
	include/cloog/cloog.h \
	include/cloog/input.h \
	include/cloog/int.h \
	include/cloog/matrix.h \
	include/cloog/state.h \
	include/cloog/domain.h \
	include/cloog/loop.h \
	include/cloog/constraints.h \
	include/cloog/names.h \
	include/cloog/options.h \
	include/cloog/pprint.h \
	include/cloog/program.h \
	include/cloog/statement.h \
	include/cloog/stride.h \
	include/cloog/union_domain.h \
	include/cloog/util.h \
	include/cloog/version.h

pkgmatrixincludedir = $(pkgincludedir)/matrix
pkgmatrixinclude_HEADERS = \
	include/cloog/matrix/constraintset.h

pkgislincludedir = $(pkgincludedir)/isl
pkgislinclude_HEADERS = \
	include/cloog/isl/backend.h \
	include/cloog/isl/cloog.h \
	include/cloog/isl/domain.h \
	include/cloog/isl/constraintset.h

version.h: @GIT_INDEX@
	echo '#define CLOOG_HEAD "'`$(top_builddir)/genversion.sh`'"' > $@

EXTRA_DIST = \
	autoconf/Doxyfile.in \
	source/matrix/constraintset.c \
	cmake \
	doc \
	examples

install-data-local:
	@test -z "$(pkgconfig_libdir)" || $(mkdir_p) "$(DESTDIR)$(pkgconfig_libdir)"
	$(INSTALL_DATA) $(pkgconfig_libfile) "$(DESTDIR)$(pkgconfig_libdir)/$(pkgconfig_libfile)"
	@test -z "$(DESTDIR)$(libdir)/isl" || $(mkdir_p) "$(DESTDIR)$(libdir)/isl"
	$(INSTALL_DATA) "$(top_srcdir)/cmake/isl-config.cmake" "$(DESTDIR)$(libdir)/isl/"
	@test -z "$(DESTDIR)$(libdir)/$(PACKAGE_NAME)" || $(mkdir_p) "$(DESTDIR)$(libdir)/$(PACKAGE_NAME)"
	$(INSTALL_DATA) "$(top_srcdir)/cmake/cloog-isl-config.cmake" "$(DESTDIR)$(libdir)/$(PACKAGE_NAME)/"

uninstall-local:
	rm -f "$(DESTDIR)$(pkgconfig_libdir)/$(pkgconfig_libfile)"
	rm -f "$(DESTDIR)$(libdir)/isl/isl-config.cmake"
	rm -f "$(DESTDIR)$(libdir)/$(PACKAGE_NAME)/cloog-isl-config.cmake"

dist-hook:
	$(top_builddir)/genversion.sh > $(distdir)/CLOOG_HEAD

#/*****************************************************************************
# *                                   Rules                                   *
# *****************************************************************************/

total:
	@echo "             /*-----------------------------------------------*"
	@echo "              *                     CLooG                     *"
	@echo "              *-----------------------------------------------*/"
	$(MAKE) uninstall
	$(MAKE) clean
	$(MAKE)
	$(MAKE) install

doc:
	@echo "             /*-----------------------------------------------*"
	@echo "              *        Generating CLooG's documentation       *"
	@echo "              *-----------------------------------------------*/"
	doxygen ./autoconf/Doxyfile

#/*****************************************************************************
# *                                   Doc                                     *
# *****************************************************************************/

if HAVE_TEXI2DVI
pdf_DATA = doc/cloog.pdf
dist_pdf_DATA = doc/cloog.pdf
doc/cloog.pdf: doc/cloog.texi doc/gitversion.texi
	$(TEXI2DVI) -I $(top_builddir)/doc --pdf $< -o $@
endif

doc/gitversion.texi: @GIT_INDEX@
	echo '@set VERSION '`$(top_builddir)/genversion.sh`'' > $@

#/*****************************************************************************
# *                                   Tests                                    *
# *****************************************************************************/

if NO_ISL
GENERATE_TEST_ADVANCED =
else
GENERATE_TEST_ADVANCED = test/generate_test_advanced
endif
noinst_PROGRAMS = $(GENERATE_TEST_ADVANCED)
test_generate_test_advanced_SOURCES = test/generate_test_advanced.c

FINITE_CLOOGTEST_C = \
	test/0D-1 \
	test/0D-2 \
	test/0D-3 \
	test/1point-1 \
	test/1point-2 \
	test/4-param \
	test/basic-bounds-1 \
	test/basic-bounds-2 \
	test/basic-bounds-3 \
	test/basic-bounds-4 \
	test/basic-bounds-5 \
	test/basic-bounds-6 \
	test/block \
	test/block2 \
	test/block3 \
	test/byu98-1-2-3 \
	test/cholesky \
	test/cholesky2 \
	test/christian \
	test/classen \
	test/classen2 \
	test/constant \
	test/constbound \
	test/darte \
	test/dealII \
	test/donotsimp \
	test/dot \
	test/dot2 \
	test/double \
	test/durbin_e_s \
	test/emploi \
	test/esced \
	test/ex1 \
	test/forwardsub-1-1-2 \
	test/forwardsub-2-1-2-3 \
	test/forwardsub-3-1-2 \
	test/gauss \
	test/gesced \
	test/gesced2 \
	test/gesced3 \
	test/guide \
	test/iftest \
	test/iftest2 \
	test/largeur \
	test/levenshtein-1-2-3 \
	test/lex \
	test/lineality-1-2 \
	test/lineality-2-1-2 \
	test/logo \
	test/logopar \
	test/lu \
	test/lu2 \
	test/lub \
	test/lux \
	test/min-1-1 \
	test/min-2-1 \
	test/min-3-1 \
	test/min-4-1 \
	test/mode \
	test/multi-mm-1 \
	test/no_lindep \
	test/orc \
	test/rectangle \
	test/singleton \
	test/square+triangle-1-1-2-3 \
	test/swim \
	test/test \
	test/thomasset \
	test/tiling \
	test/uday_scalars \
	test/union \
	test/vivien \
	test/vivien2 \
	test/walters \
	test/walters2 \
	test/walters3 \
	test/wavefront \
	test/yosr \
	test/yosr2 \
	test/non_optimal/nul_complex1 \
	test/non_optimal/usvd_e_t \
	test/non_optimal/youcef \
	test/reservoir/cholesky2 \
	test/reservoir/fusion1 \
	test/reservoir/fusion2 \
	test/reservoir/jacobi2 \
	test/reservoir/jacobi3 \
	test/reservoir/lim-lam1 \
	test/reservoir/lim-lam2 \
	test/reservoir/lim-lam3 \
	test/reservoir/lim-lam4 \
	test/reservoir/lim-lam5 \
	test/reservoir/lim-lam6 \
	test/reservoir/liu-zhuge1 \
	test/reservoir/loechner3 \
	test/reservoir/loechner4 \
	test/reservoir/loechner5 \
	test/reservoir/mg-interp2 \
	test/reservoir/mg-interp \
	test/reservoir/mg-psinv \
	test/reservoir/mg-resid \
	test/reservoir/mg-rprj3 \
	test/reservoir/pingali1 \
	test/reservoir/pingali2 \
	test/reservoir/pingali3 \
	test/reservoir/pingali4 \
	test/reservoir/pingali5 \
	test/reservoir/pingali6 \
	test/reservoir/QR \
	test/reservoir/tang-xue1 \
	test/reservoir/two

CLOOG_ISL_TEST_C = \
	test/isl/mod \
	test/isl/mod2 \
	test/isl/mod3 \
	test/isl/mod4

CLOOGTEST_C = \
	test/infinite \
	test/infinite2 \
	test/infinite3 \
	test/infinite4 \
	$(FINITE_CLOOGTEST_C) \
	$(CLOOG_ISL_TEST_C)

CLOOGTEST_FORTRAN = \
	test/dartef \
	test/iftestf \
	test/levenshtein-1-2-3f \
	test/yosrf

CLOOG_ISL_TEST_STRIDED = \
	test/isl/mxm-shared

CLOOGTEST_STRIDED = \
	test/basic-bounds-2 \
	test/mod4 \
	test/nul_basic1 \
	test/nul_basic2 \
	test/nul_lcpc \
	test/multi-stride \
	test/multi-stride2 \
	test/stride3 \
	test/stride4 \
	test/reservoir/bastoul3 \
	test/reservoir/stride \
	test/reservoir/stride2 \
	$(CLOOG_ISL_TEST_STRIDED)

if NO_OSL
CLOOGTEST_OPENSCOP =
else
CLOOGTEST_OPENSCOP = \
	test/openscop/matmult \
	test/openscop/empty \
	test/openscop/loops \
	test/openscop/union \
	test/openscop/coordinates \
	test/openscop/clay
endif

SPECIAL_TESTS = \
	test/isl/unroll \
	test/isl/jacobi-shared \
	test/isl/unroll2 \
	test/backtrack \
	test/vasilache \
	test/merge \
	test/equality \
	test/equality2 \
	test/otl \
	test/param-split \
	test/pouchet \
	test/stride \
	test/stride2 \
	test/sor1d

SPECIAL_OPTIONS = \
	'test/isl/unroll -first-unroll 1' \
	'test/isl/jacobi-shared -f 4 -l -1 -override -strides 1 -sh 1' \
	'test/isl/unroll2 -first-unroll 1' \
	'test/backtrack -f 1 -backtrack' \
	'test/vasilache -f 8 -l 9' \
	'test/merge -f -1' \
	'test/equality -f -1 -l 2 -override' \
	'test/equality2 -f -1 -l 4 -esp 1 -override' \
	'test/otl -block 1 -esp 0 -otl 0' \
	'test/param-split -f -1' \
	'test/pouchet -f 3 -l 7' \
	'test/stride -f -1 -strides 1' \
	'test/stride2 -f -1 -strides 1' \
	'test/sor1d -f -1'

generate:
	@echo "             /*-----------------------------------------------*"
	@echo "              *                 Generate files                *"
	@echo "              *-----------------------------------------------*/"
	@for x in $(CLOOGTEST_C) ; do \
		echo "Generate $$x.c" ; \
		$(top_builddir)/cloog $(srcdir)/$$x.cloog -o $(srcdir)/$$x.c ; \
	done ; \
	for x in $(CLOOGTEST_FORTRAN) ; do \
		echo "Generate $$x.f" ; \
		$(top_builddir)/cloog $(srcdir)/$$x.cloog -o $(srcdir)/$$x.f ; \
	done ; \
	for x in $(CLOOGTEST_STRIDED) ; do \
		echo "Generate $$x.c" ; \
		$(top_builddir)/cloog $(srcdir)/$$x.cloog \
			-strides 1 -o $(srcdir)/$$x.c ; \
	done ; \
	for x in $(CLOOGTEST_OPENSCOP) ; do \
		echo "Generate $$x.c" ; \
		$(top_builddir)/cloog $(srcdir)/$$x.scop \
		-openscop -o $(srcdir)/$$x.c ; \
	done ; \
	for line in $(SPECIAL_OPTIONS); do \
		options=`echo $$line | sed -e 's/^[^ ]* //'`; \
		x=`echo $$line | sed -e 's/ .*//'`; \
		echo "Generate file $$x ($$options)" ; \
		$(top_builddir)/cloog$(EXEEXT) $(srcdir)/$$x.cloog \
		    $$options > $(srcdir)/$$x.c ; \
	done

generate_good:
	@for x in $(FINITE_CLOOGTEST_C) ; do \
		echo "Generate $$x.good.c" ; \
		$(top_builddir)/cloog$(EXEEXT) -callable 1 $(srcdir)/$$x.cloog -o $(srcdir)/$$x.good.c ; \
	done; \
	for line in $(SPECIAL_OPTIONS); do echo $$line | while read x options; do \
		echo "Generate $$x.good.c ($$options)" ; \
		$(top_builddir)/cloog$(EXEEXT) -callable 1 $$options $(srcdir)/$$x.cloog -o $(srcdir)/$$x.good.c ; \
	done; done

valcheck: test_valgrind

CHECKER := "$(srcdir)/test/checker.sh"

TESTS_ENVIRONMENT = \
	builddir=$(builddir) \
	top_builddir=$(top_builddir) \
	srcdir=$(srcdir) \
	EXEXT=$(EXEEXT) \
	CHECKER=$(CHECKER) \
	COMPILE="$(COMPILE)" \
	LINK="$(LINK)" \
	FINITE_CLOOGTEST_C="$(FINITE_CLOOGTEST_C)" \
	CLOOGTEST_C="$(CLOOGTEST_C)" \
	CLOOGTEST_FORTRAN="$(CLOOGTEST_FORTRAN)" \
	CLOOGTEST_STRIDED="$(CLOOGTEST_STRIDED)" \
	CLOOGTEST_OPENSCOP="$(CLOOGTEST_OPENSCOP)" \
	SPECIAL_OPTIONS="$(SPECIAL_OPTIONS)"

test_hybrid: test/generate_test_advanced$(EXEEXT)
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_hybrid.sh;

test_valgrind:
	$(RM) -rf $(srcdir)/logs; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_c.sh valgrind ; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_fortran.sh valgrind ; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_strided.sh valgrind ; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_openscop.sh valgrind ; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_special.sh valgrind;

test_regenerate:
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_c.sh regenerate ; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_fortran.sh regenerate ; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_strided.sh regenerate ; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_openscop.sh regenerate ; \
	$(TESTS_ENVIRONMENT) $(srcdir)/test/check_special.sh regenerate

check_SCRIPTS = \
	test/check_c.sh \
	test/check_strided.sh \
	test/check_openscop.sh \
	test/check_special.sh

TESTS = $(check_SCRIPTS)

EXTRA_DIST += \
	$(check_SCRIPTS) \
	$(srcdir)/test/checker.sh \
	$(CLOOGTEST_C:%=%.cloog) \
	$(CLOOGTEST_C:%=%.c) \
	$(FINITE_CLOOGTEST_C:%=%.good.c) \
	$(CLOOGTEST_FORTRAN:%=%.cloog) \
	$(CLOOGTEST_FORTRAN:%=%.f) \
	$(CLOOGTEST_STRIDED:%=%.cloog) \
	$(CLOOGTEST_STRIDED:%=%.c) \
	$(CLOOGTEST_OPENSCOP:%=%.scop) \
	$(CLOOGTEST_OPENSCOP:%=%.c) \
	$(SPECIAL_TESTS:%=%.cloog) \
	$(SPECIAL_TESTS:%=%.c) \
	$(SPECIAL_TESTS:%=%.good.c) \
	test/openscop/clay_orig.c \
	test/openscop/coordinates_orig.c
