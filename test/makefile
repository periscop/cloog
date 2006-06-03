#
#   /**-------------------------------------------------------------------**
#    **                              CLooG                                **
#    **-------------------------------------------------------------------**
#    **                            makefile                               **
#    **-------------------------------------------------------------------**
#    **                   First version: march 6th 2003                   **
#    **-------------------------------------------------------------------**/
#
# makefile for checking.

#/*****************************************************************************
# *               CLooG : the Chunky Loop Generator (experimental)            *
# *****************************************************************************
# *                                                                           *
# * Copyright (C) 2003 Cedric Bastoul                                         *
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
# * This file has been written with the help of the Bart Kienhuis's checking  *
# * makefile for PipLib.                                                      *
# *                                                                           *
# *****************************************************************************/

ROOT = ..

CLOOGTEST_C =                          \
	1point-1                       \
	1point-2                       \
	4-param                        \
	basic-bounds-1                 \
	basic-bounds-2                 \
	basic-bounds-3                 \
	basic-bounds-4                 \
	basic-bounds-5                 \
	basic-bounds-6                 \
	byu98-1-2-3                    \
	cholesky                       \
	cholesky2                      \
	classen                        \
	darte                          \
	donotsimp                      \
	dot                            \
	dot2                           \
	double                         \
	durbin_e_s                     \
	emploi                         \
	esced                          \
	escedk                         \
	ex1                            \
	forwardsub-1-1-2               \
	forwardsub-2-1-2-3             \
	forwardsub-3-1-2               \
	gauss                          \
	gesced                         \
	gesced2                        \
	gesced3                        \
	guide                          \
	iftest                         \
	iftest2                        \
	infinite                       \
	infinite2                      \
	infinite3                      \
	infinite4                      \
	largeur                        \
	levenshtein-1-2-3              \
	lineality-1-2                  \
	lineality-2-1-2                \
	logo                           \
	logopar                        \
	lu                             \
	lu2                            \
	lub                            \
	lux                            \
	min-1-1                        \
	min-2-1                        \
	min-3-1                        \
	min-4-1                        \
	mode                           \
	multi-mm-1                     \
	no_lindep                      \
	orc                            \
	rectangle                      \
	square+triangle-1-1-2-3        \
	swim                           \
	test                           \
	thomasset                      \
	tiling                         \
	vivien                         \
	vivien2                        \
	wavefront                      \
	yosr                           \
	yosr2                          \
	./non_optimal/nul_complex1     \
	./non_optimal/usvd_e_t         \
	./non_optimal/youcef           \
	./reservoir/cholesky2          \
	./reservoir/fusion1            \
	./reservoir/fusion2            \
	./reservoir/jacobi2            \
	./reservoir/jacobi3            \
	./reservoir/lim-lam1           \
	./reservoir/lim-lam2           \
	./reservoir/lim-lam3           \
	./reservoir/lim-lam4           \
	./reservoir/lim-lam5           \
	./reservoir/lim-lam6           \
	./reservoir/liu-zhuge1         \
	./reservoir/loechner3          \
	./reservoir/loechner4          \
	./reservoir/loechner5          \
	./reservoir/mg-interp2         \
	./reservoir/mg-interp          \
	./reservoir/mg-psinv           \
	./reservoir/mg-resid           \
	./reservoir/mg-rprj3           \
	./reservoir/pingali1           \
	./reservoir/pingali2           \
	./reservoir/pingali3           \
	./reservoir/pingali4           \
	./reservoir/pingali5           \
	./reservoir/pingali6           \
	./reservoir/QR                 \
	./reservoir/tang-xue1          \
	./reservoir/two   

#	./reservoir/long               \
#	faber                          \

CLOOGTEST_FORTRAN =                    \
	dartef                         \
	iftestf                        \
	levenshtein-1-2-3f             \
	yosrf

CLOOGTEST_STRIDED =                    \
	nul_basic1                     \
	nul_basic2                     \
	nul_lcpc		       \
	reservoir/stride	       \
	reservoir/stride2

generate:
	@echo "             /*-----------------------------------------------*"
	@echo "              *                 Generate files                *"
	@echo "              *-----------------------------------------------*/"
	for x in $(CLOOGTEST_C) ; do \
		echo "Generate $$x.c" ; \
		cloog $$x.cloog -o $$x.c ; \
	done ; \
	for x in $(CLOOGTEST_FORTRAN) ; do \
		echo "Generate $$x.f" ; \
		cloog $$x.cloog -o $$x.f ; \
	done

valgrind:
	@echo "             /*-----------------------------------------------*"
	@echo "              *            Checking files by Valgrind         *"
	@echo "              *-----------------------------------------------*/"
	for x in $(CLOOGTEST_C) ; do \
		echo "Valgrinding $$x.c" ; \
		valgrind $(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog ; \
	done ; \
	for x in $(CLOOGTEST_FORTRAN) ; do \
		echo "Valgrinding $$x.f" ; \
		valgrind $(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog ; \
	done

test:
	@echo "             /*-----------------------------------------------*"
	@echo "              *                 Testing CLooG                 *"
	@echo "              *-----------------------------------------------*/"
	failedtest=0 ; \
	echo "--- Testing C files..." ; \
	for x in $(CLOOGTEST_C) ; do \
		echo "Verify file $$x" ; \
		$(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog > ttemp ; \
		diff -w --ignore-matching-lines='CLooG' ttemp $$x.c ; \
		result=$$?; \
		if [ "$$result" -eq "1" ] ; then \
			echo "!!! Error: $$x is not the same" ; \
			failedtest=`expr $$failedtest + 1` ; \
		else \
			echo "$$x passed" ; \
	        fi ; \
	done ; \
	echo "--- Testing FORTRAN files..." ; \
	for x in $(CLOOGTEST_FORTRAN) ; do \
		echo "Verify file $$x" ; \
		$(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog > ttemp ; \
		diff -w --ignore-matching-lines='CLooG' ttemp $$x.f ; \
		result=$$?; \
		if [ "$$result" -eq "1" ] ; then \
			echo "!!! Error: $$x is not the same" ; \
			failedtest=`expr $$failedtest + 1` ; \
		else \
			echo "$$x passed" ; \
	        fi ; \
	done ; \
	echo "--- Testing STRIDED files..." ; \
	for x in $(CLOOGTEST_STRIDED) ; do \
		echo "Verify file $$x" ; \
		$(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog \
		-strides 1 > ttemp ; \
		diff -w --ignore-matching-lines='CLooG' ttemp $$x.c ; \
		result=$$?; \
		if [ "$$result" -eq "1" ] ; then \
			echo "!!! Error: $$x is not the same" ; \
			failedtest=`expr $$failedtest + 1` ; \
		else \
			echo "$$x passed" ; \
	        fi ; \
	done ; \
	echo "--- Testing SPECIAL OPTIONS files..." ; \
	        echo "Verify file vasilache (-f 8 -l 9)" ; \
		x=vasilache ; \
		$(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog \
		-f 8 -l 9 > ttemp ; \
		diff -w --ignore-matching-lines='CLooG' ttemp $$x.c ; \
		result=$$?; \
		if [ "$$result" -eq "1" ] ; then \
			echo "!!! Error: $$x is not the same" ; \
			failedtest=`expr $$failedtest + 1` ; \
		else \
			echo "$$x passed" ; \
	        fi ; \
	        echo "Verify file merge (-f -1)" ; \
		x=merge ; \
		$(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog \
		-f -1  > ttemp ; \
		diff -w --ignore-matching-lines='CLooG' ttemp $$x.c ; \
		result=$$?; \
		if [ "$$result" -eq "1" ] ; then \
			echo "!!! Error: $$x is not the same" ; \
			failedtest=`expr $$failedtest + 1` ; \
		else \
			echo "$$x passed" ; \
	        fi ; \
	        echo "Verify file equality (-f -1 -l 2 -override)" ; \
		x=equality ; \
		$(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog \
		-f -1 -l 2 -override  > ttemp ; \
		diff -w --ignore-matching-lines='CLooG' ttemp $$x.c ; \
		result=$$?; \
		if [ "$$result" -eq "1" ] ; then \
			echo "!!! Error: $$x is not the same" ; \
			failedtest=`expr $$failedtest + 1` ; \
		else \
			echo "$$x passed" ; \
	        fi ; \
	        echo "Verify file equality (-f -1 -l 4 -esp 1 -override)" ; \
		x=equality2; \
		$(ROOT)/obj_$(TARGET)/cloog$(EXEC_SUFFIX) $$x.cloog \
		-f -1 -l 4 -esp 1 -override > ttemp ; \
		diff -w --ignore-matching-lines='CLooG' ttemp $$x.c ; \
		result=$$?; \
		if [ "$$result" -eq "1" ] ; then \
			echo "!!! Error: $$x is not the same" ; \
			failedtest=`expr $$failedtest + 1` ; \
		else \
			echo "$$x passed" ; \
	        fi ; \
	rm ttemp ; \
	if [ $$failedtest != 0 ] ; then \
		echo "$$failedtest tests failed" ; \
	else \
	        echo "CLooG works correctly :-) !" ; \
        fi

# Include the shared compilation rules
include $(ROOT)/makefile
