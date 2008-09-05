#!/bin/sh
libtoolize -c --force
aclocal
autoheader
automake -a -c --foreign
autoconf
