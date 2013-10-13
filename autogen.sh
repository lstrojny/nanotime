#!/bin/sh
glibtoolize --force --copy || libtoolize --force --copy
aclocal
autoheader
automake --force-missing --add-missing --copy
autoconf
./configure
