# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

aux_source_directory(. SOURCES)
add_executable(exception_debug ${SOURCES})

target_link_libraries(exception_debug metatest)
target_link_libraries(exception_debug boost_unit_test_framework)

include(ExampleOutput)
example_text_output(exception_debug exception_debug)


