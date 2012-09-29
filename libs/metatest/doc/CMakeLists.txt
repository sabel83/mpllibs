# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

include(Asciidoc)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.txt)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt)
asciidoc_build(metatest_documentation ${CMAKE_CURRENT_SOURCE_DIR}/../html ${SOURCES})

