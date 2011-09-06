# Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

-include local.mk

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

WEBSITE_DIR = website
website : html
	mkdir -p $(WEBSITE_DIR)
	cp index.html style.css $(WEBSITE_DIR)
	$(foreach d, $(notdir $(LIBS)), mkdir -p $(WEBSITE_DIR)/$(d) && cp libs/$(d)/html/* $(WEBSITE_DIR)/$(d) && sed -i 's/\/\.\.\/\.\.\/index\.html/\/index.html/g' $(WEBSITE_DIR)/$(d)/index.html &&) true
	sed -i 's/\"libs\//"/g' $(WEBSITE_DIR)/index.html
	sed -i 's/\/html\//\//g' $(WEBSITE_DIR)/index.html

