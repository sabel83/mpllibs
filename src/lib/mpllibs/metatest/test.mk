# Copyright Abel Sinkovics (abel@sinkovics.hu)  2010-2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

THIS_MAKEFILES_DIR = $(lastword $(dir $(MAKEFILE_LIST)))
include $(THIS_MAKEFILES_DIR)/common.mk

EXECUTABLE ?= test
LIBS += metatest

check : $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS) $(foreach l,$(LIBS), -l$(l) ) $(foreach l,$(LIB_DIRS), -L$(l) )

clean :
	-rm $(EXECUTABLE)


