# Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

EXECUTABLE = sample

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

build : $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	g++ $< -o $(EXECUTABLE)

$(OBJECTS): %.o : %.cpp
	g++ -Wall -Werror -ansi -pedantic -I../../lib $< -c -o $@

clean :
	-rm $(EXECUTABLE) $(OBJECTS)

all : clean
	$(MAKE) build


