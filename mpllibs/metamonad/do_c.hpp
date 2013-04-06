#ifndef MPLLIBS_METAMONAD_DO_C_HPP
#define MPLLIBS_METAMONAD_DO_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/eval_let_c.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/eval_match_let.hpp>
#include <mpllibs/metamonad/eval_match_let_c.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/instantiate.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/eval_guard.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/pair.hpp>
#include <mpllibs/metamonad/is_same.hpp>
#include <mpllibs/metamonad/apply.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

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
     * do_return
     */
    template <class V>
    struct do_return : tmp_value<do_return<V> > {};

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
        returns<T<BOOST_PP_ENUM(n, MPLLIBS_DO_REC_CASE, ~)> > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(
      1,
      BOOST_PP_INC(BOOST_MPL_LIMIT_METAFUNCTION_ARITY),
      MPLLIBS_DO_TEMPLATE_CASE,
      ~
    )

    #undef MPLLIBS_DO_TEMPLATE_CASE
    #undef MPLLIBS_DO_REC_CASE

    /*
     * set
     */
    template <class Name, class F>
    struct set : tmp_value<set<Name, F> > {};

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
        apply< \
          typename monad<Monad>::bind_, \
          T, \
          BOOST_PP_CAT(do, BOOST_PP_DEC(n))< \
            Monad, \
            BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), E) \
          > \
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
        apply< \
          typename monad<Monad>::bind, \
          do1<Monad, Ex>, \
          lambda_c< \
            Name, \
            BOOST_PP_CAT(do, BOOST_PP_DEC(n))< \
              Monad, \
              BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), E) \
            > \
          > \
        > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(2, MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DO_CASE, ~)
    
    #undef MPLLIBS_DO_CASE
        
    /*
     * do_c
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
    struct do_c;

    #ifdef MPLLIBS_DO_CASE
      #error MPLLIBS_DO_CASE already defined
    #endif
    #define MPLLIBS_DO_CASE(z, n, unused) \
      template <class Monad, BOOST_PP_ENUM_PARAMS(n, class E)> \
      struct do_c< \
        Monad, \
        BOOST_PP_ENUM_PARAMS(n, E) BOOST_PP_COMMA_IF(n) \
        BOOST_PP_ENUM( \
          BOOST_PP_SUB(MPLLIBS_DO_MAX_ARGUMENT, n), \
          boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
          ~ \
        ) \
      > : \
        BOOST_PP_CAT(do, n)<Monad BOOST_PP_REPEAT(n, MPLLIBS_DO_ARG, ~)> \
      {};
  
    BOOST_PP_REPEAT_FROM_TO(1, MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DO_CASE, ~)
    
    #undef MPLLIBS_DO_CASE
    #undef MPLLIBS_DO_ARG

    /*
     * do_
     */
    template <
      class Monad,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_DO_MAX_ARGUMENT,
        class E,
        syntax<boost::mpl::na>
      )
    >
    struct do_;

    /*
      Protection against let
    */
    namespace impl
    {
      // Custom names are needed to avoid "let"'s A be the same as one of the
      // names used
      struct let_do_c_;
      struct let_do_d_;
      struct let_do_n_;
      struct let_do_s_;
      struct let_do_v_;
      struct let_do_w_;

      typedef var<let_do_c_> let_do_c;
      typedef var<let_do_d_> let_do_d;
      typedef var<let_do_n_> let_do_n;
      typedef var<let_do_s_> let_do_s;
      typedef var<let_do_v_> let_do_v;
      typedef var<let_do_w_> let_do_w;

      MPLLIBS_METAFUNCTION(let_do_args, (A)(E1)(V))
      ((
        boost::mpl::fold<
          V,
          pair<boost::mpl::vector<>, boost::mpl::true_>,
          lambda_c<let_do_s, let_do_c,
            eval_match_let_c<
              pair<let_do_v, let_do_d>,
              let_do_s,
              if_< let_do_d,
                eval_case< eval_guard<let_do_c>,
                  matches_c<eval_guard<set<let_do_n, let_do_w> >,
                    if_<
                      is_same<A, let_do_n>,
                      pair<
                        boost::mpl::push_back<let_do_v, let_do_c>,
                        boost::mpl::false_
                      >,
                      pair<
                        lazy<
                          boost::mpl::push_back<
                            lazy_protect_args<let_do_v>,
                            lazy_protect_args<
                              eval_let_c<A, E1, set<let_do_n, let_do_w> >
                            >
                          >
                        >,
                        boost::mpl::true_
                      >
                    >
                  >,
                  matches_c<_,
                    pair<
                      lazy<
                        boost::mpl::push_back<
                          lazy_protect_args<let_do_v>,
                          lazy_protect_args<
                            eval_let_c<A, E1, returns<let_do_c> >
                          >
                        >
                      >,
                      boost::mpl::true_
                    >
                  >
                >,
                pair<
                  boost::mpl::push_back<let_do_v, let_do_c>,
                  boost::mpl::false_
                >
              >
            >
          >
        >
      ));

      #ifdef MPLLIBS_HANDLE_DO_FUN
        #error MPLLIBS_HANDLE_DO_FUN
      #endif
      #define MPLLIBS_HANDLE_DO_FUN(f, arg_num) \
        template < \
          class A, \
          class E1, \
          class Monad, \
          BOOST_PP_ENUM_PARAMS(arg_num, class T) \
        > \
        struct \
          let_impl<A, E1, f<Monad, BOOST_PP_ENUM_PARAMS(arg_num, T)> > : \
          eval_match_let< \
            syntax<pair<let_do_w, _> >, \
            let_do_args< \
              A, \
              E1, \
              boost::mpl::vector<BOOST_PP_ENUM_PARAMS(arg_num, T)> \
            >, \
            syntax< \
              apply< \
                BOOST_PP_CAT(instantiate, BOOST_PP_INC(arg_num))<f>, \
                boost::mpl::push_front<let_do_w, Monad> \
              > \
            > \
          > \
        {}

      MPLLIBS_HANDLE_DO_FUN(do_, MPLLIBS_DO_MAX_ARGUMENT);
      MPLLIBS_HANDLE_DO_FUN(do_c, MPLLIBS_DO_MAX_ARGUMENT);

      #ifdef MPLLIBS_HANDE_DO_N
        #error MPLLIBS_HANDLE_DO_N
      #endif
      #define MPLLIBS_HANDLE_DO_N(z, n, unused) \
        MPLLIBS_HANDLE_DO_FUN(BOOST_PP_CAT(do, n), n);

      BOOST_PP_REPEAT_FROM_TO(1, MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_HANDLE_DO_N,~)

      #undef MPLLIBS_HANDLE_DO_N
      #undef MPLLIBS_HANDLE_DO_FUN
    }
  }
}

#endif

