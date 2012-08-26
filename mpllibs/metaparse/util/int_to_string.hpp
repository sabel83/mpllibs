#ifndef MPLLIBS_METAPARSE_UTIL_INT_TO_STRING_HPP
#define MPLLIBS_METAPARSE_UTIL_INT_TO_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/int_to_digit.hpp>

#include <boost/mpl/string.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/char.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      namespace impl
      {
        template <unsigned int N>
        struct unsigned_int_to_string :
          boost::mpl::push_back<
            typename unsigned_int_to_string<N / 10>::type,
            mpllibs::metaparse::util::int_to_digit_c<N % 10>
          >
        {};

        template <>
        struct unsigned_int_to_string<0>
        {
          typedef boost::mpl::string<> type;
        };
      }

      struct int_to_string
      {
        typedef int_to_string type;

        // I wrap comparison expressions with bool_<> to make it work for
        // any value that behaves like an int
        template <class N>
        struct apply :
          boost::mpl::eval_if<
            boost::mpl::bool_<N::type::value == 0>,
            boost::mpl::string<'0'>,
            boost::mpl::eval_if<
              boost::mpl::bool_<(0 > N::type::value)>,
              boost::mpl::push_front<
                typename mpllibs::metaparse::util::impl::unsigned_int_to_string<
                  // I need it because push_front is not lazy
                  (0 > N::type::value ? -N::type::value : N::type::value)
                >::type,
                boost::mpl::char_<'-'>
              >,
              mpllibs::metaparse::util::impl::unsigned_int_to_string<
                N::type::value
              >
            >
          >
        {};
      };
    }
  }
}

#endif

