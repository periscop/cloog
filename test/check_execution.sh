#!/bin/sh
#
#   /**-------------------------------------------------------------------**
#    **                              CLooG                                **
#    **-------------------------------------------------------------------**
#    **                        check_execution.sh                         **
#    **-------------------------------------------------------------------**
#    **                First version: November 15th 2019                  **
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

# Refactor $SPECIAL_OPTIONS list to remove quotes and to replace spaces in
# individual tests with %, e.g., "'file1 -f -1' 'file2'" becomes
# "file1%-f%-1 file2".
special_refactored=`echo "$SPECIAL_OPTIONS" | \
                    sed "s/'  *'/#/g"       | \
                    sed 's/ /%/g'           | \
                    sed "s/#/ /g"           | \
                    sed "s/'//g"`

$CHECKER "EXECUTION C" "$CLOOGTEST_C" "" "cloog" "c" "execution"
failedtest=$?;

$CHECKER "EXECUTION SPECIAL" "$special_refactored" "" "cloog" "c" "execution"
failedtest=`expr $failedtest + $?`;

$CHECKER "EXECUTION SPECIAL -sh 1" "$special_refactored" "-sh 1" "cloog" "c" "execution"
failedtest=`expr $failedtest + $?`;

$CHECKER "EXECUTION STRIDED" "$CLOOGTEST_STRIDED" "-strides 1" "cloog" "c" "execution"
failedtest=`expr $failedtest + $?`;

if ! [ -z $CLOOGTEST_OPENSCOP ] ; then
$CHECKER "EXECUTION OPENSCOP" "$CLOOGTEST_OPENSCOP" "-openscop" "scop" "c" "execution"
failedtest=`expr $failedtest + $?`;
fi

exit $failedtest;
