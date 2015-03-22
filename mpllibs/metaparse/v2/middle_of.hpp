#ifndef MPLLIBS_METAPARSE_V2_KEEP_MIDDLE_HPP
#define MPLLIBS_METAPARSE_V2_KEEP_MIDDLE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/nth_of.hpp>
#include <mpllibs/metaparse/v2/transform_error_message.hpp>
#include <mpllibs/metaparse/v2/get_col.hpp>
#include <mpllibs/metaparse/v2/get_line.hpp>

#include <mpllibs/metaparse/v2/error/unpaired.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P1, class P2, class P3>
      struct middle_of
      {
        typedef middle_of type;

        template <class S, class Pos>
        struct apply :
          nth_of_c<
            1,
            P1,
            P2,
            transform_error_message<
              P3,
              error::unpaired<
                get_line<Pos>::type::value,
                get_col<Pos>::type::value
              >
            >
          >::template apply<S, Pos>
        {};
      };
    }
  }
}

#endif

