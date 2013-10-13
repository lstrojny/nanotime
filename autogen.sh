#!/bin/sh
glibtoolize --force || libtoolize --force
aclocal
autoheader
automake --force-missing --add-missing -i
autoconf
./configure
