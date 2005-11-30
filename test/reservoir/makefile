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

CLOOGTEST_C =                          \
	cholesky2          \
	fusion1            \
	fusion2            \
	jacobi2            \
	jacobi3            \
	lim-lam1           \
	lim-lam2           \
	lim-lam3           \
	lim-lam4           \
	lim-lam5           \
	lim-lam6           \
	liu-zhuge1         \
	loechner3          \
	loechner4          \
	loechner5          \
	long               \
	mg-interp2         \
	mg-interp          \
	mg-psinv           \
	mg-resid           \
	mg-rprj3           \
	pingali1           \
	pingali2           \
	pingali3           \
	pingali4           \
	pingali5           \
	pingali6           \
	QR                 \
	tang-xue1          \
	two   


generate:
	@echo "             /*-----------------------------------------------*"
	@echo "              *                 Generate files                *"
	@echo "              *-----------------------------------------------*/"
	for x in $(CLOOGTEST_C) ; do \
		echo "Generate $$x.c" ; \
		../../obj_i686-pc-linux-gnu/cloog $$x.cloog -o $$x.c ; \
	done
