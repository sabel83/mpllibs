#ifndef MPLLIBS_METAMONAD_VALUE_TO_STREAM_HPP
#define MPLLIBS_METAMONAD_VALUE_TO_STREAM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/has_get_value.hpp>
#include <mpllibs/metamonad/has_value.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
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

    MPLLIBS_LAZY_METAFUNCTION(value_to_stream, (T))
    ((
      impl::value_to_stream_impl<
        T,
        has_get_value<T>::type::value,
        has_value<T>::type::value
      >
    ));
  }
}

#endif

