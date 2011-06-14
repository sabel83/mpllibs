#    Copyright Abel Sinkovics (abel@sinkovics.hu) 2010-2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)


OUT_DIR = ..
TXT_FILES = $(wildcard *.txt)
HTML_FILES = $(addprefix $(OUT_DIR)/, $(TXT_FILES:.txt=.html))

all : html

html : $(HTML_FILES)

clean :
	-rm $(HTML_FILES)

$(HTML_FILES) : $(OUT_DIR)/%.html : %.txt 
	asciidoc -o $@ -b html4 $<
	sed --in-place 's/<head>/<head>\n<link rel="stylesheet" type="text\/css" href="style.css" \/> /' $@
	sed --in-place 's/<hr>//g' $@

