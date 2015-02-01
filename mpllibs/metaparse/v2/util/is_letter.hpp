#ifndef MPLLIBS_METAPARSE_V2_UTIL_IS_LETTER_HPP
#define MPLLIBS_METAPARSE_V2_UTIL_IS_LETTER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/util/is_ucase_letter.hpp>
#include <mpllibs/metaparse/v2/util/is_lcase_letter.hpp>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/vector.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace util
      {
        template <class C = boost::mpl::na>
        struct is_letter :
          boost::mpl::bool_<
            is_lcase_letter<C>::type::value || is_ucase_letter<C>::type::value
          >
        {};

        template <>
        struct is_letter<boost::mpl::na>
        {
          typedef is_letter type;
          
          template <class C = boost::mpl::na>
          struct apply : is_letter<C> {};
        };
      }
    }
  }
}

#endif

