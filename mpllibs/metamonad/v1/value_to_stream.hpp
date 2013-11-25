#ifndef MPLLIBS_METAMONAD_V1_VALUE_TO_STREAM_HPP
#define MPLLIBS_METAMONAD_V1_VALUE_TO_STREAM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/value_to_stream.hpp>
#include <mpllibs/metamonad/v1/impl/value_to_stream_impl.hpp>

#include <mpllibs/metamonad/v1/has_get_value.hpp>
#include <mpllibs/metamonad/v1/has_value.hpp>
#include <mpllibs/metamonad/v1/lazy_metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_LAZY_METAFUNCTION(value_to_stream, (T))
      ((
        impl::value_to_stream_impl<
          T,
          has_get_value<T>::type::value,
          has_value<T>::type::value
        >
      ));
    }
  }
}

#endif

