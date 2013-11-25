#ifndef MPLLIBS_METAMONAD_V1_IMPL_VALUE_TO_STREAM_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_VALUE_TO_STREAM_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/tmp_value.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class T, bool HasGetValue, bool HasValue>
        struct value_to_stream_impl :
          tmp_value<value_to_stream_impl<T, HasGetValue, HasValue> >
        {
          static std::ostream& run(std::ostream& o_)
          {
            return o_ << "???";
          }
        };

        template <class T, bool HasValue>
        struct value_to_stream_impl<T, true, HasValue> :
          tmp_value<value_to_stream_impl<T, true, HasValue> >
        {
          static std::ostream& run(std::ostream& o_)
          {
            return o_ << T::get_value();
          }
        };

        template <class T>
        struct value_to_stream_impl<T, false, true> :
          tmp_value<value_to_stream_impl<T, false, true> >
        {
          static std::ostream& run(std::ostream& o_)
          {
            return o_ << T::value;
          }
        };
      }
    }
  }
}

#endif

