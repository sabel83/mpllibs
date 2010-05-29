#    Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

MPLLIBS_ROOT = lib/mpllibs

MPLLIBS = $(filter-out $(MPLLIBS_ROOT)/Makefile,$(wildcard $(MPLLIBS_ROOT)/*))

check :
	$(foreach l, $(MPLLIBS), $(MAKE) -C $(l) check && ) true


