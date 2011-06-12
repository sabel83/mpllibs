// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("always");

  using namespace boost::mpl;

  typedef always<true_> always_true;
  typedef always<int_<10> > always_10;

  typedef apply1<always_true, false_> test_apply_f;
  typedef apply2<always_true, false_, false_> test_apply_f_f;
  typedef apply3<always_true, false_, false_, false_> test_apply_f_f_f;

  typedef apply1<always_10, int_<0> >::type test_apply_0;
  typedef apply2<always_10, int_<0>, int_<0> >::type test_apply_0_0;
  typedef apply3<always_10, int_<0>, int_<0>, int_<0> >::type test_apply_0_0_0;
}

MPLLIBS_ADD_TEST(suite, test_apply_f)
MPLLIBS_ADD_TEST(suite, test_apply_f_f)
MPLLIBS_ADD_TEST(suite, test_apply_f_f_f)

MPLLIBS_ADD_TEST(suite, test_apply_0)
MPLLIBS_ADD_TEST(suite, test_apply_0_0)
MPLLIBS_ADD_TEST(suite, test_apply_0_0_0)

