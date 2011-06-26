// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/foldl.hpp>

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::foldl;

using boost::mpl::vector;
using boost::mpl::push_back;
using boost::mpl::_1;
using boost::mpl::_2;

namespace
{ 
  const suite_path suite("foldl");
  
  template <class P>
  struct any : foldl<P, vector<>, push_back<_2, _1> > {};
}

#include "any_test.hpp"  

