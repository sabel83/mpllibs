# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

aux_source_directory(. SOURCES)
add_executable(safe_printf_test ${SOURCES})

target_link_libraries(safe_printf_test boost_unit_test_framework)

add_test(safe_printf_unit_tests safe_printf_test)

