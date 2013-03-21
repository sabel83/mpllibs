#ifndef MPLLIBS_METAPARSE_UTIL_IN_RANGE_HPP
#define MPLLIBS_METAPARSE_UTIL_IN_RANGE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/quote.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      template <class LowerBound, class UpperBound>
      struct in_range
      {
        typedef in_range type;
      
        template <class Item>
        struct apply :
          boost::mpl::and_<
            boost::mpl::less_equal<LowerBound, Item>,
            boost::mpl::less_equal<Item, UpperBound>
          >
        {};
      };
    }
  }
}

#endif

