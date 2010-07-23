#    Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

DOC_ROOT = $(DOC_SRC_ROOT)/../../doc

OUT_DIR = $(DOC_ROOT)/$(subst $(realpath $(DOC_SRC_ROOT)),,$(realpath $(CURDIR)))
TXT_FILES = $(wildcard *.txt)
HTML_FILES = $(addprefix $(OUT_DIR)/, $(TXT_FILES:.txt=.html))

CSS_FILES = $(OUT_DIR)/style.css

all : html

html : $(HTML_FILES) $(CSS_FILES)

clean :
	-rm $(HTML_FILES) $(CSS_FILES)
	-rmdir $(OUT_DIR)

$(HTML_FILES) : $(OUT_DIR)/%.html : %.txt $(OUT_DIR)
	asciidoc -o $@ -b html4 -a stylesheet=$(realpath $(DOC_SRC_ROOT)/handbookish.css) $<
	sed --in-place 's/<head>/<head>\n<link rel="stylesheet" type="text\/css" href="style.css" \/> /' $@
	sed --in-place 's/<hr>//g' $@

$(CSS_FILES) : $(OUT_DIR)/%.css : $(DOC_SRC_ROOT)/%.css $(OUT_DIR)
	cp $< $@

$(OUT_DIR) :
	mkdir -p $(OUT_DIR)

# Recursion

html : recurse
clean : recurse
check : recurse

recurse :
	$(foreach d, $(SUBDIRS), $(MAKE) -C $(d) $(MAKECMDGOALS) && ) true

