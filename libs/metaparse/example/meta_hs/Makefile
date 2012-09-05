# Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

SOURCE_ROOT = ../../../..

NAME1 = meta_hs_in_haskell
NAME2 = meta_hs_handcrafted

INCLUDES += .
INCLUDES += $(SOURCE_ROOT)
BIN_DIR = $(SOURCE_ROOT)/bin/example/metaparse/meta_hs

BIN1 = $(BIN_DIR)/$(NAME1)
BIN2 = $(BIN_DIR)/$(NAME2)

run : $(BIN1) $(BIN2)
	-$(BIN1)
	-$(BIN2)

build : $(BIN1) $(BIN2)

SOURCES1 += main_in_haskell.cpp
OBJECTS1 += $(addprefix $(BIN_DIR)/, $(SOURCES1:.cpp=.o))
OBJECTS += $(OBJECTS1)

SOURCES2 += main_handcrafted.cpp
OBJECTS2 += $(addprefix $(BIN_DIR)/, $(SOURCES2:.cpp=.o))
OBJECTS += $(OBJECTS2)

DEPS += $(OBJECTS:.o=.d)

# We need it for dependency file generation
CXXFLAGS += -MMD
CXXFLAGS += -MP

CXXFLAGS += -Wall
CXXFLAGS += -pedantic
CXXFLAGS += -Wno-multichar

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
	+$(MAKE) build

-include $(DEPS)

$(BIN1) : $(OBJECTS1)
	$(CXX) -o $(BIN1) $(OBJECTS1) $(foreach l,$(LIBS), -l$(l) ) $(foreach l,$(LIB_DIRS), -L$(l) )

$(BIN2) : $(OBJECTS2)
	$(CXX) -o $(BIN2) $(OBJECTS2) $(foreach l,$(LIBS), -l$(l) ) $(foreach l,$(LIB_DIRS), -L$(l) )

clean :
	-rm $(BIN1) $(BIN2) $(OBJECTS) $(DEPS)

