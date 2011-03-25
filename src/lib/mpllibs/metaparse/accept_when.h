#ifndef MPLLIBS_PARSER_ACCEPT_WHEN_H
#define MPLLIBS_PARSER_ACCEPT_WHEN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/fail.h>
#include <mpllibs/metaparse/is_error.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class pred, class msg>
    struct accept_when_unchecked
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::apply<
          typename boost::mpl::if_<
            typename boost::mpl::apply<
              pred,
              typename mpllibs::metaparse::get_result<
                boost::mpl::apply<p, s, pos>
              >::type
            >::type,
            p,
            mpllibs::metaparse::fail<msg>
          >::type,
          s,
          pos
        >
      {};
    };
  
    template <class p, class pred, class msg>
    struct accept_when
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::apply<
          typename boost::mpl::if_<
            mpllibs::metaparse::is_error<boost::mpl::apply<p, s, pos> >,
            p,
            mpllibs::metaparse::accept_when_unchecked<p, pred, msg>
          >::type,
          s,
          pos
        >
      {};
    };
  }
}

#endif

