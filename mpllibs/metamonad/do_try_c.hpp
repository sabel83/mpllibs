#ifndef MPLLIBS_METAMONAD_DO_TRY_C_HPP
#define MPLLIBS_METAMONAD_DO_TRY_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/do_try.hpp>
#include <mpllibs/metamonad/do_c.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_DO_MAX_ARGUMENT,
        class E,
        boost::mpl::na
      )
    >
    struct do_try_c :
      impl::do_try_impl<
        do_c<exception_tag, BOOST_PP_ENUM_PARAMS(MPLLIBS_DO_MAX_ARGUMENT, E)>
      >
    {};
  }
}

#endif

