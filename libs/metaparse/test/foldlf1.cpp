// Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/foldlf1.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metaparse::foldlf1;

using boost::mpl::vector;
using boost::mpl::push_back;
using boost::mpl::_1;
using boost::mpl::_2;

namespace
{ 
  template <class P>
  struct anyf1 : foldlf1<P, vector<>, push_back<_1, _2> > {};
}

#define DEFINE_TEST_CASE BOOST_AUTO_TEST_CASE(test_foldlf1)

#include "anyf1_test.hpp"  

