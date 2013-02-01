#ifndef MPLLIBS_METAMONAD_IS_TAG_HPP
#define MPLLIBS_METAMONAD_IS_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/mpl/tag.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/has_xxx.hpp>

#include <boost/type_traits.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      BOOST_MPL_HAS_XXX_TRAIT_DEF(type)
    }

    template <class E, class T = boost::mpl::na>
    struct is_tag : 
      boost::is_same<
        typename boost::mpl::tag<typename E::type>::type,
        // Tags coming from Boost.Mpl are not metaprogramming values
        typename boost::mpl::eval_if<
          typename impl::has_type<T>::type,
          T,
          returns<T>
        >::type
      >
    {};

    template <class E>
    struct is_tag<E, boost::mpl::na> : tmp_value<is_tag<E, boost::mpl::na> >
    {
      template <class T>
      struct apply : is_tag<E, T> {};
    };
  }
}

#endif

