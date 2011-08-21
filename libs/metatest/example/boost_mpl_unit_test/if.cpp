// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("if");

  using namespace boost::mpl;

  typedef equal_to<
        if_<true_, int_<1>, int_<2> >::type
      , int_<1>
      > test_if_true;

  typedef equal_to<
        if_c<true, int_<1>, int_<2> >::type
      , int_<1>
      > test_if_c_true;

  typedef equal_to<
        if_<false_, int_<1>, int_<2> >::type
      , int_<2>
      > test_if_false;

  typedef equal_to<
        if_c<false, int_<1>, int_<2> >::type
      , int_<2>
      > test_if_c_false;
}

MPLLIBS_ADD_TEST (suite, test_if_true)
MPLLIBS_ADD_TEST (suite, test_if_c_true)
MPLLIBS_ADD_TEST (suite, test_if_false)
MPLLIBS_ADD_TEST (suite, test_if_c_false)

