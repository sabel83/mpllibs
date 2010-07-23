#    Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

MPLLIBS_ROOT = lib/mpllibs

CODE_DIRS = $(filter-out $(MPLLIBS_ROOT)/Makefile,$(wildcard $(MPLLIBS_ROOT)/*))
DOC_DIRS = doc

clean all : recurse_code recurse_doc

check : recurse_code
html : recurse_doc

recurse_code :
	$(foreach l, $(CODE_DIRS), $(MAKE) -C $(l) $(MAKECMDGOALS) && ) true

recurse_doc :
	$(foreach l, $(DOC_DIRS), $(MAKE) -C $(l) $(MAKECMDGOALS) && ) true

