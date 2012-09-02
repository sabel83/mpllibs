// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/maybe.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/fail.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/not.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/list_c.hpp>

BOOST_AUTO_TEST_CASE(test_maybe)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::just;
  using mpllibs::metamonad::nothing;
  using mpllibs::metamonad::get_data;
  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::bind;
  using mpllibs::metamonad::maybe_tag;
  using mpllibs::metamonad::fail;
  
  using boost::mpl::equal_to;
  using boost::mpl::not_;
  using boost::mpl::plus;
  using boost::mpl::_1;
  using boost::mpl::list_c;

  typedef just<int13> just13;
  typedef just<int11> just11;
  
  typedef list_c<char, 'h', 'e', 'l', 'l', 'o'> s_hello;
  
  typedef just<plus<_1, int2> > maybe_add_2;
  
  meta_require<
    equal_to<return_<maybe_tag, int13>, just13>
  >(MPLLIBS_HERE, "test_return");

  meta_require<
    equal_to<bind<maybe_tag, just11, maybe_add_2>::type, just13>
  >(MPLLIBS_HERE, "test_bind_with_just");

  meta_require<
    equal_to<bind<maybe_tag, nothing, maybe_add_2>::type, nothing>
  >(MPLLIBS_HERE, "test_bind_with_nothing");

  meta_require<
    equal_to<
      bind<maybe_tag, fail<maybe_tag, s_hello>, maybe_add_2>::type,
      nothing
    >
  >(MPLLIBS_HERE, "test_fail");
}


