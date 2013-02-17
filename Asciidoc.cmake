# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

find_program(ASCIIDOC_EXECUTABLE asciidoc)

macro(asciidoc_build TARGET_NAME OUTDIR)
  set(OUTFILES)
  foreach(IT ${ARGN})
    get_filename_component(FILENAME ${IT} NAME_WE)
    set(OUTFILE ${OUTDIR}/${FILENAME}.html)
    set(OUTFILES ${OUTFILES} ${OUTFILE})
    add_custom_command(
      OUTPUT ${OUTFILE}
      COMMAND ${ASCIIDOC_EXECUTABLE} -o ${OUTFILE} -b html4 ${IT}
      COMMAND sed --in-place 's/Fork me on github/<a href=\"https:\\/\\/github.com\\/sabel83\\/mpllibs\"><img style=\"position: absolute\; top: 0\; right: 0\; border: 0\;\" src=\"https:\\/\\/s3.amazonaws.com\\/github\\/ribbons\\/forkme_right_darkblue_121621.png\" alt=\"Fork me on GitHub\"><\\/a>/' ${OUTFILE}
      COMMAND sed --in-place 's/<head>/<head>\\n<link rel="stylesheet" type="text\\/css" href="style.css" \\/> /' ${OUTFILE}
      COMMAND sed --in-place 's/<hr>//g' ${OUTFILE}
      DEPENDS ${IT}
    )
  endforeach(IT)
  add_custom_target(${TARGET_NAME} DEPENDS ${OUTFILES})
endmacro(asciidoc_build)

