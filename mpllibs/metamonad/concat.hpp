#ifndef MPLLIBS_METAMONAD_CONCAT_HPP
#define MPLLIBS_METAMONAD_CONCAT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/insert_range.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(concat, (a)(b))
    ((
      boost::mpl::insert_range<a, typename boost::mpl::end<a>::type, b>
    ));
  }
}

#endif

