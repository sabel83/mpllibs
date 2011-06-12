# Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

CODE_DIRS = $(foreach d, src test, $(wildcard $(d)) ) $(wildcard example/*)

recurse = $(foreach d, $(CODE_DIRS), $(MAKE) -C $(d) $(1) && ) true

build : ; $(call recurse, build)
.PHONY : build

check : ; $(MAKE) -C test check
.PHONY : check

clean : ; $(call recurse, clean)
.PHONY : clean

all : clean build check
.PHONY : all


