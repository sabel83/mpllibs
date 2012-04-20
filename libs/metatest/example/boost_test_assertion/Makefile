# Copyright Abel Sinkovics (abel@sinkovics.hu)  2010-2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

LIB_ROOT = ../..
SOURCE_ROOT = $(LIB_ROOT)/../..

NAME = boost_test_assertion

INCLUDES += $(SOURCE_ROOT)
BIN_DIR = $(SOURCE_ROOT)/bin/example/metatest/$(NAME)
OUTPUT = output.txt

BIN = $(BIN_DIR)/$(NAME)

run : $(OUTPUT)

$(OUTPUT) : $(BIN)
	-$(BIN) --log_sink=$@

build : $(BIN)

SOURCES += $(wildcard *.cpp)
OBJECTS += $(addprefix $(BIN_DIR)/, $(SOURCES:.cpp=.o))
DEPS += $(OBJECTS:.o=.d)

LIBS += boost_unit_test_framework

# We need it for dependency file generation
CXXFLAGS += -MMD
CXXFLAGS += -MP

CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -pedantic
CXXFLAGS += -Wno-multichar
CXXFLAGS += -Wno-four-char-constants

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
	-rm $(BIN)

html : $(LIB_ROOT)/html/example_$(NAME).html

$(LIB_ROOT)/html/example_$(NAME).html : $(OUTPUT)
	-mkdir -p $(LIB_ROOT)/html
	echo '<html><head><title>$(NAME)</title></head><body style="font-family: Monaco, Courier; font-weight: 900;">' > $@
	cat $(OUTPUT) | sed 's/\&/\&amp;/g' | sed 's/ /\&nbsp;/g' | sed 's/</\&lt;/g' | sed 's/>/\&gt;/g' | sed 's/$$/<br\/>/' >> $@
	echo '</body></html>' >> $@


