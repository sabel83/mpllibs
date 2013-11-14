# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

aux_source_directory(. SOURCES)
add_executable(metamonad_test ${SOURCES})

add_definitions(-DBUILD_MAJOR_VERSION=${MAJOR_VERSION})
add_definitions(-DBUILD_MINOR_VERSION=${MINOR_VERSION})
add_definitions(-DBUILD_PATCH_VERSION=${PATCH_VERSION})

if(NOT Boost_USE_STATIC_LIBS)
  add_definitions(-DBOOST_TEST_DYN_LINK)
endif()

target_link_libraries(metamonad_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(metamonad_unit_tests metamonad_test)

