#ifndef MPLLIBS_UTIL_CONS_SEQ_H
#define MPLLIBS_UTIL_CONS_SEQ_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/push_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      struct cons_seq
      {
        template <class seq>
        struct apply :
          boost::mpl::push_front<
            typename boost::mpl::back<typename seq::type>::type,
            typename boost::mpl::front<typename seq::type>::type
          >
        {};
      };
    }
  }
}

#endif

