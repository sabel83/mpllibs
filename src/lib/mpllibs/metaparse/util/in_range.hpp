#ifndef MPLLIBS_UTIL_IN_RANGE_H
#define MPLLIBS_UTIL_IN_RANGE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream.hpp>

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

DEFINE_TO_STREAM_FOR_TEMPLATE(2, mpllibs::metaparse::util::in_range, "in_range")

#endif

