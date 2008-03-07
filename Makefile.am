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
# * This is free software; you can redistribute it and/or modify it under the *
# * terms of the GNU General Public License as published by the Free Software *
# * Foundation; either version 2 of the License, or (at your option) any      *
# * later version.							      *
# *                                                                           *
# * This software is distributed in the hope that it will be useful, but      *
# * WITHOUT ANY WARRANTY; without even the implied warranty of                *
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General *
# * Public License for more details.                                          *
# *                                                                           *
# * You should have received a copy of the GNU General Public License along   *
# * with software; if not, write to the Free Software Foundation, Inc.,       *
# * 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA                    *
# *                                                                           *
# * CLooG, the Chunky Loop Generator                                          *
# * Written by Cedric Bastoul, Cedric.Bastoul@inria.fr                        *
# *                                                                           *
# *****************************************************************************/

SUBDIRS = . doc test

bin_PROGRAMS = cloog
lib_LTLIBRARIES = libcloog.la

INCLUDES = -I$(top_builddir)/include -I$(top_srcdir)/include
AM_CFLAGS = -Wall -fomit-frame-pointer
libcloog_la_SOURCES = \
	source/block.c \
	source/clast.c \
	source/domain.c \
	source/loop.c \
	source/matrix.c \
	source/names.c \
	source/options.c \
	source/pprint.c \
	source/program.c \
	source/statement.c \
	source/version.c
LDADD = libcloog.la
cloog_SOURCES = source/cloog.c

pkginclude_HEADERS = \
	include/cloog/block.h \
	include/cloog/clast.h \
	include/cloog/cloog.h \
	include/cloog/domain.h \
	include/cloog/loop.h \
	include/cloog/matrix.h \
	include/cloog/names.h \
	include/cloog/options.h \
	include/cloog/pprint.h \
	include/cloog/program.h \
	include/cloog/statement.h \
	include/cloog/version.h

version.h: @GIT_INDEX@
	echo '#define CLOOG_HEAD "'`$(top_builddir)/genversion.sh`'"' > $@

EXTRA_DIST = autoconf/Doxyfile.in doc/images test

dist-hook:
	rm -f $(distdir)/test/Makefile
	$(top_builddir)/genversion.sh > $(distdir)/CLOOG_HEAD
	(cd doc; make cloog.pdf) && cp doc/cloog.pdf $(distdir)/doc/

#/*****************************************************************************
# *                                   Rules                                   *
# *****************************************************************************/

check:
	$(MAKE) test -C test

valcheck:
	$(MAKE) valgrind -C test

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
