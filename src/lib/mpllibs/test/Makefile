# Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

SELF_TEST_DEFINE = MPLLIBS_TEST_SELF_TEST


HEADERS = $(wildcard *.h)
OBJECTS = $(HEADERS:.h=.o)

check : $(OBJECTS)
	rm $(OBJECTS)

$(OBJECTS) : %.o : %.h
	g++ -Wall -ansi -Werror $< -o $@ -I../.. -D$(SELF_TEST_DEFINE)
	rm $@
	g++ -Wall -ansi -Werror $< -o $@ -I../..

clean :
	-rm $(OBJECTS)

all : clean
	$(MAKE)

