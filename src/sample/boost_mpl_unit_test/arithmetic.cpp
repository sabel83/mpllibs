// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/int.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("arithmetic");

  using namespace boost::mpl;

  typedef int_<0> _0;
  typedef int_<1> _1;
  typedef int_<3> _3;
  typedef int_<10> _10;
  typedef int_<-10> _neg10;

  typedef equal_to<_10, plus<_0, _10> > test_0_plus_10;
  typedef equal_to<_10, plus<_10, _0> > test_10_plus_0;

  typedef equal_to<_neg10, minus<_0,_10> > test_0_minus_10;
  typedef equal_to<_10, minus<_10,_0> > test_10_minus_0;

  typedef equal_to<_10, times<_1,_10> > test_1_times_10;
  typedef equal_to<_10, times<_10,_1> > test_10_times_1;
  typedef equal_to<_10, multiplies<_1,_10> > test_1_mult_10;
  typedef equal_to<_10, multiplies<_10,_1> > test_10_mult_1;

  typedef equal_to<_10, divides<_10,_1> > test_10_div_1;

  typedef equal_to<_0, modulus<_10,_1> > test_10_mod_1;
  typedef equal_to<_1, modulus<_10,_3> > test_10_mod_3;

#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
  typedef equal_to<int_<-1>, minus<_10,_1,_10> > test_10_minus_1_minus_10;
  typedef equal_to<int_<21>, plus<_10,_1,_10> > test_10_plus_1_plus_10;
  typedef equal_to<_1, divides<_10,_1,_10> > test_10_div_1_div_10;
#endif

  typedef equal_to<_neg10, negate<_10> > test_negate_10;
}

MPLLIBS_ADD_TEST(suite, test_0_plus_10)
MPLLIBS_ADD_TEST(suite, test_10_plus_0)
MPLLIBS_ADD_TEST(suite, test_0_minus_10)
MPLLIBS_ADD_TEST(suite, test_10_minus_0)
MPLLIBS_ADD_TEST(suite, test_1_times_10)
MPLLIBS_ADD_TEST(suite, test_10_times_1)
MPLLIBS_ADD_TEST(suite, test_1_mult_10)
MPLLIBS_ADD_TEST(suite, test_10_mult_1)
MPLLIBS_ADD_TEST(suite, test_10_div_1)
MPLLIBS_ADD_TEST(suite, test_10_mod_1)
MPLLIBS_ADD_TEST(suite, test_10_mod_3)
#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
MPLLIBS_ADD_TEST(suite, test_10_minus_1_minus_10)
MPLLIBS_ADD_TEST(suite, test_10_plus_1_plus_10)
MPLLIBS_ADD_TEST(suite, test_10_div_1_div_10)
#endif
MPLLIBS_ADD_TEST(suite, test_negate_10)

