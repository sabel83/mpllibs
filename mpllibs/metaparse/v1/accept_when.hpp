#ifndef MPLLIBS_METAPARSE_V1_ACCEPT_WHEN_HPP
#define MPLLIBS_METAPARSE_V1_ACCEPT_WHEN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/get_result.hpp>
#include <mpllibs/metaparse/v1/fail.hpp>
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
      template <class P, class Pred, class Msg>
      struct accept_when
      {
      private:
        struct unchecked
        {
          template <class S, class Pos>
          struct apply :
            boost::mpl::apply_wrap2<
              typename boost::mpl::if_<
                typename boost::mpl::apply<
                  Pred,
                  typename get_result<boost::mpl::apply<P, S, Pos> >::type
                >::type,
                P,
                fail<Msg>
              >::type,
              S,
              Pos
            >
          {};
        };
      public:
        typedef accept_when type;
        
        template <class S, class Pos>
        struct apply :
          boost::mpl::apply<
            typename boost::mpl::if_<
              is_error<boost::mpl::apply<P, S, Pos> >,
              P,
              unchecked
            >::type,
            S,
            Pos
          >
        {};
      };
    }
  }
}

#endif

