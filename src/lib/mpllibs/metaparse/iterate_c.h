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
      template <int n, class p, class accum>
      struct iterate_impl;
      
      template <int n, class p, class accum, class s, class pos>
      struct iterate_impl_unchecked :
        boost::mpl::apply<
          mpllibs::metaparse::impl::iterate_impl<
            n - 1,
            p,
            typename boost::mpl::push_back<
              accum,
              typename mpllibs::metaparse::get_result<
                boost::mpl::apply<p, s, pos>
              >::type
            >::type
          >,
          typename mpllibs::metaparse::get_remaining<
            boost::mpl::apply<p, s, pos>
          >::type,
          typename mpllibs::metaparse::get_position<
            boost::mpl::apply<p, s, pos>
          >::type
        >
      {};

      template <int n, class p, class accum>
      struct iterate_impl
      {
        template <class s, class pos>
        struct apply :
          boost::mpl::eval_if<
            typename mpllibs::metaparse::is_error<
              boost::mpl::apply<p, s, pos>
            >::type,
            boost::mpl::apply<p, s, pos>,
            mpllibs::metaparse::impl::iterate_impl_unchecked<n,p, accum, s, pos>
          >
        {};
      };
      
      template <class p, class accum>
      struct iterate_impl<0, p, accum> : mpllibs::metaparse::return_<accum> {};
    }

    template <class p, int n>
    struct iterate_c :
      mpllibs::metaparse::impl::iterate_impl<n, p, boost::mpl::deque<> >
    {};
  }
}

#endif

