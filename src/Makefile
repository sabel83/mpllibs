#    Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

MPLLIBS_ROOT = lib/mpllibs

# Make sure, that metatest is the first code dir
ALL_CODE_DIRS = $(filter-out $(MPLLIBS_ROOT)/Makefile,$(wildcard $(MPLLIBS_ROOT)/*))

CODE_DIRS = \
  lib/mpllibs/metatest \
  $(filter-out lib/mpllibs/metatest, $(ALL_CODE_DIRS)) \
  sample

DOC_DIRS = doc

main_target : all

build check :
	$(foreach l, $(CODE_DIRS), $(MAKE) -C $(l) $@ && ) true

html :
	$(foreach l, $(DOC_DIRS), $(MAKE) -C $(l) $@ && ) true

clean all :
	$(foreach l, $(DOC_DIRS), $(MAKE) -C $(l) $@ && ) true
	$(foreach l, $(CODE_DIRS), $(MAKE) -C $(l) $@ && ) true

check : build


