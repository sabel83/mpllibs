#ifndef MPLLIBS_METAMONAD_IS_SAME_HPP
#define MPLLIBS_METAMONAD_IS_SAME_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/type_traits/is_same.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    // LAZY_METAFUNCTION depends on it
    namespace impl
    {
      struct is_same_no_arg;
    }

    template <class A = impl::is_same_no_arg, class B = impl::is_same_no_arg>
    struct is_same : boost::is_same<typename A::type, typename B::type> {};

    template <class A>
    struct is_same<A, impl::is_same_no_arg> :
      tmp_value<is_same<A, impl::is_same_no_arg> >
    {
      template <class B = impl::is_same_no_arg>
      struct apply : is_same<A, B> {};
    };

    template <>
    struct is_same<impl::is_same_no_arg, impl::is_same_no_arg> :
      tmp_value<is_same<impl::is_same_no_arg, impl::is_same_no_arg> >
    {
      template <class A = impl::is_same_no_arg, class B = impl::is_same_no_arg>
      struct apply : is_same<A, B> {};
    };
  }
}

#endif

