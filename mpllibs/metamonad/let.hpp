#ifndef MPLLIBS_METAMONAD_LET_HPP
#define MPLLIBS_METAMONAD_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/util/id.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct let_impl;

    template <class A, class E1, class E2>
    struct let : let_impl<A, E1, E2>
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "let<";
          mpllibs::metatest::to_stream_argument_list<A, E1, E2>::run(o);
          return o << ">";
        }
      };
    };

    template <class A, class E1>
    struct let<A, E1, A> : mpllibs::metamonad::util::id<E1> {};

    
    // let_impl assumes, that let_impl<A, E1, A> is never instantiated
    template <class A, class E1, class E2>
    struct let_impl : mpllibs::metamonad::util::id<E2> {};

    template <class A, class E1a, class E1b, class E2>
    struct let_impl<A, E1a, let<A, E1b, E2> > :
      mpllibs::metamonad::util::id<let<A, E1b, E2> >
    {};

    template <class A, class E1, class E2>
    struct letrec;

    template <class A, class E1a, class E1b, class E2>
    struct let_impl<A, E1a, letrec<A, E1b, E2> > :
      mpllibs::metamonad::util::id<letrec<A, E1b, E2> >
    {};

    #ifndef MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT
      #define MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT 10
    #endif
    
    #ifdef MPLLIBS_LET_CLASS
      #error MPLLIBS_LET_CLASS alread defined
    #endif
    #define MPLLIBS_LET_CLASS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) class
    
    #ifdef MPLLIBS_LET_REC_CASE
      #error MPLLIBS_LET_REC_CASE alread defined
    #endif
    #define MPLLIBS_LET_REC_CASE(z, n, unused) \
      BOOST_PP_COMMA_IF(n) typename let<A, E1, X##n>::type

    #ifdef MPLLIBS_LET_TEMPLATE_CASE
      #error MPLLIBS_LET_TEMPLATE_CASE already defined
    #endif
    #define MPLLIBS_LET_TEMPLATE_CASE(z, n, unused) \
      template < \
        class A, \
        class E1, \
        template<BOOST_PP_REPEAT(n, MPLLIBS_LET_CLASS, ~) > class T, \
        BOOST_PP_ENUM_PARAMS(n, class X) \
      > \
      struct let_impl<A, E1, T<BOOST_PP_ENUM_PARAMS(n, X)> > : \
        mpllibs::metamonad::util::id< \
          T<BOOST_PP_REPEAT(n, MPLLIBS_LET_REC_CASE, ~) > \
        > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(
      1,
      MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT,
      MPLLIBS_LET_TEMPLATE_CASE,
      ~
    )

    #undef MPLLIBS_LET_TEMPLATE_CASE
    #undef MPLLIBS_LET_CLASS
    #undef MPLLIBS_LET_REC_CASE
  }
}

#endif

