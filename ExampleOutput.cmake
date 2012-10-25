# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

macro(example_output EXAMPLE_NAME)
  if(NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(BINARY ${EXAMPLE_NAME})
    set(HTML ${CMAKE_CURRENT_SOURCE_DIR}/../../html/example_${EXAMPLE_NAME}.html)
    set(CMD ${CMAKE_CURRENT_BINARY_DIR}/${BINARY})
    add_custom_command(
      OUTPUT ${HTML}
      COMMAND ${CMD} > ${HTML}
      DEPENDS ${CMD}
    )
    add_custom_target(example_${EXAMPLE_NAME}_output DEPENDS ${HTML})
  endif()
endmacro(example_output)

macro(example_text_output EXAMPLE_NAME)
  if(NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(BINARY ${EXAMPLE_NAME})
    set(HTML ${CMAKE_CURRENT_SOURCE_DIR}/../../html/example_${EXAMPLE_NAME}.html)
    set(CMD ${CMAKE_CURRENT_BINARY_DIR}/${BINARY})
    add_custom_command(
      OUTPUT ${HTML}
      COMMAND echo '<html><head><title>${EXAMPLE_NAME}</title></head><body style="font-family: Monaco, Courier; font-weight: 900;">' > ${HTML}
      COMMAND ${CMD} | sed 's/\\&/\\&amp;/g' | sed 's/ /\\&nbsp;/g' | sed 's/</\\&lt;/g' | sed 's/>/\\&gt;/g' | sed 's/$$/<br\\/>/' >> ${HTML}
      COMMAND echo '</body></html>' >> ${HTML}
      DEPENDS ${CMD}
    )
    add_custom_target(example_${EXAMPLE_NAME}_output DEPENDS ${HTML})
  endif()
endmacro(example_text_output)


