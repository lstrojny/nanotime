#!/bin/sh
glibtoolize --force
aclocal
autoheader
automake --force-missing --add-missing -i
autoconf
./configure
