#ifndef MPLLIBS_METAPARSE_V1_IF__HPP
#define MPLLIBS_METAPARSE_V1_IF__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/return_.hpp>
#include <mpllibs/metaparse/v1/is_error.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class P, class T, class F>
      struct if_
      {
        typedef if_ type;
        
        template <class S, class Pos>
        struct apply :
          boost::mpl::apply_wrap2<
            return_<
              typename boost::mpl::if_<
                is_error<boost::mpl::apply<P, S, Pos> >,
                F,
                T
              >::type
            >,
            S,
            Pos
          >
        {};
      };
    }
  }
}

#endif

