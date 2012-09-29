# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

aux_source_directory(. SOURCES)
add_executable(misc ${SOURCES})

target_link_libraries(misc metatest)
target_link_libraries(misc boost_unit_test_framework)

include(ExampleOutput)
example_text_output(misc misc)

