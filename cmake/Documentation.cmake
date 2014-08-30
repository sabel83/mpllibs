# Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

include(Pandoc)

find_program(RSVG_CONVERT rsvg-convert)

function(png_gen TARGET_NAME OUTDIR)
  set(OUTFILES)
  foreach(IT ${ARGN})
    get_filename_component(FILENAME ${IT} NAME_WE)
    set(OUTFILE ${OUTDIR}/${FILENAME}.png)
    set(OUTFILES ${OUTFILES} ${OUTFILE})
    add_custom_command(
      OUTPUT ${OUTFILE}
      COMMAND ${RSVG_CONVERT} -o ${OUTFILE} -f png ${IT}
      DEPENDS ${IT}
    )
  endforeach(IT)
  add_custom_target(${TARGET_NAME} DEPENDS ${OUTFILES})
endfunction(png_gen)

macro(generate_documentation LIB_NAME OUT_DIR_NAME)
  file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.md)
  file(GLOB SVGS ${CMAKE_CURRENT_SOURCE_DIR}/*.svg)

  pandoc_build(${LIB_NAME}_documentation
    ${CMAKE_CURRENT_SOURCE_DIR}/../${OUT_DIR_NAME}
    ${SOURCES}
  )
  png_gen(${LIB_NAME}_png
    ${CMAKE_CURRENT_SOURCE_DIR}/../${OUT_DIR_NAME}
    ${SVGS}
  )
  add_dependencies(${LIB_NAME}_documentation ${LIB_NAME}_png)
endmacro(generate_documentation)

