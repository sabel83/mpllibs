#ifndef MPLLIBS_METAPARSE_ITERATE_HPP
#define MPLLIBS_METAPARSE_ITERATE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/iterate_c.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class N>
    struct iterate : iterate_c<P, N::type::value> {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, mpllibs::metaparse::iterate, "iterate")

#endif

