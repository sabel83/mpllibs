# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

aux_source_directory(. SOURCES)
add_executable(metaparse_test ${SOURCES})

target_link_libraries(metaparse_test boost_unit_test_framework)

add_test(metaparse_unit_tests metaparse_test)

