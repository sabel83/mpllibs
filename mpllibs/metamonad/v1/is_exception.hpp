#ifndef MPLLIBS_METAMONAD_V1_IS_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_V1_IS_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/is_exception.hpp>

#include <mpllibs/metamonad/v1/impl/strict_is_exception.hpp>
#include <mpllibs/metamonad/v1/lazy_metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_LAZY_METAFUNCTION(is_exception, (T))
      ((impl::strict_is_exception<T>));
    }
  }
}

#endif

