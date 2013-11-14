#ifndef MPLLIBS_METAPARSE_IMPL_STRING_HPP
#define MPLLIBS_METAPARSE_IMPL_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/string_fwd.hpp>
#include <mpllibs/metaparse/string_tag.hpp>
#include <mpllibs/metaparse/impl/string_iterator.hpp>
#include <mpllibs/metaparse/impl/empty_string.hpp>
#include <mpllibs/metaparse/impl/size.hpp>
#include <mpllibs/metaparse/impl/pop_front.hpp>
#include <mpllibs/metaparse/impl/push_front_c.hpp>
#include <mpllibs/metaparse/impl/push_back_c.hpp>
#include <mpllibs/metaparse/impl/pop_back.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

#include <boost/type_traits/is_same.hpp>

/*
 * The string type
 */

namespace mpllibs
{
  namespace metaparse
  {
#ifdef MPLLIBS_VARIADIC_STRING
    template <char... Cs>
    struct string
    {
      typedef string type;
      typedef string_tag tag;
    };
#else
    template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C)>
    struct string
    {
      typedef string type;
      typedef string_tag tag;
    };
#endif
  }
}

/*
 * Boost.MPL overloads
 */

namespace boost
{
  namespace mpl
  {
    // push_back
    template <class S>
    struct push_back_impl;

    template <>
    struct push_back_impl<mpllibs::metaparse::string_tag>
    {
      typedef push_back_impl type;

      template <class S, class C>
      struct apply :
        mpllibs::metaparse::impl::push_back_c<typename S::type, C::type::value>
      {};
    };

    // pop_back
    template <class S>
    struct pop_back_impl;

    template <>
    struct pop_back_impl<mpllibs::metaparse::string_tag>
    {
      typedef pop_back_impl type;

      template <class S>
      struct apply : mpllibs::metaparse::impl::pop_back<S> {};
    };

    // push_front
    template <class S>
    struct push_front_impl;

    template <>
    struct push_front_impl<mpllibs::metaparse::string_tag>
    {
      typedef push_front_impl type;

      template <class S, class C>
      struct apply :
        mpllibs::metaparse::impl::push_front_c<typename S::type, C::type::value>
      {};
    };

    // pop_front
    template <class S>
    struct pop_front_impl;

    template <>
    struct pop_front_impl<mpllibs::metaparse::string_tag>
    {
      typedef pop_front_impl type;

      template <class S>
      struct apply : mpllibs::metaparse::impl::pop_front<S> {};
    };

    // clear
    template <class S>
    struct clear_impl;

    template <>
    struct clear_impl<mpllibs::metaparse::string_tag>
    {
      typedef clear_impl type;

      template <class S>
      struct apply : mpllibs::metaparse::string<> {};
    };

    // begin
    template <class S>
    struct begin_impl;

    template <>
    struct begin_impl<mpllibs::metaparse::string_tag>
    {
      typedef begin_impl type;

      template <class S>
      struct apply :
        mpllibs::metaparse::impl::string_iterator<typename S::type, 0>
      {};
    };

    // end
    template <class S>
    struct end_impl;

    template <>
    struct end_impl<mpllibs::metaparse::string_tag>
    {
      typedef end_impl type;

      template <class S>
      struct apply :
        mpllibs::metaparse::impl::string_iterator<
          typename S::type,
          mpllibs::metaparse::impl::size<typename S::type>::type::value
        >
      {};
    };

    // equal_to
    template <class A, class B>
    struct equal_to_impl;

    template <>
    struct equal_to_impl<
      mpllibs::metaparse::string_tag,
      mpllibs::metaparse::string_tag
    >
    {
      typedef equal_to_impl type;

      template <class A, class B>
      struct apply : boost::is_same<typename A::type, typename B::type> {};
    };

    template <class T>
    struct equal_to_impl<mpllibs::metaparse::string_tag, T>
    {
      typedef equal_to_impl type;
      
      template <class, class>
      struct apply : false_ {};
    };
    
    template <class T>
    struct equal_to_impl<T, mpllibs::metaparse::string_tag> :
      equal_to_impl<mpllibs::metaparse::string_tag, T>
    {};

    // c_str
    template <class S>
    struct c_str;

#ifdef MPLLIBS_VARIADIC_STRING
    template <char... Cs>
    struct c_str<mpllibs::metaparse::string<Cs...>>
    {
      typedef c_str type;
      #if defined MPLLIBS_USE_CONSTEXPR && !defined MPLLIBS_NO_CONSTEXPR_C_STR
        static constexpr const char value[sizeof...(Cs)] = {Cs...};
      #else
        static const char value[sizeof...(Cs)];
      #endif
    };

    template <>
    struct c_str<mpllibs::metaparse::string<>> :
      mpllibs::metaparse::impl::empty_string<>
    {};

    #if defined MPLLIBS_USE_CONSTEXPR && !defined MPLLIBS_NO_CONSTEXPR_C_STR
      template <char... Cs>
      constexpr const char c_str<mpllibs::metaparse::string<Cs...>>::value[];
    #else
      template <char... Cs>
      const char c_str<mpllibs::metaparse::string<Cs...>>::value[] = {Cs...};
    #endif

#else
    template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C)>
    struct c_str<
      mpllibs::metaparse::string<
        BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C)
      >
    >
    {
      typedef c_str type;
      static MPLLIBS_CONSTEXPR const char value[MPLLIBS_STRING_MAX_LENGTH + 1]
      #ifdef MPLLIBS_USE_CONSTEXPR
        = {BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C), 0}
      #endif
        ;
    };

    template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C)>
    MPLLIBS_CONSTEXPR const char
      c_str<
        mpllibs::metaparse::string<
          BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C)
        >
      >::value[MPLLIBS_STRING_MAX_LENGTH + 1]
      #ifndef MPLLIBS_USE_CONSTEXPR
        = {BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C), 0}
      #endif
        ;

    template <>
    struct c_str<mpllibs::metaparse::string<> > :
      mpllibs::metaparse::impl::empty_string<>
    {
      typedef c_str type;
    };

    #ifdef MPLLIBS_DEF
      #error MPLLIBS_DEF already defined
    #endif
    #define MPLLIBS_DEF(n) = {BOOST_PP_ENUM_PARAMS(n, C) BOOST_PP_COMMA_IF(n) 0}

    #ifdef MPLLIBS_STRING_DECLARE
      #error MPLLIBS_STRING_DECLARE already defined
    #endif
    #ifdef MPLLIBS_STRING_DEFINE
      #error MPLLIBS_STRING_DECLARE already defined
    #endif
    #ifdef MPLLIBS_USE_CONSTEXPR
      #define MPLLIBS_STRING_DECLARE(n) MPLLIBS_DEF(n)
      #define MPLLIBS_STRING_DEFINE(n)
    #else
      #define MPLLIBS_STRING_DECLARE(n)
      #define MPLLIBS_STRING_DEFINE(n) MPLLIBS_DEF(n)
    #endif

    #ifdef MPLLIBS_STRING_CASE
      #error MPLLIBS_STRING_CASE is already defined
    #endif
    #define MPLLIBS_STRING_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, int C)> \
      struct \
        c_str< \
          mpllibs::metaparse::string< \
            BOOST_PP_ENUM_PARAMS(n, C) BOOST_PP_COMMA_IF(n) \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(MPLLIBS_STRING_MAX_LENGTH, n), \
              MPLLIBS_NO_CHAR BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > \
        > \
      { \
        typedef c_str type; \
        static MPLLIBS_CONSTEXPR const char value[n + 1] \
          MPLLIBS_STRING_DECLARE(n); \
      }; \
      \
      template <BOOST_PP_ENUM_PARAMS(n, int C)> \
      MPLLIBS_CONSTEXPR const char c_str< \
        mpllibs::metaparse::string< \
          BOOST_PP_ENUM_PARAMS(n, C) BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(MPLLIBS_STRING_MAX_LENGTH, n), \
            MPLLIBS_NO_CHAR BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > \
      >::value[n + 1] MPLLIBS_STRING_DEFINE(n);

    BOOST_PP_REPEAT_FROM_TO(
      1,
      MPLLIBS_STRING_MAX_LENGTH,
      MPLLIBS_STRING_CASE,
      ~
    )

    #undef MPLLIBS_STRING_CASE
    #undef MPLLIBS_STRING_DECLARE
    #undef MPLLIBS_STRING_DEFINE
    #undef MPLLIBS_DEF
#endif
  }
}

#endif

