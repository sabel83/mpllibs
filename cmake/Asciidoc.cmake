# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

find_program(A2X_EXECUTABLE a2x)

macro(asciidoc_build_impl A2X_ARGS TARGET_NAME OUTDIR)
  set(OUTFILES)
  foreach(IT ${ARGN})
    get_filename_component(FILENAME ${IT} NAME_WE)
    set(OUTFILE ${OUTDIR}/${FILENAME}.html)
    set(OUTFILES ${OUTFILES} ${OUTFILE})
    add_custom_command(
      OUTPUT ${OUTFILE}
      COMMAND ${A2X_EXECUTABLE} -f xhtml ${IT} --stylesheet style.css --destination-dir=${OUTDIR} ${A2X_ARGS}
      COMMAND sed --in-place 's/Fork me on github/<a href=\"https:\\/\\/github.com\\/sabel83\\/mpllibs\"><img style=\"position: absolute\; top: 0\; right: 0\; border: 0\;\" src=\"https:\\/\\/s3.amazonaws.com\\/github\\/ribbons\\/forkme_right_darkblue_121621.png\" alt=\"Fork me on GitHub\"><\\/a>/' ${OUTFILE}
      COMMAND sed --in-place 's/<hr \\/>//g' ${OUTFILE}
      DEPENDS ${IT}
    )
  endforeach(IT)
  add_custom_target(${TARGET_NAME} DEPENDS ${OUTFILES})
endmacro(asciidoc_build_impl)

macro(asciidoc_build_with_toc TARGET_NAME OUTDIR)
  asciidoc_build_impl("" ${TARGET_NAME} ${OUTDIR} ${ARGN})
endmacro(asciidoc_build_with_toc)

macro(asciidoc_build TARGET_NAME OUTDIR)
  asciidoc_build_impl("--xsltproc-opts=--param;--xsltproc-opts=generate.toc;--xsltproc-opts=nop" ${TARGET_NAME} ${OUTDIR} ${ARGN})
endmacro(asciidoc_build)

