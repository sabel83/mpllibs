#ifndef MPLLIBS_METAPARSE_UTIL_CONS_SEQ_HPP
#define MPLLIBS_METAPARSE_UTIL_CONS_SEQ_HPP

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
        typedef cons_seq type;
        
        template <class Seq>
        struct apply :
          boost::mpl::push_front<
            typename boost::mpl::back<typename Seq::type>::type,
            typename boost::mpl::front<typename Seq::type>::type
          >
        {};
      };
    }
  }
}

#endif

