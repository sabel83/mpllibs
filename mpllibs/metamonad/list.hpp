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
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/transform_view.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct list_tag : tmp_tag<list_tag> {};
    
    namespace impl
    {
      MPLLIBS_METAFUNCTION_CLASS(join_lists, (State)(NewList))
      ((
        boost::mpl::insert_range<
          State,
          typename boost::mpl::end<State>::type,
          NewList
        >
      ));
    }

    template <>
    struct monad<list_tag> : monad_defaults<list_tag>
    {
      MPLLIBS_METAFUNCTION_CLASS(return_, (T)) ((boost::mpl::list<T>));
      
      MPLLIBS_METAFUNCTION_CLASS(bind, (A)(F))
      ((
        boost::mpl::fold<
          boost::mpl::transform_view<A, F>,
          boost::mpl::list<>,
          mpllibs::metamonad::impl::join_lists
        >
      ));
    };
    
    template <>
    struct monoid<list_tag> : monoid_defaults<list_tag>
    {
      typedef boost::mpl::list<> mempty;
      typedef
        typename boost::mpl::lambda<
          boost::mpl::apply_wrap2<
            mpllibs::metamonad::impl::join_lists,
            boost::mpl::_1,
            boost::mpl::_2
          >
        >::type
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

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::list_tag>::bind,
  "monad<list_tag>::bind"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::list_tag>::return_,
  "monad<list_tag>::return_"
)

#endif

