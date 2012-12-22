// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>

#include <mpllibs/metamonad/mzero.hpp>
#include <mpllibs/metamonad/mplus.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/lambda.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>

using boost::mpl::list;

namespace
{
  MPLLIBS_METAFUNCTION_CLASS(twice, (T)) ((list<T, T>));
}

BOOST_AUTO_TEST_CASE(test_list_monad)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::bind;
  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::mplus;
  using mpllibs::metamonad::mzero;
  
  using boost::mpl::equal;
  
  meta_require<
    equal<return_<list_tag, int13>, list<int13> >
  >(MPLLIBS_HERE, "test_return");

  meta_require<
    equal<
      bind<list_tag, list<int13, int11>, twice>::type,
      list<int13, int13, int11, int11>
    >
  >(MPLLIBS_HERE, "test_bind");

  typedef mzero<list_tag>::type zero;

  meta_require<equal<zero, list<> > >(MPLLIBS_HERE, "test mzero");

  meta_require<
    equal<zero, mplus<list_tag, zero, zero>::type>
  >(MPLLIBS_HERE, "test mzero + mzero");

  meta_require<
    equal<list<int13>, mplus<list_tag, zero, list<int13> >::type>
  >(MPLLIBS_HERE, "test mzero + x");

  meta_require<
    equal<list<int13>, mplus<list_tag, list<int13>, zero>::type>
  >(MPLLIBS_HERE, "test x + mzero");

  meta_require<
    equal<list<int11, int13>, mplus<list_tag, list<int11>, list<int13> >::type>
  >(MPLLIBS_HERE, "test x + y");
}

