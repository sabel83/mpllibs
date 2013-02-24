#ifndef MPLLIBS_METAMONAD_DATA_HPP
#define MPLLIBS_METAMONAD_DATA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/void.hpp>

#include <boost/type_traits.hpp>

#ifndef MPLLIBS_DATA_MAX_TEMPLATE_ARGUMENT
  #define MPLLIBS_DATA_MAX_TEMPLATE_ARGUMENT 10
#endif

#ifdef MPLLIBS_DATA_ARGS
  #error MPLLIBS_DATA_ARGS already defined
#endif
#define MPLLIBS_DATA_ARGS(arity) \
  template <BOOST_PP_ENUM(arity, class BOOST_PP_TUPLE_EAT(3), ~)>

#ifdef MPLLIBS_DATA_ARGS_WITH_DEFAULT_VOID
  #error MPLLIBS_DATA_ARGS_WITH_DEFAULT_VOID already defined
#endif
#define MPLLIBS_DATA_ARGS_WITH_DEFAULT_VOID(arity) \
  template < \
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(arity, class T, boost::mpl::void_) \
  >

#ifdef MPLLIBS_NULLARY_DATA_CONSTR
  #error MPLLIBS_NULLARY_DATA_CONSTR already defined
#endif
#define MPLLIBS_NULLARY_DATA_CONSTR(name, arity) \
  struct name : \
    mpllibs::metamonad::tmp_value< \
      name, \
      mpllibs::metamonad::algebraic_data_type_tag \
    > \
  {};

#ifdef MPLLIBS_BUILD_SEQ
  #error MPLLIBS_BUILD_SEQ already defined
#endif
#define MPLLIBS_BUILD_SEQ(z, n, unused) (BOOST_PP_CAT(T, n))

#ifdef MPLLIBS_NON_NULLARY_DATA_CONSTR
  #error MPLLIBS_NON_NULLARY_DATA_CONSTR already defined
#endif
#define MPLLIBS_NON_NULLARY_DATA_CONSTR(name, arity) \
  MPLLIBS_LAZY_METAFUNCTION(name, BOOST_PP_REPEAT(arity, MPLLIBS_BUILD_SEQ, ~))\
  (( \
    mpllibs::metamonad::tmp_value< \
      name<BOOST_PP_ENUM_PARAMS(arity, T)>, \
      mpllibs::metamonad::algebraic_data_type_tag \
    > \
  )); \

#ifdef MPLLIBS_DATA_CONSTR
  #error MPLLIBS_DATA_CONSTR already defined
#endif
#define MPLLIBS_DATA_CONSTR(name, arity) \
  BOOST_PP_IF( \
    arity, \
    MPLLIBS_NON_NULLARY_DATA_CONSTR, \
    MPLLIBS_NULLARY_DATA_CONSTR \
  )(name, arity)

#ifdef MPLLIBS_DATA_CONSTR_CB
  #error MPLLIBS_DATA_CONSTR_CB already defined
#endif
#define MPLLIBS_DATA_CONSTR_CB(r, unused, constr) \
  MPLLIBS_DATA_CONSTR( \
    BOOST_PP_TUPLE_ELEM(2, 0, constr), \
    BOOST_PP_TUPLE_ELEM(2, 1, constr) \
  )

#ifdef MPLLIBS_DATA
  #error MPLLIBS_DATA already defined
#endif
#define MPLLIBS_DATA(name, type_arity, constrs) \
  BOOST_PP_IF( \
    type_arity, \
    MPLLIBS_DATA_ARGS_WITH_DEFAULT_VOID, \
    BOOST_PP_TUPLE_EAT(1) \
  )(type_arity) \
  struct BOOST_PP_CAT(name, _tag); \
  \
  BOOST_PP_SEQ_FOR_EACH(MPLLIBS_DATA_CONSTR_CB, ~, constrs) \
  \
  BOOST_PP_IF(type_arity, MPLLIBS_DATA_ARGS, BOOST_PP_TUPLE_EAT(1))(type_arity)\
  struct BOOST_PP_CAT(name, _tag) \
  { \
    typedef BOOST_PP_CAT(name, _tag) type; \
    typedef mpllibs::metamonad::tag_tag tag; \
  }

namespace mpllibs
{
  namespace metamonad
  {
    struct algebraic_data_type_tag : tmp_value<algebraic_data_type_tag> {};

    namespace impl
    {
      template <class A, class B>
      struct rec_equal_to_impl : boost::mpl::false_ {};

      #ifdef REC_EQUAL_TO_CASE
        #error REC_EQUAL_TO_CASE already defined
      #endif
      #define REC_EQUAL_TO_CASE(z, n, unused) \
        template < \
          MPLLIBS_DATA_ARGS(n) class T, \
          BOOST_PP_ENUM_PARAMS(n, class A), \
          BOOST_PP_ENUM_PARAMS(n, class B) \
        > \
        struct \
          rec_equal_to_impl< \
            T<BOOST_PP_ENUM_PARAMS(n, A)>, \
            T<BOOST_PP_ENUM_PARAMS(n, B)> \
          > : \
          boost::mpl::equal< \
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, A)>, \
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, B)>, \
            boost::mpl::equal_to<boost::mpl::_1, boost::mpl::_2> \
          > \
        {};
      
      BOOST_PP_REPEAT_FROM_TO(
        1,
        MPLLIBS_DATA_MAX_TEMPLATE_ARGUMENT,
        REC_EQUAL_TO_CASE,
        ~
      )
      
      #undef REC_EQUAL_TO_CASE

      // It detects when the same constructor is used for both values and
      // compares the constructor arguments using equal_to
      template <class A, class B>
      struct rec_equal_to : rec_equal_to_impl<A, B> {};

      template <class A>
      struct rec_equal_to<A, A> : boost::mpl::true_ {};
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
    struct equal_to_impl<T, mpllibs::metamonad::algebraic_data_type_tag> :
      always<false_>
    {};
    
    template <class T>
    struct equal_to_impl<mpllibs::metamonad::algebraic_data_type_tag, T> :
      always<false_>
    {};
    
    template <>
    struct
      equal_to_impl<
        mpllibs::metamonad::algebraic_data_type_tag,
        mpllibs::metamonad::algebraic_data_type_tag
      >
    {
      typedef equal_to_impl type;
      
      MPLLIBS_LAZY_METAFUNCTION(apply, (A)(B))
      ((mpllibs::metamonad::impl::rec_equal_to<A, B>));
    };
  }
}

#endif

