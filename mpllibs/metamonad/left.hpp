#ifndef MPLLIBS_METAMONAD_LEFT_HPP
#define MPLLIBS_METAMONAD_LEFT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/get_data.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/equal_to.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    struct left_tag : tmp_tag<left_tag> {};
    
    template <class T>
    struct left : tmp_value<left<T>, left_tag>
    {
      typedef typename T::type data;
    };
    
    template <>
    struct get_data_impl<left_tag>
    {
      MPLLIBS_METAFUNCTION(apply, (T)) ((returns<typename T::data>));
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <class A, class B>
    struct equal_to_impl;

    template <>
    struct
      equal_to_impl<
        mpllibs::metamonad::left_tag,
        mpllibs::metamonad::left_tag
      >
    {
      MPLLIBS_LAZY_METAFUNCTION(apply, (A)(B))
      ((
        equal_to<
          typename mpllibs::metamonad::get_data<A>::type,
          typename mpllibs::metamonad::get_data<B>::type
        >
      ));
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, mpllibs::metamonad::left, "left")

#endif

