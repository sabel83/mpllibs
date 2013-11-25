#ifndef MPLLIBS_METAMONAD_V1_LAZY_HPP
#define MPLLIBS_METAMONAD_V1_LAZY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/lazy.hpp>
#include <mpllibs/metamonad/limit_metafunction_arity.hpp>

#include <boost/mpl/if.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp> 
#include <boost/preprocessor/repetition/enum.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class AnglyExpr>
      struct lazy : AnglyExpr {};
 
      #ifdef MPLLIBS_METAMONAD_LAZY_REC
      #  error MPLLIBS_METAMONAD_LAZY_REC already defined
      #endif
      #define MPLLIBS_METAMONAD_LAZY_REC(z, n, unused) \
        typename lazy<BOOST_PP_CAT(T, n)>::type
  
      #ifdef MPLLIBS_METAMONAD_LAZY_TEMPLATE
      #  error MPLLIBS_METAMONAD_LAZY_TEMPLATE already defined
      #endif
      #define MPLLIBS_METAMONAD_LAZY_TEMPLATE(z, n, unused) \
        template < \
          template <BOOST_PP_ENUM(n, class BOOST_PP_TUPLE_EAT(3), ~)> class T, \
          BOOST_PP_ENUM_PARAMS(n, class T) \
        > \
        struct lazy<T<BOOST_PP_ENUM_PARAMS(n, T)> > : \
          T<BOOST_PP_ENUM(n, MPLLIBS_METAMONAD_LAZY_REC, ~)> \
        {};
      
      BOOST_PP_REPEAT_FROM_TO(
        1,
        MPLLIBS_LIMIT_METAFUNCTION_ARITY,
        MPLLIBS_METAMONAD_LAZY_TEMPLATE,
        ~
      )
  
      #undef MPLLIBS_METAMONAD_LAZY_REC
      #undef MPLLIBS_METAMONAD_LAZY_TEMPLATE
  
      template <class Expr>
      struct lazy<lazy<Expr> > : lazy<Expr> {};
    }
  }
}

#endif

