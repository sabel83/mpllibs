#ifndef MPLLIBS_METAPARSE_V2_NEXT_LINE_HPP
#define MPLLIBS_METAPARSE_V2_NEXT_LINE_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/fwd/next_line.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class Ch>
      struct next_line :
        boost::mpl::apply_wrap2<
          next_line_impl<typename boost::mpl::tag<typename P::type>::type>,
          typename P::type,
          typename Ch::type
        >
      {};
    }
  }
}

#endif

