#ifndef MPLLIBS_PARSER_FIRST_OF_H
#define MPLLIBS_PARSER_FIRST_OF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.h>

namespace mpllibs
{
  namespace metaparse
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        SEQUENCE_MAX_ARGUMENT,
        class P,
        mpllibs::metaparse::impl::sequence_no_argument
      )
    >
    struct first_of :
      nth_of_c<0, BOOST_PP_ENUM_PARAMS(SEQUENCE_MAX_ARGUMENT, P)>
    {};
  }
}

#endif

