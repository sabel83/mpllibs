// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("eval_if");

  using namespace boost::mpl;
  using boost::is_same;

  typedef is_same<
        eval_if< true_, identity<char>, identity<long> >::type
      , char
    > t1;

  typedef is_same<
        eval_if_c< true, identity<char>, identity<long> >::type
      , char
    > t2;

  typedef is_same<
        eval_if< false_, identity<char>, identity<long> >::type
      , long
    > t3;

  typedef is_same<
        eval_if_c< false, identity<char>, identity<long> >::type
      , long
    > t4;
}

MPLLIBS_ADD_TEST (suite, t1)
MPLLIBS_ADD_TEST (suite, t2)
MPLLIBS_ADD_TEST (suite, t3)
MPLLIBS_ADD_TEST (suite, t4)

