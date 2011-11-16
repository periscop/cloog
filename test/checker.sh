#!/bin/sh
#
#   /**-------------------------------------------------------------------**
#    **                              CLooG                                **
#    **-------------------------------------------------------------------**
#    **                           checker.sh                              **
#    **-------------------------------------------------------------------**
#    **                 First version: November 16th 2011                 **
#    **-------------------------------------------------------------------**/
#

#/*****************************************************************************
# *               CLooG : the Chunky Loop Generator (experimental)            *
# *****************************************************************************
# *                                                                           *
# * Copyright (C) 2003 Cedric Bastoul                                         *
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

# This is the main test script of CLooG. It checks that CLooG generates
# a convenient output for an input set of tests, according to some
# parameters (see below). Two checking policies are possible: simply
# compare the generated codes or compare the executions of the generated
# codes. The reference output files must be present: if we are checking a
# file foo.cloog, either foo.c or foo.f must exist in the case of a simple
# code generation checking, and either foo.good.c or foo.good.f must exist
# in the case of a run check.

TEST_NAME="$1"             ## Name of the group of files to test

TEST_FILES="$2"            ## List of test file prefixes and individual options
                           ## spaces between the elements of one test are
                           ## represented with '%', e.g., "file -f -1" is
                           ## "file%-f%-1".

TEST_GLOBAL_OPTIONS="$3"   ## Options for all the tests in the group

TEST_INPUT_EXTENSION="$4"  ## Extension of the input file

TEST_OUTPUT_EXTENSION="$5" ## Extension of the generated file

TEST_RUN="$6"              ## "1" if the checking policy is to generate,
                           ## compile and run, generate only otherwise

failedtest=0;
cloog=$top_builddir/cloog$EXEEXT
echo "             /*-----------------------------------------------*"
echo "              *       Testing CLooG: $TEST_NAME test set       "
echo "              *-----------------------------------------------*/"
for x in $TEST_FILES; do
    name=`echo $x | sed 's/%/ /g' | cut -d\  -f1`;
    individual_options=`echo $x | sed 's/%/ /g' | cut -s -d\  -f2-`;
    input="$srcdir/$name.$TEST_INPUT_EXTENSION";
    output="$srcdir/$name.$TEST_OUTPUT_EXTENSION";
    options="$individual_options $TEST_GLOBAL_OPTIONS";

    echo "Check file $input \c";
    if [ "$options" = " " ]; then
        echo "(no option), \c"
    else
        echo "(options $options), \c";
    fi;

    if [ "$TEST_RUN" = "1" ]; then
	generate_test=$srcdir/generate_test$EXEEXT
	test_run=$srcdir/test_run$EXEEXT
	good="$srcdir/$name.good.$TEST_OUTPUT_EXTENSION";

	echo "generating... \c";
	$cloog $options -q -callable 1 $input > test_test.c;
	$generate_test < $input > test_main.c;

	echo "compiling... \c";
# TODO: (nd Cedric) The following line is to deal with the (F*CKING !!!)
#       space in PACKAGE_STRING, introduced by AC_INIT and which, for
#       some reason, seems to be the source of a problem with my shell.
#       Maybe there is a better way to solve the problem...
	COMPILE=`echo $COMPILE | sed 's/\\\ /_SPACE_/g'`;
	$COMPILE -c test_test.c;
	$COMPILE -Dtest=good -c $good -o test_good.o;
	$LINK test_main.c test_test.o test_good.o > /dev/null;

	echo "comparing... \c";
	$test_run;
	result=$?;
	rm -f $test_run;
    else
	echo "generating... \c";
	$cloog $options -q $input > cloog_temp;
	diff -u -w --ignore-matching-lines='CLooG' cloog_temp $output;
	result=$?;
	rm -f cloog_temp;
    fi;

    if [ "$result" -ne "0" ]; then
        echo -e "\033[31mFAIL: $output is not the same\033[0m";
        failedtest=`expr $failedtest + 1`;
    else
        echo "PASS";
    fi;
done;

if [ $failedtest != 0 ]; then
    echo "\033[31m[CLooG] FAIL: $failedtest tests failed in $TEST_NAME\033[0m";
else
    echo "[CLooG] PASS: $TEST_NAME passed :-) !";
fi
exit $failedtest
