#ifndef MPLLIBS_METAMONAD_TEST_SAME_MAP_HPP
#define MPLLIBS_METAMONAD_TEST_SAME_MAP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/first.hpp>
#include <mpllibs/metamonad/second.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/size.hpp>

// equal depends on the order of elements in the map
MPLLIBS_METAFUNCTION(same_map, (A)(B))
((
  boost::mpl::and_<
    typename
      boost::mpl::fold<
        A,
        boost::mpl::true_,
        mpllibs::metamonad::lambda_c<
          mpllibs::metamonad::s,
          mpllibs::metamonad::p,
          mpllibs::metamonad::lazy<
            boost::mpl::and_<
              mpllibs::metamonad::already_lazy<mpllibs::metamonad::s>,
              boost::is_same<
                boost::mpl::at<
                  mpllibs::metamonad::already_lazy<B>,
                  mpllibs::metamonad::lazy_protect_args<
                    mpllibs::metamonad::first<mpllibs::metamonad::p>
                  >
                >,
                mpllibs::metamonad::lazy_protect_args<
                  mpllibs::metamonad::second<mpllibs::metamonad::p>
                >
              >
            >
          >
        >
      >::type,
    typename boost::mpl::equal_to<
      typename boost::mpl::size<A>::type,
      typename boost::mpl::size<B>::type
    >::type
  >
));

MPLLIBS_METAFUNCTION(not_same_map, (A)(B))
((boost::mpl::not_<typename same_map<A, B>::type>));

#endif

