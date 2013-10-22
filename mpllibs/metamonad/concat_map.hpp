#ifndef MPLLIBS_METAMONAD_CONCAT_MAP_HPP
#define MPLLIBS_METAMONAD_CONCAT_MAP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/concat.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/transform_view.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(concat_map, (l)(f))
    ((
      boost::mpl::fold<
        boost::mpl::transform_view<l, f>,
        boost::mpl::list<>,
        concat<>
      >
    ));
  }
}

#endif

