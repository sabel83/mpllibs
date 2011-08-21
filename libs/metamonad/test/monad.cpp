// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>

#include <boost/static_assert.hpp>

#include "common.hpp"

#include <iostream>

using boost::mpl::minus;
using boost::mpl::equal_to;

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::return_;
using mpllibs::metamonad::bind;

namespace
{
  const suite_path suite("monad");
  
  struct minus_2
  {
    typedef minus_2 type;
  
    template <class A>
    struct apply : right<typename minus<typename A::value, int2>::type> {};
    
    struct to_stream
    {
      static std::ostream& run(std::ostream& o)
      {
        return o << "minus_2";
      }
    };
  };

  typedef equal_to<right<int13>, return_<either, int13>::type> test_return;

  typedef
    equal_to<right<int11>, bind<either, right<int13>, minus_2>::type>
    test_bind_right;

  typedef
    equal_to<left<int13>, bind<either, left<int13>, minus_2>::type>
    test_bind_left;

  typedef
    equal_to<
      right<int9>,
      bind<either, bind<either, return_<either, int13>, minus_2>, minus_2>
    >
    test_multi_step_chain;
}

MPLLIBS_ADD_TEST(suite, test_return)
MPLLIBS_ADD_TEST(suite, test_bind_left)
MPLLIBS_ADD_TEST(suite, test_bind_right)
MPLLIBS_ADD_TEST(suite, test_multi_step_chain)



