// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <mpllibs/metamonad/mconcat.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/assert.hpp>


using boost::mpl::_1;
using boost::mpl::_2;
using boost::mpl::plus;
using boost::mpl::times;

using mpllibs::metamonad::tmp_tag;
using mpllibs::metamonad::lambda;

using namespace mpllibs::metamonad::name;

namespace
{
  struct plus_tag : tmp_tag<plus_tag> {};
  struct mult_tag : tmp_tag<mult_tag> {};
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct monoid<plus_tag> : monoid_defaults<plus_tag>
    {
      typedef int0 mempty;
      typedef lambda_c<a, b, plus<a, b> >::type mappend;
    };

    template <>
    struct monoid<mult_tag> : monoid_defaults<mult_tag>
    {
      typedef int1 mempty;
      typedef lambda_c<a, b, times<a, b> >::type mappend;
    };
  }
}

BOOST_AUTO_TEST_CASE(test_monoid)
{  
  using mpllibs::metamonad::mconcat;

  using boost::mpl::equal_to;
  using boost::mpl::list_c;
  using boost::mpl::int_;

  // test_concat_plus
  BOOST_MPL_ASSERT((
    equal_to<int13, mconcat<plus_tag, list_c<int, 1, 2, 3, 4, 3> >::type>
  ));

  // test_concat_mult
  BOOST_MPL_ASSERT((
    equal_to<int_<72>, mconcat<mult_tag, list_c<int, 1, 2, 3, 4, 3> >::type>
  ));
}



