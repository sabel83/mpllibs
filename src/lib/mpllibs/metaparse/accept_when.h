#ifndef MPLLIBS_PARSER_ACCEPT_WHEN_H
#define MPLLIBS_PARSER_ACCEPT_WHEN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/unless_error.h>

#include <mpllibs/metaparse/util/compose.h>
#include <mpllibs/metaparse/util/lazy_eval_if.h>
#include <mpllibs/metaparse/util/lazy_equal_to.h>

#include <mpllibs/metaparse/get_result.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/quote.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class pred, class msg>
    struct accept_when
    {
      template <class s, class pos>
      struct apply :
        mpllibs::metaparse::util::unless_error<
          boost::mpl::apply<p, s, pos>,
          
          mpllibs::metaparse::util::lazy_eval_if<
            boost::mpl::apply<
              mpllibs::metaparse::util::compose<
                pred,
                boost::mpl::quote1<mpllibs::metaparse::get_result>
              >,
              typename boost::mpl::apply<p, s, pos>::type
            >,
            boost::mpl::apply<p, s, pos>,
            mpllibs::metaparse::error<msg, pos>
          >
        >
      {};
    };
  }
}

#endif

