// Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/foldrf1.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metaparse::foldrf1;

using boost::mpl::list;
using boost::mpl::push_front;
using boost::mpl::_1;
using boost::mpl::_2;

namespace
{ 
  template <class P>
  struct anyf1 : foldrf1<P, list<>, push_front<_1, _2> > {};
}

#define DEFINE_TEST_CASE BOOST_AUTO_TEST_CASE(test_foldrf1)

#include "anyf1_test.hpp"  

