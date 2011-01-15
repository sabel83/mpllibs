# Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

THIS_MAKEFILES_DIR = $(lastword $(dir $(MAKEFILE_LIST)))

INCLUDES += ../..

LIB = libmetatest.a

build : $(LIB)

include $(THIS_MAKEFILES_DIR)/common.mk

$(LIB) : $(OBJECTS)
	ar rcs $@ $^

check : ; $(MAKE) -C test $(MAKECMDGOALS)

clean :
	-rm $(LIB)
	$(MAKE) -C test $(MAKECMDGOALS)

