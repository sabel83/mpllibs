# Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

SAMPLES = $(filter-out Makefile, $(wildcard *))

recursiveRule = $(1) :; $(foreach d,$(SAMPLES), $(MAKE) -C $(d) $(1) && ) true

$(call recursiveRule, build)
$(call recursiveRule, clean)
$(call recursiveRule, all)

check :; echo Nothing to test for the samples

