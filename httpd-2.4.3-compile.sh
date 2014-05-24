#!/bin/sh
#Download httpd-deps from apache site
#Download pcre from pcre site
tar -xf pcre-8.30.tar.gz
cd pcre-8.30
make
make install
cd ..
mv pcre-8.30 httpd-2.4.3/srclib/pcre
tar -xf httpd-deps*.tar.gz
cd httpd-2.4.3/srclib/apr-utils
make
./configure --prefix=/usr/local/apache2 --with-mpm=worker --enable-so --enable-deflate --enable-ssl
make
make install
