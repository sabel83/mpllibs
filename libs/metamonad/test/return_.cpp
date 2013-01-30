// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include "common.hpp"

using mpllibs::metamonad::tmp_tag;

namespace
{
  struct test_tag : tmp_tag<test_tag> {};
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct monad<test_tag> : monad_defaults<test_tag>
    {
      typedef lambda_c<_, returns<int13> > return_;
      
      // no bind is needed for this test
    };
  }
}

BOOST_AUTO_TEST_CASE(test_return_)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::monad;

  using boost::mpl::apply_wrap1;
  using boost::mpl::equal_to;

  meta_require<
    equal_to<int13, apply_wrap1<monad<test_tag>::return_, int>::type>
  >(MPLLIBS_HERE, "test_specialisation_is_called"); 

  meta_require<
    equal_to<int13, return_<test_tag, int>::type>
  >(MPLLIBS_HERE, "test_using_two_arguments");
}


