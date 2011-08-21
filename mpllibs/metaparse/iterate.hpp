#ifndef MPLLIBS_METAPARSE_ITERATE_HPP
#define MPLLIBS_METAPARSE_ITERATE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/iterate_c.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class N>
    struct iterate : iterate_c<P, N::type::value>
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "iterate<";
          mpllibs::metatest::to_stream_argument_list<P, N>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

