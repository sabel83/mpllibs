# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

aux_source_directory(. SOURCES)
add_executable(metatest_test ${SOURCES})

target_link_libraries(metatest_test metatest ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(metatest_unit_tests metatest_test)

