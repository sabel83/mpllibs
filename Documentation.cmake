# Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

include(Asciidoc)

macro(generate_documentation LIB_NAME)
  set(DOCS_WITH_TOC ${ARGN})
  foreach(F ${DOCS_WITH_TOC})
    set(SOURCES_TOC ${SOURCES_TOC} ${CMAKE_CURRENT_SOURCE_DIR}/${F})
  endforeach(F)
  file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.txt)
  list(REMOVE_ITEM SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${SOURCES_TOC}
  )
  asciidoc_build(${LIB_NAME}_documentation_no_toc
    ${CMAKE_CURRENT_SOURCE_DIR}/../html
    ${SOURCES}
  )
  asciidoc_build_with_toc(${LIB_NAME}_documentation_toc
    ${CMAKE_CURRENT_SOURCE_DIR}/../html
    ${SOURCES_TOC}
  )
  add_custom_target(${LIB_NAME}_documentation
    DEPENDS ${LIB_NAME}_documentation_no_toc ${LIB_NAME}_documentation_toc
  )
endmacro(generate_documentation)


