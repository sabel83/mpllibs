#ifndef MPLLIBS_METAPARSE_UTIL_JOIN_STRING_HPP
#define MPLLIBS_METAPARSE_UTIL_JOIN_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/copy.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/empty_sequence.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/string.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      template <class C>
      struct join_string :
        boost::mpl::copy<
          typename boost::mpl::fold<
            C,
            boost::mpl::empty_sequence,
            typename boost::mpl::lambda<
              boost::mpl::joint_view<boost::mpl::_1, boost::mpl::_2>
            >::type
          >::type,
          boost::mpl::back_inserter<boost::mpl::string<> >
        >
      {};
    }
  }
}

#endif

