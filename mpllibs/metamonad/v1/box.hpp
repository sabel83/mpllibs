#ifndef MPLLIBS_METAMONAD_V1_BOX_HPP
#define MPLLIBS_METAMONAD_V1_BOX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/box.hpp>
#include <mpllibs/metamonad/v1/fwd/lazy.hpp>
#include <mpllibs/metamonad/v1/impl/fwd/let_impl.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/is_same.hpp>
#include <mpllibs/metamonad/v1/box_tag.hpp>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/map.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(box, (T)) ((tmp_value<box<T>, box_tag>));

      // box should wrap things that are not nullary metafunctions
      template <class T>
      struct lazy<box<T> > : box<T> {};

      namespace impl
      {
        // the content of a box should not be used as a let variable
        template <class A, class E1, class T>
        struct let_impl<A, E1, box<T> > : box<T> {};
      }
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
    struct equal_to_impl<mpllibs::metamonad::v1::box_tag, T> :
      mpllibs::metamonad::v1::lambda_c<
        mpllibs::metamonad::v1::_, mpllibs::metamonad::v1::_,
        boost::mpl::false_
      >
    {};

    template <class T>
    struct equal_to_impl<T, mpllibs::metamonad::v1::box_tag> :
      equal_to_impl<mpllibs::metamonad::v1::box_tag, T>
    {};

    template <>
    struct
      equal_to_impl<
        mpllibs::metamonad::v1::box_tag,
        mpllibs::metamonad::v1::box_tag
      > :
      mpllibs::metamonad::v1::lambda_c<
        mpllibs::metamonad::v1::name::a, mpllibs::metamonad::v1::name::b,
        is_same<
          mpllibs::metamonad::v1::name::a,
          mpllibs::metamonad::v1::name::b
        >
      >
    {};
  }
}

#endif

