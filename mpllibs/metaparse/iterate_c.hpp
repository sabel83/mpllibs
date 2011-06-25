#ifndef MPLLIBS_METAPARSE_ITERATE_C_HPP
#define MPLLIBS_METAPARSE_ITERATE_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>

#include <boost/mpl/deque.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>
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
        boost::mpl::apply_wrap2<
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
        typedef iterate_impl type;
        
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

