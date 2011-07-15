// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/either.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/not.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::left;
using mpllibs::metamonad::right;
using mpllibs::metamonad::get_data;
using mpllibs::metamonad::return_;
using mpllibs::metamonad::bind;
using mpllibs::metamonad::either_tag;

using boost::mpl::equal_to;
using boost::mpl::not_;
using boost::mpl::plus;
using boost::mpl::_1;
using boost::mpl::int_;

namespace
{
  const suite_path suite("either");
  
  typedef int_<2> int2;
  typedef int_<11> int11;
  typedef int_<13> int13;
  
  typedef right<int13> right13;
  typedef right<int11> right11;
  typedef left<int11> left11;
  
  typedef right<plus<_1, int2> > either_add_2;
  
  typedef equal_to<return_<either_tag, int13>, right13> test_return;

  typedef
    equal_to<bind<either_tag, right11, either_add_2>::type, right13>
    test_bind_with_right;

  typedef
    equal_to<bind<either_tag, left11, either_add_2>::type, left11>
    test_bind_with_left;
}

MPLLIBS_ADD_TEST(suite, test_return)
MPLLIBS_ADD_TEST(suite, test_bind_with_right)
MPLLIBS_ADD_TEST(suite, test_bind_with_left)


