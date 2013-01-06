#ifndef MPLLIBS_METAMONAD_DO__HPP
#define MPLLIBS_METAMONAD_DO__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/eval_match_let.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/instantiate.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/push_back.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    #ifndef MPLLIBS_DO_MAX_ARGUMENT
      #define MPLLIBS_DO_MAX_ARGUMENT 8
    #endif
    
    #if MPLLIBS_DO_MAX_ARGUMENT + 2 > MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT
      #error MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT not big enough
    #endif
    
    /*
     * Syntactic sugar
     */
    template <
      class Monad,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_DO_MAX_ARGUMENT,
        class E,
        boost::mpl::na
      )
    >
    struct do_impl;
    
    /*
     * do_return
     */
    template <class>
    struct do_return;

    /*
     * do_return substitution
     */
    // I can't use let, because I should not stop at let expressions.
    // Nested do_'s are not important, since they should be used by
    // accessing a nested apply template, and do_substitute doesn't
    // recurse into that.
    // Using boost::mpl::apply and do_ together is not supported
    template <class Monad, class T>
    struct do_substitute : returns<T> {};

    template <class Monad, class T>
    struct do_substitute<Monad, do_return<T> > :
      returns<return_<Monad, typename do_substitute<Monad, T>::type> >
    {};
    
    // When an outer do_ has already substituted this do_return,
    // we need to re-substitute it. I couldn't find a way of preventing
    // substitution of inner do_'s do_returns.
    template <class Monad1, class Monad2, class T>
    struct do_substitute<Monad1, return_<Monad2, T> > :
      returns<return_<Monad1, typename do_substitute<Monad1, T>::type> >
    {};

    #ifdef MPLLIBS_DO_REC_CASE
      #error MPLLIBS_DO_REC_CASE alread defined
    #endif
    #define MPLLIBS_DO_REC_CASE(z, n, unused) \
      typename do_substitute<Monad, BOOST_PP_CAT(X, n)>::type

    #ifdef MPLLIBS_DO_TEMPLATE_CASE
      #error MPLLIBS_DO_TEMPLATE_CASE already defined
    #endif
    #define MPLLIBS_DO_TEMPLATE_CASE(z, n, unused) \
      template < \
        class Monad, \
        template<BOOST_PP_ENUM(n, class BOOST_PP_TUPLE_EAT(3), ~) > class T, \
        BOOST_PP_ENUM_PARAMS(n, class X) \
      > \
      struct do_substitute<Monad, T<BOOST_PP_ENUM_PARAMS(n, X)> > : \
        mpllibs::metamonad::returns<T<BOOST_PP_ENUM(n,MPLLIBS_DO_REC_CASE,~)> >\
      {};
    
    BOOST_PP_REPEAT_FROM_TO(
      1,
      MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT,
      MPLLIBS_DO_TEMPLATE_CASE,
      ~
    )

    #undef MPLLIBS_DO_TEMPLATE_CASE
    #undef MPLLIBS_DO_REC_CASE

    /*
     * set
     */
    template <class Name, class F>
    struct set;

    /*
     * do1
     */
    // This case handles nullary metafunction elements of the do
    template <class Monad, class E>
    struct do1 : E {};

    template <class Monad, class Name, class F>
    struct do1<Monad, set<Name, F> >;
      // Error: last statement in a 'do' construct must be an expression.
      // Current way of error handling is not having an implementation.
      // It may be improved.
    
    /*
     * don
     */
    #ifdef MPLLIBS_DO_CASE
      #error MPLLIBS_DO_CASE already defined
    #endif
    // I need at least one template argument. The "n"th case handles n+1 args.
    #define MPLLIBS_DO_CASE(z, n, unused) \
      template < \
        class Monad, \
        class T BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) \
        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), class E) \
      > \
      struct BOOST_PP_CAT(do, n) : \
        boost::mpl::apply_wrap2< \
          typename monad<Monad>::bind_, \
          typename T::type, \
          typename do_impl< \
            Monad, \
            BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), E) \
          >::type \
        > \
      {}; \
      \
      template < \
        class Monad, \
        class Name, \
        class Ex BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) \
        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), class E) \
      > \
      struct BOOST_PP_CAT(do, n)< \
        Monad, \
        set<Name, Ex> BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) \
        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), E) \
      > : \
        boost::mpl::apply_wrap2< \
          typename monad<Monad>::bind, \
          typename do1<Monad, Ex>::type, \
          lambda< \
            Name, \
            do_impl<Monad, BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), E)> \
          > \
        > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(2, MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DO_CASE, ~)
    
    #undef MPLLIBS_DO_CASE
        
    /*
     * do_impl
     */
    #ifdef MPLLIBS_DO_CASE
      #error MPLLIBS_DO_CASE already defined
    #endif
    #define MPLLIBS_DO_CASE(z, n, unused) \
      template <class Monad, BOOST_PP_ENUM_PARAMS(n, class E)> \
      struct do_impl< \
        Monad, \
        BOOST_PP_ENUM_PARAMS(n, E) BOOST_PP_COMMA_IF(n) \
        BOOST_PP_ENUM( \
          BOOST_PP_SUB(MPLLIBS_DO_MAX_ARGUMENT, n), \
          boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
          ~ \
        ) \
      > : \
        BOOST_PP_CAT(do, n)<Monad, BOOST_PP_ENUM_PARAMS(n, E)> \
      {};
  
    BOOST_PP_REPEAT_FROM_TO(1, MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DO_CASE, ~)
    
    #undef MPLLIBS_DO_CASE
    
    /*
     * do_
     */
    #ifdef MPLLIBS_DO_ARG
      #error MPLLIBS_DO_ARG already defined
    #endif
    #define MPLLIBS_DO_ARG(z, n, unused) \
      , typename do_substitute<Monad, BOOST_PP_CAT(E, n)>::type
     
    template <
      class Monad,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_DO_MAX_ARGUMENT,
        class E,
        boost::mpl::na
      )
    >
    struct do_:
      do_impl<
        Monad BOOST_PP_REPEAT(MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DO_ARG, ~)
      >
    {};

    #undef MPLLIBS_DO_ARG

    /*
      Protection against let
    */
    namespace impl
    {
      // Custom names are needed to avoid "let"'s A be the same as one of the
      // names used
      struct let_do_c;
      struct let_do_d;
      struct let_do_s;
      struct let_do_v;
      struct let_do_w;

      MPLLIBS_METAFUNCTION(let_do_args, (A)(E1)(V))
      ((
        boost::mpl::fold<
          V,
          boost::mpl::pair<boost::mpl::vector<>, boost::mpl::true_>,
          lambda<let_do_s, let_do_c,
            eval_match_let<
              boost::mpl::pair<var<let_do_v>, var<let_do_d> >,
              let_do_s,
              boost::mpl::eval_if< let_do_d,
                eval_case< returns<let_do_c>,
                  matches<set<A, _>,
                    lazy<
                      boost::mpl::pair<
                        lazy_protect_args<
                          boost::mpl::push_back<let_do_v, let_do_c>
                        >,
                        boost::mpl::false_
                      >
                    >
                  >,
                  matches<_,
                    lazy<
                      boost::mpl::pair<
                        boost::mpl::push_back<
                          already_lazy<let_do_v>,
                          lazy_protect_args<let<A, E1, let_do_c> >
                        >,
                        boost::mpl::true_
                      >
                    >
                  >
                >,
                lazy<
                  boost::mpl::pair<
                    lazy_protect_args<
                      boost::mpl::push_back<let_do_v, let_do_c>
                    >,
                    boost::mpl::false_
                  >
                >
              >
            >
          >
        >
      ));
    }

    #ifdef MPLLIBS_HANDLE_DO_FUN
      #error MPLLIBS_HANDLE_DO_FUN
    #endif
    #define MPLLIBS_HANDLE_DO_FUN(f) \
      template < \
        class A, \
        class E1, \
        class Monad, \
        BOOST_PP_ENUM_PARAMS(MPLLIBS_DO_MAX_ARGUMENT, class T) \
      > \
      struct \
        let_impl< \
          A, \
          E1, \
          f<Monad, BOOST_PP_ENUM_PARAMS(MPLLIBS_DO_MAX_ARGUMENT, T)> \
        > : \
        eval_match_let< \
          boost::mpl::pair<var<impl::let_do_w>, _>, \
          impl::let_do_args< \
            A, \
            E1, \
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(MPLLIBS_DO_MAX_ARGUMENT,T)>\
          >, \
          lazy< \
            boost::mpl::apply_wrap1< \
              BOOST_PP_CAT(instantiate, BOOST_PP_INC(MPLLIBS_DO_MAX_ARGUMENT))<\
                f \
              >, \
              lazy_protect_args<boost::mpl::push_front<impl::let_do_w, Monad> >\
            > \
          > \
        > \
      {}

    MPLLIBS_HANDLE_DO_FUN(do_);
    MPLLIBS_HANDLE_DO_FUN(do_impl);

    #undef MPLLIBS_HANDLE_DO_FUN
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, mpllibs::metamonad::do_, "MPLLIBS_DO")

#endif

