# Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

EXECUTABLE ?= test

SOURCES += $(wildcard *.cpp)
OBJECTS += $(SOURCES:.cpp=.o)
DEPS += $(OBJECTS:.o=.d)

CXXFLAGS += -Wall
CXXFLAGS += -ansi
CXXFLAGS += -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra

CXXFLAGS += -Wabi
CXXFLAGS += -Wctor-dtor-privacy
CXXFLAGS += -Wold-style-cast
CXXFLAGS += -Woverloaded-virtual
CXXFLAGS += -Wsign-promo
CXXFLAGS += -Winit-self
CXXFLAGS += -Wmissing-include-dirs
CXXFLAGS += -Wswitch-enum
CXXFLAGS += -Wsync-nand
CXXFLAGS += -Wunused-parameter

CXXFLAGS += -Wformat
CXXFLAGS += -Wformat-y2k
CXXFLAGS += -Wformat-nonliteral
CXXFLAGS += -Wformat-security

CXXFLAGS += -Wfloat-equal
CXXFLAGS += -Wshadow
CXXFLAGS += -Wc++0x-compat
CXXFLAGS += -Wcast-align
CXXFLAGS += -Wconversion
CXXFLAGS += -Wsign-conversion
CXXFLAGS += -Wlogical-op
CXXFLAGS += -Wmissing-declarations

# We need it for dependency file generation
CXXFLAGS += -MMD
CXXFLAGS += -MP

check : $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)

$(OBJECTS) : %.o : %.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(foreach i,$(INCLUDES), -I$(i) ) -o $@ $<
	sed -i -e '1s,\($*\)\.o[ :]*,\1.o $*.d: ,' $*.d

clean :
	-rm $(OBJECTS) $(EXECUTABLE) $(DEPS)

all : clean
	$(MAKE)

-include $(DEPS)

