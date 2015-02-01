#ifndef MPLLIBS_METAPARSE_V2_IMPL_SEQUENCE_IMPL_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_SEQUENCE_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/impl/apply_parser.hpp>
#include <mpllibs/metaparse/v2/accept.hpp>

#include <boost/mpl/deque.hpp>
#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        template <class Ps, class S, class Pos>
        struct sequence_impl :
          boost::mpl::fold<
            Ps,
            accept<boost::mpl::deque<>, S, Pos>,
            apply_parser
          >
        {};
      }
    }
  }
}

#endif

