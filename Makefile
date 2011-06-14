# Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

LIBS = $(wildcard libs/*)

recurse = $(foreach d, $(1), $(MAKE) -C $(d) $(2) && ) true

build :
	$(call recurse, libs/metatest, build)
	$(call recurse, $(LIBS), build)
.PHONY : build

check : build ; $(call recurse, $(LIBS), check)
.PHONY : check

clean : ; $(call recurse, $(LIBS) doc, clean)
.PHONY : clean

html : ; $(call recurse, $(LIBS) doc, html)
.PHONY : html

all : clean check html
.PHONY : all


