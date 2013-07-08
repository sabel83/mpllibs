# Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

find_program(PANDOC pandoc)
set(GEN_TOC ${PROJECT_SOURCE_DIR}/tools/gen_toc)

macro(pandoc_build TARGET_NAME OUTDIR)
  set(OUTFILES)
  foreach(IT ${ARGN})
    get_filename_component(FILENAME ${IT} NAME_WE)
    set(OUTFILE ${OUTDIR}/${FILENAME}.html)
    set(OUTFILES ${OUTFILES} ${OUTFILE})
    add_custom_command(
      OUTPUT ${OUTFILE}
      COMMAND 
        ${GEN_TOC} -i ${IT} -o - -t pandoc_html |
        ${PANDOC} --from markdown --to html -c style.css -o ${OUTFILE}
      DEPENDS ${IT}
    )
  endforeach(IT)
  add_custom_target(${TARGET_NAME} DEPENDS ${OUTFILES})
endmacro(pandoc_build)

