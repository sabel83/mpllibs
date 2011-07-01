#ifndef MPLLIBS_METATEST_HAS_VALUE_HPP
#define MPLLIBS_METATEST_HAS_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_argument_list.hpp>
#include <mpllibs/metatest/yes.hpp>
#include <mpllibs/metatest/no.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace metatest
  {
    // Based on C++ Template Metaprogramming, chapter 9.10
    template <class F, class ValueType>
    struct has_value
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "has_value<";
          to_stream_argument_list<F, ValueType>::run(o);
          return o << ">";
        }
      };

      struct type
      {
        template <ValueType Value_>
        struct value_wrapper;
        
        // It needs an extra int argument to remove ambiguity between
        // this version and the one with ...
        template <class T>
        static
          typename
            boost::mpl::apply_wrap1<
              boost::mpl::always<yes>,
              boost::mpl::integral_c<ValueType, T::value>
            >::type
          tester(T*, int);
      
        // I have to pass a T* argument to make Visual C++ accept it
        template <class T>
        static no tester(T*, ...);
      
        static const bool
          value =
            sizeof(
              has_value<F, ValueType>::type::tester(static_cast<F*>(0), 13)
            )
            == sizeof(yes);

        typedef typename has_value<F, ValueType>::to_stream to_stream;
      };
    };
  }
}

#endif

