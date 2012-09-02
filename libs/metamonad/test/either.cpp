// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/either.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/fail.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/not.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metamonad::left;
using mpllibs::metamonad::right;
using mpllibs::metamonad::get_data;
using mpllibs::metamonad::return_;
using mpllibs::metamonad::bind;
using mpllibs::metamonad::either_tag;
using mpllibs::metamonad::fail;

using boost::mpl::equal_to;
using boost::mpl::not_;
using boost::mpl::plus;
using boost::mpl::_1;
using boost::mpl::int_;

namespace
{
  typedef int_<2> int2;
  typedef int_<11> int11;
  typedef int_<13> int13;
  
  typedef right<int13> right13;
  typedef right<int11> right11;
  typedef left<int11> left11;
  
  typedef right<plus<_1, int2> > either_add_2;
  
  typedef equal_to<return_<either_tag, int13>, right13> test_return;
}

BOOST_AUTO_TEST_CASE(test_either)
{
  using mpllibs::metatest::meta_require;

  meta_require<
    equal_to<bind<either_tag, right11, either_add_2>::type, right13>
  >(MPLLIBS_HERE, "test_bind_with_right");

  meta_require<
    equal_to<bind<either_tag, left11, either_add_2>::type, left11>
  >(MPLLIBS_HERE, "test_bind_with_left");

  meta_require<
    equal_to<
      bind<either_tag, fail<either_tag, int13>, either_add_2>::type,
      left<int13>
    >
  >(MPLLIBS_HERE, "test_fail");
}


