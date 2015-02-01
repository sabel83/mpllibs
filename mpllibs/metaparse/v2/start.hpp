#ifndef MPLLIBS_METAPARSE_V2_START_HPP
#define MPLLIBS_METAPARSE_V2_START_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/source_position.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/char.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      typedef
        source_position<
          boost::mpl::int_<1>,
          boost::mpl::int_<1>,
          boost::mpl::char_<0>
        >
        start;
    }
  }
}

#endif

