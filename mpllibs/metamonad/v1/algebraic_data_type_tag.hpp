#ifndef MPLLIBS_METAMONAD_V1_ALGEBRAIC_DATA_TYPE_TAG_HPP
#define MPLLIBS_METAMONAD_V1_ALGEBRAIC_DATA_TYPE_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/algebraic_data_type_tag.hpp>
#include <mpllibs/metamonad/v1/impl/rec_equal_to.hpp>

#include <mpllibs/metamonad/v1/tmp_value.hpp>
#include <mpllibs/metamonad/v1/lazy_metafunction.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/equal.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      struct algebraic_data_type_tag : tmp_value<algebraic_data_type_tag> {};
    }
  }
}

namespace boost
{
  namespace mpl
  {
    template <class, class>
    struct equal_to_impl;
    
    template <class T>
    struct equal_to_impl<T, mpllibs::metamonad::v1::algebraic_data_type_tag> :
      always<false_>
    {};
    
    template <class T>
    struct equal_to_impl<mpllibs::metamonad::v1::algebraic_data_type_tag, T> :
      always<false_>
    {};
    
    template <>
    struct
      equal_to_impl<
        mpllibs::metamonad::v1::algebraic_data_type_tag,
        mpllibs::metamonad::v1::algebraic_data_type_tag
      >
    {
      typedef equal_to_impl type;
      
      MPLLIBS_V1_LAZY_METAFUNCTION(apply, (A)(B))
      ((mpllibs::metamonad::v1::impl::rec_equal_to<A, B>));
    };
  }
}

#endif

