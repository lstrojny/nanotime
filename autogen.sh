#!/bin/sh
glibtoolize --force --copy || libtoolize --force --copy
aclocal
automake --force-missing --add-missing --copy
autoconf
./configure
