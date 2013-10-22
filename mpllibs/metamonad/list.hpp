#ifndef MPLLIBS_METAMONAD_LIST_HPP
#define MPLLIBS_METAMONAD_LIST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/concat.hpp>
#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monad_plus.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/concat_map.hpp>

#include <boost/mpl/list.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct list_tag : tmp_tag<list_tag> {};
    
    template <>
    struct monad<list_tag> : monad_defaults<list_tag>
    {
      typedef lambda_c<t, boost::mpl::list<t> > return_;
      typedef lambda_c<a, f, concat_map<a, f> > bind;
    };
    
    template <>
    struct monoid<list_tag> : monoid_defaults<list_tag>
    {
      typedef boost::mpl::list<> mempty;
      typedef concat<> mappend;
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

