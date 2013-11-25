#ifndef MPLLIBS_METAMONAD_V1_IMPL_MAP_INSERT_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MAP_INSERT_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/instantiate.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/first.hpp>
#include <mpllibs/metamonad/v1/second.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/push_back.hpp>

#include <boost/preprocessor/cat.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        MPLLIBS_V1_METAFUNCTION(map_insert_impl, (P)(Pair))
        ((
          BOOST_PP_CAT(instantiate, BOOST_MPL_LIMIT_MAP_SIZE)<
            boost::mpl::map
          >::apply<
            typename if_<
              second<P>,
              boost::mpl::push_back<typename first<P>::type, Pair>,
              first<P>
            >::type
          >
        ));
      }
    }
  }
}

#endif

