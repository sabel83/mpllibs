#ifndef MPLLIBS_METAPARSE_UTIL_DIGIT_TO_INT_HPP
#define MPLLIBS_METAPARSE_UTIL_DIGIT_TO_INT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/int.hpp>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      namespace impl
      {
        struct invalid_digit {};
    
        template <char C>
        struct digit_to_int : invalid_digit {};
      }

      struct digit_to_int
      {
        template <class D>
        struct apply :
          mpllibs::metaparse::util::impl::digit_to_int<D::type::value>
        {};
      };
    
      namespace impl
      {
        #ifdef MPLLIBS_UTIL_DIGIT_TO_INT_IMPL
          #error MPLLIBS_UTIL_DIGIT_TO_INT_IMPL is defined
        #endif
        #define MPLLIBS_UTIL_DIGIT_TO_INT_IMPL(c, n) \
          template <> struct digit_to_int<c> \
          { \
            typedef boost::mpl::int_<n> type; \
          }
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('0', 0);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('1', 1);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('2', 2);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('3', 3);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('4', 4);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('5', 5);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('6', 6);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('7', 7);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('8', 8);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('9', 9);
        #undef MPLLIBS_UTIL_DIGIT_TO_INT_IMPL
      }
    }
  }
}

#endif

