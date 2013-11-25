#ifndef MPLLIBS_METAPARSE_V1_UTIL_IS_LETTER_HPP
#define MPLLIBS_METAPARSE_V1_UTIL_IS_LETTER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/util/is_ucase_letter.hpp>
#include <mpllibs/metaparse/v1/util/is_lcase_letter.hpp>

#include <boost/mpl/or.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace util
      {
        template <class C = boost::mpl::na>
        struct is_letter :
          boost::mpl::or_<
            typename is_lcase_letter<C>::type,
            typename is_ucase_letter<C>::type
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

