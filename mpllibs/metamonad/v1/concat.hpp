#ifndef MPLLIBS_METAMONAD_V1_CONCAT_HPP
#define MPLLIBS_METAMONAD_V1_CONCAT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/concat.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/insert_range.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(concat, (A)(B))
      ((
        boost::mpl::insert_range<A, typename boost::mpl::end<A>::type, B>
      ));
    }
  }
}

#endif

