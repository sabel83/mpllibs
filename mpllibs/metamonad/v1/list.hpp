#ifndef MPLLIBS_METAMONAD_V1_LIST_HPP
#define MPLLIBS_METAMONAD_V1_LIST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/list_tag.hpp>
#include <mpllibs/metamonad/v1/concat.hpp>
#include <mpllibs/metamonad/v1/tmp_tag.hpp>
#include <mpllibs/metamonad/v1/monad.hpp>
#include <mpllibs/metamonad/v1/monad_plus.hpp>
#include <mpllibs/metamonad/v1/monoid.hpp>
#include <mpllibs/metamonad/v1/lambda.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/concat_map.hpp>

#include <boost/mpl/list.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <>
      struct monad<list_tag> : monad_defaults<list_tag>
      {
        typedef lambda_c<t, boost::mpl::list<t> > return_;
        typedef concat_map<> bind;
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
}

#endif

