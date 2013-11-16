#ifndef MPLLIBS_SAFE_PRINTF_EXPECTED_TYPES_HPP
#define MPLLIBS_SAFE_PRINTF_EXPECTED_TYPES_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/impl/to_typelist.hpp>
#include <mpllibs/safe_printf/impl/parser.hpp>

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/concat_map.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    MPLLIBS_METAFUNCTION(expected_types, (S))
    ((
      metamonad::concat_map<impl::parser::apply<S>, impl::to_typelist<> >
    ));
  }
}

#endif

