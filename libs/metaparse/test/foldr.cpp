// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/foldr.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metaparse::foldr;

using boost::mpl::list;
using boost::mpl::push_front;
using boost::mpl::_1;
using boost::mpl::_2;
using boost::mpl::lambda;

namespace
{ 
  template <class P>
  struct any : foldr<P, list<>, lambda<push_front<_2, _1> >::type> {};
}

#define DEFINE_TEST_CASE BOOST_AUTO_TEST_CASE(test_foldr)

#include "any_test.hpp"  

