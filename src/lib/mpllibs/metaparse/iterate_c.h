#ifndef MPLLIBS_PARSER_ITERATE_C_H
#define MPLLIBS_PARSER_ITERATE_C_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/get_remaining.h>
#include <mpllibs/metaparse/get_position.h>

#include <boost/mpl/deque.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/push_back.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <int N, class P, class Accum>
      struct iterate_impl;
      
      template <int N, class P, class Accum, class S, class Pos>
      struct iterate_impl_unchecked :
        boost::mpl::apply<
          iterate_impl<
            N - 1,
            P,
            typename boost::mpl::push_back<
              Accum,
              typename mpllibs::metaparse::get_result<
                boost::mpl::apply<P, S, Pos>
              >::type
            >::type
          >,
          typename mpllibs::metaparse::get_remaining<
            boost::mpl::apply<P, S, Pos>
          >::type,
          typename mpllibs::metaparse::get_position<
            boost::mpl::apply<P, S, Pos>
          >::type
        >
      {};

      template <int N, class P, class Accum>
      struct iterate_impl
      {
        template <class S, class Pos>
        struct apply :
          boost::mpl::eval_if<
            typename mpllibs::metaparse::is_error<
              boost::mpl::apply<P, S, Pos>
            >::type,
            boost::mpl::apply<P, S, Pos>,
            iterate_impl_unchecked<N, P, Accum, S, Pos>
          >
        {};
      };
      
      template <class P, class Accum>
      struct iterate_impl<0, P, Accum> : mpllibs::metaparse::return_<Accum> {};
    }

    template <class P, int N>
    struct iterate_c :
      mpllibs::metaparse::impl::iterate_impl<N, P, boost::mpl::deque<> >
    {};
  }
}

#endif
