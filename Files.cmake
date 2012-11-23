# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

macro(dir PATH)
  get_filename_component(P ${PATH} ABSOLUTE)
  add_custom_command(
    OUTPUT ${P}
    COMMAND mkdir -p ${P}
  )
endmacro(dir)

macro(copy_file SRC_PATH FILENAME DST_PATH)
  get_filename_component(P ${DST_PATH} ABSOLUTE)
  set(DST ${P}/${FILENAME})
  set(SRC ${SRC_PATH}/${FILENAME})

  add_custom_command(
    OUTPUT ${DST}
    COMMAND cp ${SRC} ${DST}
    DEPENDS ${SRC} ${P} ${ARGN}
  )
endmacro(copy_file)

