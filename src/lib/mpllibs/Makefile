#    Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

LIBRARIES = $(filter-out Makefile,$(wildcard *))

test :
	$(foreach l,$(LIBRARIES), $(MAKE) -C $(l) test && ) true



