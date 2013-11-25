#ifndef MPLLIBS_SAFE_PRINTF_IMPL_MATCHES_HPP
#define MPLLIBS_SAFE_PRINTF_IMPL_MATCHES_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/v1/impl/any_type.hpp>

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/unbox.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_cv.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace v1
    {
      namespace impl
      {
        template <class A, class B>
        struct matches_impl : boost::is_same<A, B> {};

        template <class A>
        struct matches_impl<A, any_type> : boost::mpl::true_ {};

        template <class B>
        struct matches_impl<any_type, B> : boost::mpl::true_ {};

        template <class A, class B>
        struct matches_recurse :
          matches_impl<
            typename boost::remove_cv<A>::type,
            typename boost::remove_cv<B>::type
          >
        {};

        template <class A, class B>
        struct matches_impl<A*, B*> : matches_recurse<A, B> {};

        template <class A, class B>
        struct matches_impl<A[], B[]> : matches_recurse<A, B> {};

        template <class A, class B>
        struct matches_impl<A*, B[]> : matches_recurse<A, B> {};

        template <class A, class B>
        struct matches_impl<A[], B*> : matches_recurse<A, B> {};

        MPLLIBS_METAFUNCTION(matches, (A)(B))
        ((
          matches_recurse<
            typename metamonad::unbox<A>::type,
            typename metamonad::unbox<B>::type
          >
        ));
      }
    }
  }
}

#endif

