#ifndef MPLLIBS_METAMONAD_HAS_GET_VALUE_HPP
#define MPLLIBS_METAMONAD_HAS_GET_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      struct yes
      {
        double _[1000];
      };

      char has_get_value_test(...);

      template <class T>
      yes has_get_value_test(T*, boost::mpl::int_<sizeof(T::get_value())>* = 0); 
    }

    template <class T>
    struct has_get_value :
      boost::mpl::bool_<
        sizeof(impl::has_get_value_test((T*)0)) == sizeof(impl::yes)
      >
    {};
  }
}

#endif

