// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "min.h"

#include <mpllibs/metatest/test.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::error::exception;

using boost::mpl::int_;
using boost::mpl::equal_to;

namespace
{
  const test_suite suite("min");
  
  struct test_class
  {
    typedef test_class type;
  };
  
  typedef equal_to<int_<11>, min<int_<11>, int_<13> >::type> test_integers;

  typedef
    equal_to<exception<non_comparable>, min<test_class, test_class>::type>
    test_non_comparable;
}

MPLLIBS_ADD_TEST(suite, test_integers)
MPLLIBS_ADD_TEST(suite, test_non_comparable)



