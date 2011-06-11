#ifndef MPLLIBS_METAPARSE_UTIL_IS_WHITESPACE_HPP
#define MPLLIBS_METAPARSE_UTIL_IS_WHITESPACE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/or.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      struct is_whitespace
      {
        template <class C>
        struct apply :
          boost::mpl::or_<
            boost::mpl::equal_to<C, boost::mpl::integral_c<char, ' '> >,
            boost::mpl::equal_to<C, boost::mpl::integral_c<char, '\r'> >,
            boost::mpl::equal_to<C, boost::mpl::integral_c<char, '\n'> >,
            boost::mpl::equal_to<C, boost::mpl::integral_c<char, '\t'> >
          >
        {};
      };
    }
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metaparse::util::is_whitespace,
  "is_whitespace"
)

#endif

