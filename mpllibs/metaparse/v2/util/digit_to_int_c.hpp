#ifndef MPLLIBS_METAPARSE_V2_UTIL_DIGIT_TO_INT_C_HPP
#define MPLLIBS_METAPARSE_V2_UTIL_DIGIT_TO_INT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/error/digit_expected.hpp>
#include <mpllibs/metamonad/exception.hpp>

#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace util
      {
        template <char C>
        struct digit_to_int_c : metamonad::exception<error::digit_expected> {};

        template <> struct digit_to_int_c<'0'> : boost::mpl::int_<0> {};
        template <> struct digit_to_int_c<'1'> : boost::mpl::int_<1> {};
        template <> struct digit_to_int_c<'2'> : boost::mpl::int_<2> {};
        template <> struct digit_to_int_c<'3'> : boost::mpl::int_<3> {};
        template <> struct digit_to_int_c<'4'> : boost::mpl::int_<4> {};
        template <> struct digit_to_int_c<'5'> : boost::mpl::int_<5> {};
        template <> struct digit_to_int_c<'6'> : boost::mpl::int_<6> {};
        template <> struct digit_to_int_c<'7'> : boost::mpl::int_<7> {};
        template <> struct digit_to_int_c<'8'> : boost::mpl::int_<8> {};
        template <> struct digit_to_int_c<'9'> : boost::mpl::int_<9> {};
      }
    }
  }
}

#endif

