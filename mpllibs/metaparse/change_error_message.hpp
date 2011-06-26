#ifndef MPLLIBS_METAPARSE_CHANGE_ERROR_MESSAGE_HPP
#define MPLLIBS_METAPARSE_CHANGE_ERROR_MESSAGE_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class Msg>
    struct change_error_message
    {
      template <class S, class Pos>
      struct apply :
        boost::mpl::apply<
          typename boost::mpl::if_<
            is_error<boost::mpl::apply<P, S, Pos> >,
            fail<Msg>,
            P
          >::type,
          S,
          Pos
        >
      {};
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  mpllibs::metaparse::change_error_message,
  "change_error_message"
);

#endif

