#!/bin/sh
autoreconf -i
if test -f isl/autogen.sh; then
	(cd isl; ./autogen.sh)
fi
