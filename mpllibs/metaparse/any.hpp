#ifndef MPLLIBS_METAPARSE_ANY_HPP
#define MPLLIBS_METAPARSE_ANY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any_fold.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/quote.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct any :
      any_fold<
        P,
        boost::mpl::list<>,
        boost::mpl::quote2<boost::mpl::push_front>
      >
    {};
  }
}

#endif

