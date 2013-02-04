#ifndef MPLLIBS_METAMONAD_BOX_HPP
#define MPLLIBS_METAMONAD_BOX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/map.hpp>

#include <boost/type_traits.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct box_tag : tmp_tag<box_tag> {};

    MPLLIBS_METAFUNCTION(box, (T)) ((tmp_value<box<T>, box_tag>));

    template <class E>
    struct lazy;

    // box should wrap things that are not nullary metafunctions
    template <class T>
    struct lazy<box<T> > : box<T> {};

    namespace impl
    {
      // the content of a box should not be used as a let variable
      template <class A, class E1, class E2>
      struct let_impl;

      template <class A, class E1, class T>
      struct let_impl<A, E1, box<T> > : box<T> {};
    }
  }
}

namespace boost
{
  namespace mpl
  {
    template <class T1, class T2>
    struct equal_to_impl;

    template <class T>
    struct equal_to_impl<mpllibs::metamonad::box_tag, T> :
      mpllibs::metamonad::lambda_c<
        mpllibs::metamonad::_, mpllibs::metamonad::_,
        boost::mpl::false_
      >
    {};

    template <class T>
    struct equal_to_impl<T, mpllibs::metamonad::box_tag> :
      equal_to_impl<mpllibs::metamonad::box_tag, T>
    {};

    template <>
    struct
      equal_to_impl<mpllibs::metamonad::box_tag, mpllibs::metamonad::box_tag> :
      mpllibs::metamonad::lambda_c<
        mpllibs::metamonad::name::a, mpllibs::metamonad::name::b,
        boost::is_same<mpllibs::metamonad::name::a, mpllibs::metamonad::name::b>
      >
    {};
  }
}

#endif

