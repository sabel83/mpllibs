#ifndef MPLLIBS_TEST_HAS_VALUE_H
#define MPLLIBS_TEST_HAS_VALUE_H

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
    struct has_value
    {
      struct type
      {
        template <ValueType value_>
        struct value_wrapper;
        
        // It needs an extra int argument to remove ambiguity between
        // this version and the one with ...
        template <class T>
        static
          typename
            boost::mpl::apply<
              boost::mpl::always<mpllibs::test::yes>,
              typename mpllibs::test::has_value<
                F,
                ValueType
              >::type::template value_wrapper<T::value>
            >::type
          tester(T*, int);
      
        // I have to pass a T* argument to make Visual C++ accept it
        template <class T>
        static mpllibs::test::no tester(T*, ...);
      
        static const bool
          value =
            sizeof(
              mpllibs::test::has_value<F, ValueType>::type::tester(
                static_cast<F*>(0),
                13
              )
            )
            == sizeof(mpllibs::test::yes);
      };
    };
  }
}

#endif

