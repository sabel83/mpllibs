# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

aux_source_directory(. SOURCES)
add_executable(boost_test_assertion ${SOURCES})

target_link_libraries(boost_test_assertion metatest)
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_link_libraries(boost_test_assertion ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
else()
  target_link_libraries(boost_test_assertion boost_unit_test_framework)
endif()

include(ExampleOutput)
example_text_output(boost_test_assertion boost_test_assertion)


