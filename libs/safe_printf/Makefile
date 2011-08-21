# Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

CODE_DIRS = $(foreach d, src test, $(wildcard $(d)) ) $(wildcard example/*)

recurse = $(foreach d, $(1), $(MAKE) -C $(d) $(2) && ) true

build : ; $(call recurse, $(CODE_DIRS), build)
.PHONY : build

check : ; $(call recurse, test, check)
.PHONY : check

clean : ; $(call recurse, $(CODE_DIRS) doc, clean)
.PHONY : clean

html : ; $(call recurse, doc, html)
.PHONY : html

all : clean build check html
.PHONY : all


