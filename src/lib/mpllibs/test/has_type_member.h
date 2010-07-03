#ifndef MPLLIBS_TEST_HAS_TYPE_MEMBER_H
#define MPLLIBS_TEST_HAS_TYPE_MEMBER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/yes.h>
#include <mpllibs/test/no.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/always.hpp>

namespace mpllibs
{
  namespace test
  {
    // Based on C++ Template Metaprogramming, chapter 9.10
    template <class F>
    struct has_type_member
    {
      struct type
      {
        template <class T>
        static
          typename
            boost::mpl::apply<
              boost::mpl::always<mpllibs::test::yes>,
              typename T::type
            >::type
          tester(T *t);
      
        template <class T>
        static mpllibs::test::no tester(...);
      
        static const bool
          value =
            sizeof(mpllibs::test::has_type_member<F>::type::tester<F>(0))
            == sizeof(mpllibs::test::yes);
      };
    };
  }
}

#endif

