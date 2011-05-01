// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::test_suite suite ("identity");

  using boost::is_same;
  using boost::mpl::_1;
  using boost::mpl::apply1;
  using boost::mpl::apply;
  using boost::mpl::identity;
  using boost::mpl::make_identity;

    typedef is_same< apply1<identity<>, char>::type, char > t1;
    typedef is_same< apply1<identity<_1>, int>::type, int > t2;

    typedef is_same<
          apply1< make_identity<>, char >::type
        , identity<char>
      > t3;

    typedef is_same<
          apply1< make_identity<_1>, int >::type
        , identity<int>
      > t4;
}

MPLLIBS_ADD_TEST (suite, t1)
MPLLIBS_ADD_TEST (suite, t2)
MPLLIBS_ADD_TEST (suite, t3)
MPLLIBS_ADD_TEST (suite, t4)

