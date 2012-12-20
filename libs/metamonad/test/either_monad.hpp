#ifndef MPLLIBS_METAMONAD_TEST_EITHER_MONAD_HPP
#define MPLLIBS_METAMONAD_TEST_EITHER_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/tag.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  /*
   * Either monad for testing
   */
  struct either_tag : mpllibs::metamonad::tmp_tag<either_tag> {};
  struct left_tag : mpllibs::metamonad::tmp_tag<left_tag> {};
  struct right_tag : mpllibs::metamonad::tmp_tag<right_tag> {};

  typedef either_tag either;
  
  template <class T>
  struct left : mpllibs::metamonad::tmp_value<left<T>, left_tag> {};
  
  template <class T>
  struct right : mpllibs::metamonad::tmp_value<right<T>, right_tag> {};

  template <class T>
  struct get_value;

  template <class T>
  struct get_value<left<T> >
  {
    typedef T type;
  };

  template <class T>
  struct get_value<right<T> >
  {
    typedef T type;
  };
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, left, "left")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, right, "right")

namespace boost
{
  namespace mpl
  {
    template <>
    struct equal_to_impl<left_tag, left_tag>
    {
      MPLLIBS_LAZY_METAFUNCTION(apply, (A)(B))
      ((
        mpllibs::metamonad::lazy<
          boost::mpl::equal_to<get_value<A>, get_value<B> >
        >
      ));
    };

    template <>
    struct equal_to_impl<right_tag, right_tag> :
      equal_to_impl<left_tag, left_tag>
    {};

    template <>
    struct equal_to_impl<right_tag, left_tag>
    {
      MPLLIBS_METAFUNCTION(apply, (A)(B))
      ((boost::mpl::identity<boost::mpl::false_>));
    };
    
    template <>
    struct equal_to_impl<left_tag, right_tag> :
      equal_to_impl<right_tag, left_tag>
    {};
  }
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct monad<either_tag> : monad_defaults<either_tag>
    {
      MPLLIBS_METAFUNCTION_CLASS(return_, (T)) ((right<T>));
      
      MPLLIBS_METAFUNCTION_CLASS(bind, (A)(F))
      ((
          typename boost::mpl::if_<
            typename boost::is_same<
              right_tag,
              typename boost::mpl::tag<typename A::type>::type
            >::type,
            boost::mpl::apply<F, typename get_value<typename A::type>::type>,
            A
          >::type
      ));
    };
  }
}

#endif


