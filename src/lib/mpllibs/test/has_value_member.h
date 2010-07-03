#ifndef MPLLIBS_TEST_HAS_VALUE_MEMBER_H
#define MPLLIBS_TEST_HAS_VALUE_MEMBER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/yes.h>
#include <mpllibs/test/no.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace test
  {
    // Based on C++ Template Metaprogramming, chapter 9.10
    template <class F, class ValueType>
    struct has_value_member
    {
      struct type
      {
        template <ValueType value_>
        struct value_wrapper;
        
        template <class T>
        static
          typename
            boost::mpl::apply<
              boost::mpl::always<mpllibs::test::yes>,
              mpllibs::test::has_value_member<
                F,
                ValueType
              >::type::value_wrapper<T::value>
            >::type
          tester(T *t);
      
        template <class T>
        static mpllibs::test::no tester(...);
      
        static const bool
          value =
            sizeof(
              mpllibs::test::has_value_member<F, ValueType>::type::tester<F>(0)
            )
            == sizeof(mpllibs::test::yes);
      };
    };
  }
}

#endif

