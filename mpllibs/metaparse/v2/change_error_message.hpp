#ifndef MPLLIBS_METAPARSE_V2_CHANGE_ERROR_MESSAGE_HPP
#define MPLLIBS_METAPARSE_V2_CHANGE_ERROR_MESSAGE_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/is_error.hpp>
#include <mpllibs/metaparse/v2/reject.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class Msg>
      struct change_error_message
      {
        template <class S, class Pos>
        struct apply :
          boost::mpl::eval_if<
            typename is_error<boost::mpl::apply<P, S, Pos> >::type,
            reject<Msg, Pos>,
            boost::mpl::apply<P, S, Pos>
          >
        {};
        
        typedef change_error_message type;
      };
    }
  }
}

#endif

