#ifndef MPLLIBS_METAMONAD_V1_IMPL_MERGE_MAP_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MERGE_MAP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/merge_map_value.hpp>
#include <mpllibs/metamonad/v1/is_exception.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>

#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        MPLLIBS_V1_METAFUNCTION(merge_map, (A)(B))
        ((
          if_<
            is_exception<A>,
            A,
            if_<
              is_exception<B>,
              B,
              boost::mpl::fold<
                typename B::type,
                typename A::type,
                merge_map_value
              >
            >
          >
        ));
      }
    }
  }
}

#endif

