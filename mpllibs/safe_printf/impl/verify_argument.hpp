#ifndef MPLLIBS_SAFE_PRINTF_IMPL_VERIFY_ARGUMENT_HPP
#define MPLLIBS_SAFE_PRINTF_IMPL_VERIFY_ARGUMENT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/impl/verify_argument_impl.hpp>

#include <mpllibs/metamonad/unbox.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/or.hpp>

#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/at.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace impl
    {
      // This function is lazy
      template <class Expected, class Actual>
      struct verify_argument :
        verify_argument_impl<
          typename boost::mpl::if_<
            typename boost::mpl::or_<
              typename boost::mpl::front<typename Expected::type>::type,
              typename boost::mpl::at_c<typename Expected::type, 1>::type
            >::type,
            unsigned int,
            typename mpllibs::metamonad::unbox<
              boost::mpl::back<typename Expected::type>
            >::type
          >::type,
          typename Actual::type
        >
      {};
    }
  }
}

#endif

