// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monoid.hpp>

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/to_stream.hpp>

#include "common.hpp"

#include <boost/mpl/lambda.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::monoid;
using mpllibs::metamonad::monoid_defaults;

using boost::mpl::equal_to;
using boost::mpl::lambda;
using boost::mpl::_1;
using boost::mpl::_2;
using boost::mpl::list_c;
using boost::mpl::plus;
using boost::mpl::times;
using boost::mpl::apply;
using boost::mpl::int_;

namespace
{
  const suite_path suite("monoid");
  
  MPLLIBS_DEFINE_TAG(plus_tag)
  MPLLIBS_DEFINE_TAG(mult_tag)
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct monoid<plus_tag> : monoid_defaults<plus_tag>
    {
      typedef int0 empty;
      typedef lambda<plus<_1, _2> > append;
    };

    template <>
    struct monoid<mult_tag> : monoid_defaults<mult_tag>
    {
      typedef int1 empty;
      typedef lambda<times<_1, _2> > append;
    };
  }
}

namespace
{  
  typedef
    equal_to<
      int13,
      apply<monoid<plus_tag>::concat, list_c<int, 1, 2, 3, 4, 3> >::type
    >
    test_concat_plus;

  typedef
    equal_to<
      int_<72>,
      apply<monoid<mult_tag>::concat, list_c<int, 1, 2, 3, 4, 3> >::type
    >
    test_concat_mult;
}

MPLLIBS_ADD_TEST(suite, test_concat_plus)
MPLLIBS_ADD_TEST(suite, test_concat_mult)




