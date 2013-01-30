#ifndef MPLLIBS_METAMONAD_TEST_IS_EMPTY_HPP
#define MPLLIBS_METAMONAD_TEST_IS_EMPTY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/is_exception.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/int.hpp>

MPLLIBS_METAFUNCTION(is_empty, (S))
((
  boost::mpl::and_<
    typename boost::mpl::not_<
      typename mpllibs::metamonad::is_exception<S>::type
    >::type,
    typename boost::mpl::equal_to<
      boost::mpl::int_<0>,
      typename boost::mpl::distance<
        typename boost::mpl::begin<S>::type,
        typename boost::mpl::end<S>::type
      >::type
    >::type
  >
));

#endif

