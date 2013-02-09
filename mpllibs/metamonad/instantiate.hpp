#ifndef MPLLIBS_METAMONAD_INSTANTIATE_HPP
#define MPLLIBS_METAMONAD_INSTANTIATE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/if.hpp>

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/int.hpp>

#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

#ifndef MPLLIBS_INSTANTIATE_ARITY_LIMIT
  #define MPLLIBS_INSTANTIATE_ARITY_LIMIT 32
#endif

namespace mpllibs
{
  namespace metamonad
  {
    #ifdef MPLLIBS_CONT_GET_ELEM
      #error MPLLIBS_CONT_GET_ELEM already defined
    #endif
    #define MPLLIBS_CONT_GET_ELEM(z, n, unused) \
      typename if_< \
        boost::mpl::less< \
          boost::mpl::int_<n>, \
          typename boost::mpl::size<typename V::type>::type \
        >, \
        boost::mpl::deref< \
          BOOST_PP_REPEAT( \
            n, \
            typename boost::mpl::next< BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
            typename boost::mpl::begin<typename V::type>::type \
          BOOST_PP_REPEAT(n, >::type BOOST_PP_TUPLE_EAT(3), ~) \
        >, \
        returns<boost::mpl::na> \
      >::type

    #ifdef MPLLIBS_INSTANTIATE_CASE
      #error MPLLIBS_INSTANTIATE_CASE already defined
    #endif
    #define MPLLIBS_INSTANTIATE_CASE(z, n, unused) \
      template < \
        template <BOOST_PP_ENUM(n, class BOOST_PP_TUPLE_EAT(3), ~)> class T \
      > \
      struct BOOST_PP_CAT(instantiate, n) : \
        tmp_value<BOOST_PP_CAT(instantiate, n)<T> > \
      { \
        template <class V> \
        struct apply : \
          returns<T<BOOST_PP_ENUM(n, MPLLIBS_CONT_GET_ELEM, ~)> > \
        {}; \
      };

    BOOST_PP_REPEAT_FROM_TO(
      1,
      MPLLIBS_INSTANTIATE_ARITY_LIMIT,
      MPLLIBS_INSTANTIATE_CASE,
      ~
    )
    
    #undef MPLLIBS_INSTANTIATE_CASE
    #undef MPLLIBS_CONT_GET_ELEM
  }
}

#endif

