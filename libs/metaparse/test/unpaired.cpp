// Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/error/unpaired.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
  struct some_tmp_value
  {
    typedef some_tmp_value type;
  };
}

BOOST_AUTO_TEST_CASE(test_unpaired)
{
  using mpllibs::metaparse::error::unpaired;
  
  using boost::is_same;

  // test_unpaired_currying
  BOOST_MPL_ASSERT((
    is_same<
      unpaired<1, 2, some_tmp_value>,
      unpaired<1, 2>::apply<some_tmp_value>::type
    >
  ));
}

