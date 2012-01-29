# Copyright Abel Sinkovics (abel@sinkovics.hu)  2010-2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

SOURCE_ROOT = ../../..

INCLUDES += $(SOURCE_ROOT)
BIN_DIR = $(SOURCE_ROOT)/bin/tests/metamonad

BIN = $(BIN_DIR)/test

LIBS += metatest
LIB_DIRS += $(SOURCE_ROOT)/bin/libs/metatest

check : $(BIN)
	$(BIN)

build : $(BIN)

SOURCES += $(wildcard *.cpp)
OBJECTS += $(addprefix $(BIN_DIR)/, $(SOURCES:.cpp=.o))
DEPS += $(OBJECTS:.o=.d)

# We need it for dependency file generation
CXXFLAGS += -MMD
CXXFLAGS += -MP

CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -pedantic

$(OBJECTS) : $(BIN_DIR)/%.o : %.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(foreach i,$(INCLUDES), -I$(i) ) -o $@ $<
	sed -i -e '1s,\($*\)\.o[ :]*,\1.o $*.d: ,' $(BIN_DIR)/$*.d

clean : clean_objects clean_deps

clean_objects:
	-rm $(OBJECTS)

clean_deps:
	-rm $(DEPS)

all : clean
	$(MAKE) build

-include $(DEPS)

$(BIN) : $(OBJECTS)
	$(CXX) -o $(BIN) $(OBJECTS) $(foreach l,$(LIBS), -l$(l) ) $(foreach l,$(LIB_DIRS), -L$(l) )

clean :
	-rm $(LIB)

