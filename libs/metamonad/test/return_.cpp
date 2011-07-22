// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/identity.hpp>

#include "common.hpp"

using boost::mpl::identity;
using boost::mpl::equal_to;
using boost::mpl::apply_wrap1;

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::return_;
using mpllibs::metamonad::monad;

namespace
{
  MPLLIBS_DEFINE_TAG(test_tag)
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct monad<test_tag> : monad_defaults<test_tag>
    {
      struct return_
      {
        typedef return_ type;
        
        template <class T>
        struct apply : identity<int13> {};
      };
      
      // no bind is needed for this test
    };
  }
}

namespace
{
  const suite_path suite("return_");

  typedef
    equal_to<int13, apply_wrap1<monad<test_tag>::return_, int>::type>
    test_specialisation_is_called;  

  typedef
    equal_to<int13, return_<test_tag, int>::type>
    test_using_two_arguments;
}

MPLLIBS_ADD_TEST(suite, test_specialisation_is_called)
MPLLIBS_ADD_TEST(suite, test_using_two_arguments)


