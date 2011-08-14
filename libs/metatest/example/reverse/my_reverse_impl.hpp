#ifndef MPLLIBS_METATEST_MY_REVERSE_IMPL_HPP_INCLUDED
#define MPLLIBS_METATEST_MY_REVERSE_IMPL_HPP_INCLUDED

// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/sequence_tag.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/deref.hpp>

template< typename Tag > struct my_reverse_impl {};

template< typename First, typename Last, typename Accum >
struct my_accum_reverse_impl;

#if defined(BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
template<>
struct my_reverse_impl<
      boost::mpl::aux::vector_tag
  >
#else
template<long N>
struct my_reverse_impl<
      boost::mpl::aux::vector_tag<N>
  >
#endif
{
  template< typename Vector > struct apply
    : my_accum_reverse_impl<
          typename boost::mpl::begin<Vector>::type
        , typename boost::mpl::end<Vector>::type
        , boost::mpl::vector<>
        >
  {};
};

template< typename First, typename Last, typename Accum >
struct my_accum_reverse_impl
  : my_accum_reverse_impl<
          typename boost::mpl::next<First>::type
        , Last
        , typename boost::mpl::push_front<
                Accum
              , typename boost::mpl::deref<First>::type
            >::type
      >
{};

template< typename Last, typename Accum >
struct my_accum_reverse_impl< Last, Last, Accum >
  : Accum
{};

#endif // MPLLIBS_METATEST_MY_REVERSE_IMPL_HPP_INCLUDED

