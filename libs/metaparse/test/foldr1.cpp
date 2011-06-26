// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/foldr1.hpp>

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::foldr1;

using boost::mpl::list;
using boost::mpl::push_front;
using boost::mpl::_1;
using boost::mpl::_2;

namespace
{ 
  const suite_path suite("foldr1");
  
  template <class P>
  struct any1 : foldr1<P, list<>, push_front<_2, _1> > {};
}

#include "any1_test.hpp"  

