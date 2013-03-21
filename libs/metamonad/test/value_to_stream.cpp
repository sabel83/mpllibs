// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/value_to_stream.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/assert.hpp>

#include <string>
#include <iostream>
#include <sstream>

using mpllibs::metamonad::tmp_value;

namespace
{
  struct with_const_value : tmp_value<with_const_value>
  {
    static const int value;
  };
  
  const int with_const_value::value = 1;

  struct with_enum_value : tmp_value<with_enum_value>
  {
    enum { value = 2 };
  };

  struct with_get_value : tmp_value<with_get_value>
  {
    static int get_value() { return 3; }
  };

  struct with_value_and_get_value : tmp_value<with_value_and_get_value>
  {
    static int get_value() { return 4; }
    enum { value = 5 };
  };

  struct without_value : tmp_value<without_value> {};

  template <class T>
  std::string to_string()
  {
    std::ostringstream s;
    mpllibs::metamonad::value_to_stream<T>::run(s);
    return s.str();
  }
}

BOOST_AUTO_TEST_CASE(test_value_to_stream)
{
  BOOST_CHECK_EQUAL("1", to_string<with_const_value>());
  BOOST_CHECK_EQUAL("2", to_string<with_enum_value>());
  BOOST_CHECK_EQUAL("3", to_string<with_get_value>());
  BOOST_CHECK_EQUAL("4", to_string<with_value_and_get_value>());
  BOOST_CHECK_EQUAL("???", to_string<without_value>());
}


