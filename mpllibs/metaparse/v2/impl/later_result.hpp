#ifndef MPLLIBS_METAPARSE_V2_IMPL_LATER_RESULT_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_LATER_RESULT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/get_position.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/less.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        template <class R1, class R2>
        struct later_result :
          boost::mpl::if_<
            typename boost::mpl::less<
              typename get_position<R1>::type,
              typename get_position<R2>::type
            >::type,
            R2,
            R1
          >
        {};
      }
    }
  }
}

#endif

