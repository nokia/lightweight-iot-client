# Makefile for tinydtls
#
# Copyright (c) 2011, 2012, 2013, 2014, 2015 Olaf Bergmann (TZI) and others.
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v1.0
# and Eclipse Distribution License v. 1.0 which accompanies this distribution.
#
# The Eclipse Public License is available at http://www.eclipse.org/legal/epl-v10.html
# and the Eclipse Distribution License is available at 
# http://www.eclipse.org/org/documents/edl-v10.php.
#
# Contributors:
#    Olaf Bergmann  - initial API and implementation
#    Hauke Mehrtens - memory optimization, ECC integration
#

# the library's version
VERSION:=0.8.6

# tools

SHELL = /bin/sh
MKDIR = mkdir
CC=gcc

abs_builddir = /home/pi/impact/wakaama-wm/examples/shared/tinydtls/ecc
top_builddir = ..
top_srcdir:= ..

ECC_SOURCES:= ecc.c testecc.c testfield.c test_helper.c
ECC_HEADERS:= ecc.h test_helper.h
FILES:=Makefile.in Makefile.contiki $(ECC_SOURCES) $(ECC_HEADERS) 
DISTDIR=$(top_builddir)/tinydtls-0.8.6

ifeq ("@WITH_CONTIKI@", "1")
include Makefile.contiki
else
ECC_OBJECTS:= $(patsubst %.c, %.o, $(ECC_SOURCES)) ecc_test.o
PROGRAMS:= testecc testfield
CPPFLAGS= -DDTLSv12 -DWITH_SHA256
CFLAGS=-Wall -std=c99 -pedantic -g -O2 -DTEST_INCLUDE
LDLIBS=

.PHONY: all dirs clean install distclean .gitignore doc

.SUFFIXES:
.SUFFIXES:      .c .o

all: $(PROGRAMS)

ecc_test.o:	ecc.c ecc.h
	$(CC) $(CFLAGS) $(CPPFLAGS)  -c -o $@ $<

testecc: ecc_test.o test_helper.o

testfield: ecc_test.o test_helper.o

check:	
	echo DISTDIR: $(DISTDIR)
	echo top_builddir: $(top_builddir)

clean:
	@rm -f $(PROGRAMS) main.o $(LIB) $(ECC_OBJECTS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean ; \
	done

distclean:	clean
	@rm -rf $(DISTDIR)
	@rm -f *~ $(DISTDIR).tar.gz
endif # WITH_CONTIKI

dist:	$(FILES)
	test -d $(DISTDIR)/ecc || mkdir $(DISTDIR)/ecc
	cp -p $(FILES) $(DISTDIR)/ecc

install:	$(ECC_HEADERS)
	test -d $(includedir)/ecc || mkdir -p $(includedir)/ecc
	$(install) $(ECC_HEADERS) $(includedir)/ecc

.gitignore:
	echo "core\n*~\n*.[oa]\n*.gz\n*.cap\n$(PROGRAM)\n$(DISTDIR)\n.gitignore" >$@
