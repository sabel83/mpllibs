#ifndef MPLLIBS_METAMONAD_LIST_HPP
#define MPLLIBS_METAMONAD_LIST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monad_plus.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>

#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/transform_view.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct list_tag : tmp_tag<list_tag> {};
    
    namespace impl
    {
      typedef
        lambda_c<a, b,
          lazy<
            boost::mpl::insert_range<
              lazy_protect_args<a>,
              boost::mpl::end<lazy_protect_args<a> >,
              lazy_protect_args<b>
            >
          >
        >
        join_lists;
    }

    template <>
    struct monad<list_tag> : monad_defaults<list_tag>
    {
      typedef lambda_c<t, boost::mpl::list<t> > return_;
      
      typedef
        lambda_c<a, f,
          boost::mpl::fold<
            boost::mpl::transform_view<a, f>,
            boost::mpl::list<>,
            mpllibs::metamonad::impl::join_lists
          >
        >
        bind;
    };
    
    template <>
    struct monoid<list_tag> : monoid_defaults<list_tag>
    {
      typedef boost::mpl::list<> mempty;
      typedef
        lambda_c<a, b,
          boost::mpl::apply_wrap2<
            mpllibs::metamonad::impl::join_lists,
            a,
            b
          >
        >
        mappend;
    };

    template <>
    struct monad_plus<list_tag>
    {
      typedef monoid<list_tag>::mempty mzero;
      typedef monoid<list_tag>::mappend mplus;
    };
  }
}

#endif

