#ifndef MPLLIBS_METAPARSE_V1_ANY_HPP
#define MPLLIBS_METAPARSE_V1_ANY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/foldr.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/lambda.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class P>
      struct any :
        foldr<
          P,
          boost::mpl::vector<>,
          typename boost::mpl::lambda<
            boost::mpl::push_front<boost::mpl::_2, boost::mpl::_1>
          >::type
        >
      {};
    }
  }
}

#endif

