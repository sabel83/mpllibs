#ifndef MPLLIBS_METAPARSE_V2_ENTIRE_INPUT_HPP
#define MPLLIBS_METAPARSE_V2_ENTIRE_INPUT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/first_of.hpp>
#include <mpllibs/metaparse/v2/empty.hpp>
#include <mpllibs/metaparse/v2/change_error_message.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class Msg = error::end_of_input_expected>
      struct entire_input :
        first_of<P, change_error_message<empty<void>, Msg> >
      {};

      template <class P>
      struct entire_input<P, error::end_of_input_expected> :
        first_of<P, empty<void> >
      {};
    }
  }
}

#endif

