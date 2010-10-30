#ifndef MPLLIBS_UTIL_PAIR_H
#define MPLLIBS_UTIL_PAIR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/pair.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/equal_to.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      struct pair_tag {};
    
      template <class first, class second>
      struct pair : boost::mpl::pair<first, second>
      {
        typedef pair_tag tag;
      
        typedef pair<first, second> type;
      };
    }
  }
}

namespace boost
{
  namespace mpl
  {
    template <>
    struct
      equal_to_impl<
        mpllibs::metaparse::util::pair_tag,
        mpllibs::metaparse::util::pair_tag
      >
    {
      template <class a, class b>
      struct apply :
        boost::mpl::and_<
          typename boost::mpl::equal_to<
            typename a::first,
            typename b::first
          >::type,
          typename boost::mpl::equal_to<
            typename a::second,
            typename b::second
          >::type
        >
      {};
    };
  }
}

#endif

