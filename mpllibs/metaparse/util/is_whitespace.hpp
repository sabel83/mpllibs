#ifndef MPLLIBS_METAPARSE_UTIL_IS_WHITESPACE_HPP
#define MPLLIBS_METAPARSE_UTIL_IS_WHITESPACE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/or.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/char.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      struct is_whitespace
      {
        typedef is_whitespace type;
        
        template <class C>
        struct apply :
          boost::mpl::or_<
            boost::mpl::equal_to<C, boost::mpl::char_<' '> >,
            boost::mpl::equal_to<C, boost::mpl::char_<'\r'> >,
            boost::mpl::equal_to<C, boost::mpl::char_<'\n'> >,
            boost::mpl::equal_to<C, boost::mpl::char_<'\t'> >
          >
        {};
      };
    }
  }
}

#endif

