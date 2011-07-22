// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>

#include <mpllibs/metatest/test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::return_;
using mpllibs::metamonad::bind;
using mpllibs::metamonad::list_tag;

using boost::mpl::equal;
using boost::mpl::list;

namespace
{
  const suite_path suite = suite_path("list")("monad");
  
  struct twice
  {
    template <class T>
    struct apply : list<T, T> {};
  };
  
  typedef equal<return_<list_tag, int13>, list<int13> > test_return;

  typedef
    equal<
      bind<list_tag, list<int13, int11>, twice>::type,
      list<int13, int13, int11, int11>
    >
    test_bind;
}

MPLLIBS_ADD_TEST(suite, test_return)
MPLLIBS_ADD_TEST(suite, test_bind)


