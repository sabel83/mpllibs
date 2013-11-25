#ifndef MPLLIBS_METAMONAD_V1_IMPL_MAP_INSERT_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MAP_INSERT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/map_insert_impl.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/lazy.hpp>
#include <mpllibs/metamonad/v1/already_lazy.hpp>
#include <mpllibs/metamonad/v1/lazy_protect_args.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/first.hpp>
#include <mpllibs/metamonad/v1/second.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>
#include <mpllibs/metamonad/v1/is_same.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/push_back.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        // It is needed because
        //   boost::mpl::insert<
        //     boost::mpl::map<>,
        //     pair<boost::mpl::int_<1>, boost::mpl::int_<2>>
        //   >::type:type
        // is
        //   boost::mpl::map<>
        MPLLIBS_V1_METAFUNCTION(map_insert, (Map)(Pair))
        ((
          map_insert_impl<
            typename boost::mpl::fold<
              typename Map::type,
              pair<boost::mpl::vector<>, boost::mpl::true_>,
              lambda_c<s, c,
                if_<
                  second<s>,
                  if_<
                    is_same<first<c>, first<Pair> >,
                    pair<
                      lazy<
                        boost::mpl::push_back<
                          lazy_protect_args<first<s> >,
                          lazy_protect_args<Pair>
                        >
                      >,
                      boost::mpl::false_
                    >,
                    pair<
                      lazy<
                        boost::mpl::push_back<
                          lazy_protect_args<first<s> >,
                          already_lazy<c>
                        >
                      >,
                      boost::mpl::true_
                    >
                  >,
                  pair<
                    lazy<
                      boost::mpl::push_back<
                        lazy_protect_args<first<s> >,
                        already_lazy<c>
                      >
                    >,
                    boost::mpl::false_
                  >
                >
              >
            >::type,
            typename Pair::type
          >
        ));
      }
    }
  }
}

#endif

