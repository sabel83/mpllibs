// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "min.hpp"

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include <iostream>

using mpllibs::metamonad::tmp_tag;
using mpllibs::metamonad::tmp_value;

namespace
{
  struct test_class_tag : tmp_tag<test_class_tag> {};
  struct test_class : tmp_value<test_class, test_class_tag> {};
}

int main()
{
  using mpllibs::metamonad::exception;

  using boost::mpl::int_;
  using boost::mpl::equal_to;

  std::cout
    << "min<11, 13> = " << min<int_<11>, int_<13> >::type::value
    << std::endl
    << "equal_to<exception, min<test_class, test_class>> = "
    <<
      (equal_to<
        exception<non_comparable>,
        min<test_class, test_class>::type
      >::type::value ? "yes" : "no")
    << std::endl;
}



