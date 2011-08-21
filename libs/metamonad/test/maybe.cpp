// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/maybe.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/fail.hpp>

#include <mpllibs/metatest/test.hpp>

#include "common.hpp"

#include <boost/mpl/not.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/list_c.hpp>

using mpllibs::metatest::suite_path;

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

namespace
{
  const suite_path suite("maybe");
  
  typedef just<int13> just13;
  typedef just<int11> just11;
  
  typedef list_c<char, 'h', 'e', 'l', 'l', 'o'> s_hello;
  
  typedef just<plus<_1, int2> > maybe_add_2;
  
  typedef equal_to<return_<maybe_tag, int13>, just13> test_return;

  typedef
    equal_to<bind<maybe_tag, just11, maybe_add_2>::type, just13>
    test_bind_with_just;

  typedef
    equal_to<bind<maybe_tag, nothing, maybe_add_2>::type, nothing>
    test_bind_with_nothing;

  typedef
    equal_to<
      bind<maybe_tag, fail<maybe_tag, s_hello>, maybe_add_2>::type,
      nothing
    >
    test_fail;
}

MPLLIBS_ADD_TEST(suite, test_return)
MPLLIBS_ADD_TEST(suite, test_bind_with_just)
MPLLIBS_ADD_TEST(suite, test_bind_with_nothing)
MPLLIBS_ADD_TEST(suite, test_fail)


