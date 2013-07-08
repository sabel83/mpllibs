# Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

include(Pandoc)

macro(generate_documentation LIB_NAME OUT_DIR_NAME)
  file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.md)
  pandoc_build(${LIB_NAME}_documentation
    ${CMAKE_CURRENT_SOURCE_DIR}/../${OUT_DIR_NAME}
    ${SOURCES}
  )
endmacro(generate_documentation)


