# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

aux_source_directory(. SOURCES)
add_executable(metatest_example ${SOURCES})

target_link_libraries(metatest_example metatest)
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_link_libraries(metatest_example ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
else()
  target_link_libraries(metatest_example boost_unit_test_framework)
endif()

include(ExampleOutput)
example_text_output(metatest_example metatest_example)


