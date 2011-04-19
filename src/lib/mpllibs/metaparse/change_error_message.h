#ifndef MPLLIBS_PARSER_CHANGE_ERROR_MESSAGE_H
#define MPLLIBS_PARSER_CHANGE_ERROR_MESSAGE_H

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/fail.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class msg>
    struct change_error_message
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::apply<
          typename boost::mpl::if_<
            mpllibs::metaparse::is_error<boost::mpl::apply<p, s, pos> >,
            mpllibs::metaparse::fail<msg>,
            p
          >::type,
          s,
          pos
        >
      {};
    };
  }
}

#endif

