#ifndef MPLLIBS_METAPARSE_STRING_HPP
#define MPLLIBS_METAPARSE_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/config.hpp>

#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/char.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/equal.hpp>

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/less.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

#include <boost/type_traits/is_same.hpp>

#include <cstdio>

#ifndef MPLLIBS_STRING_MAX_LENGTH
  #define MPLLIBS_STRING_MAX_LENGTH 32
#endif

namespace mpllibs
{
  namespace metaparse
  {
    // string_tag

    struct string_tag
    {
      typedef string_tag type;
    };

    // string

    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(MPLLIBS_STRING_MAX_LENGTH, int C, EOF)
    >
    struct string
    {
      typedef string type;
      typedef string_tag tag;
    };

    namespace impl
    {
      template <class Ignore = int>
      struct empty_string
      {
        static const char value[1];
      };

      template <class Ignore>
      const char empty_string<Ignore>::value[1] = {0};
    }

    template <class S, int Removed>
    struct string_suffix
    {
      typedef string_suffix type;
      typedef string_tag tag;
    };

    // at_c

    template <class S, int N>
    struct at_c;

    #ifdef MPLLIBS_STRING_CASE
      #error MPLLIBS_STRING_CASE is already defined
    #endif
    #define MPLLIBS_STRING_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C)> \
      struct at_c<string<BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH,C)>,n>:\
        boost::mpl::char_<BOOST_PP_CAT(C, n)> \
      {};
    
    BOOST_PP_REPEAT(MPLLIBS_STRING_MAX_LENGTH, MPLLIBS_STRING_CASE, ~)

    #undef MPLLIBS_STRING_CASE

    // size

    template <class S>
    struct size;

    #ifdef MPLLIBS_STRING_CASE
      #error MPLLIBS_STRING_CASE
    #endif
    #define MPLLIBS_STRING_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, int C)> \
      struct \
        size< \
          string< \
            BOOST_PP_ENUM_PARAMS(n, C) BOOST_PP_COMMA_IF(n) \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(MPLLIBS_STRING_MAX_LENGTH, n), \
              EOF BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > \
        > : \
        boost::mpl::int_<n> \
      {};

    BOOST_PP_REPEAT(MPLLIBS_STRING_MAX_LENGTH, MPLLIBS_STRING_CASE, ~)

    #undef MPLLIBS_STRING_CASE

    // string_iterator

    struct string_iterator_tag
    {
      typedef string_iterator_tag type;
    };

    template <class S, int N>
    struct string_iterator
    {
      typedef string_iterator type;
      typedef string_iterator_tag tag;
      typedef boost::mpl::random_access_iterator_tag category;
    };

    // advance_c

    template <class S, int N>
    struct advance_c;

    template <class S, int N, int P>
    struct advance_c<string_iterator<S, N>, P> : string_iterator<S, N + P> {};

    // distance

    template <class A, class B>
    struct distance;

    template <class S, int A, int B>
    struct distance<string_iterator<S, A>, string_iterator<S, B> > :
      boost::mpl::int_<B - A>
    {};

    // pop_front

    template <class S>
    struct pop_front;

    #ifdef MPLLIBS_POP_FRONT
      #error MPLLIBS_POP_FRONT already defined
    #endif
    #define MPLLIBS_POP_FRONT(z, n, unused) \
      BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) BOOST_PP_CAT(C, n)

    template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C)>
    struct
      pop_front<
        string<BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C)>
      > :
      string<
        BOOST_PP_REPEAT_FROM_TO(
          1,
          MPLLIBS_STRING_MAX_LENGTH,
          MPLLIBS_POP_FRONT,
          ~
        ),
        EOF
      >
    {};

    #undef MPLLIBS_POP_FRONT

    // push_front

    template <class S, char C>
    struct push_front_c;

    template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C), char Ch>
    struct push_front_c<
      string<BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C)>,
      Ch
    > :
      string<
        Ch,
        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(MPLLIBS_STRING_MAX_LENGTH), C)
      >
    {};

    template <class S, int Removed, char C>
    struct push_front_c<string_suffix<S, Removed>, C> :
      push_front_c<typename string_suffix<S, Removed>::type, C>
    {};

    // update

    template <class S, int N, char C>
    struct update_c;

    #ifdef MPLLIBS_ARGN
      #error MPLLIBS_ARGN already defined
    #endif
    #define MPLLIBS_ARGN(z, n, unused) , BOOST_PP_CAT(C, n)

    #ifdef MPLLIBS_UPDATE
      #error MPLLIBS_UPDATE already defined
    #endif
    #define MPLLIBS_UPDATE(z, n, unused) \
      template < \
        BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C), \
        char Ch \
      > \
      struct update_c< \
        string<BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C)>, \
        n, \
        Ch \
      > : \
        string< \
          BOOST_PP_ENUM_PARAMS(n, C) BOOST_PP_COMMA_IF(n) \
          Ch \
          BOOST_PP_REPEAT_FROM_TO( \
            BOOST_PP_INC(n), \
            BOOST_PP_DEC(MPLLIBS_STRING_MAX_LENGTH), \
            MPLLIBS_ARGN, \
            ~ \
          ) \
        > \
      {};

    BOOST_PP_REPEAT(MPLLIBS_STRING_MAX_LENGTH, MPLLIBS_UPDATE, ~)

    #undef MPLLIBS_UPDATE
    #undef MPLLIBS_ARGN

#ifndef BOOST_NO_CONSTEXPR
    namespace impl
    {
      template <int Len, class T>
      constexpr int string_at(const T (&s)[Len], int n)
      {
        return n >= Len - 1 ? EOF : s[n];
      }
    }
#endif
  }
}

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
        mpllibs::metaparse::update_c<
          typename S::type,
          mpllibs::metaparse::size<typename S::type>::type::value,
          C::type::value
        >
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
      struct apply :
        mpllibs::metaparse::update_c<
          typename S::type,
          mpllibs::metaparse::size<typename S::type>::type::value - 1,
          EOF
        >
      {};
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
        mpllibs::metaparse::push_front_c<typename S::type, C::type::value>
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
      struct apply : mpllibs::metaparse::pop_front<S> {};
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
        mpllibs::metaparse::string_iterator<typename S::type, 0>
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
        mpllibs::metaparse::string_iterator<
          typename S::type,
          mpllibs::metaparse::size<typename S::type>::type::value
        >
      {};
    };

    // advance
    template <class S>
    struct advance_impl;

    template <>
    struct advance_impl<mpllibs::metaparse::string_iterator_tag>
    {
      typedef advance_impl type;

      template <class S, class N>
      struct apply :
        mpllibs::metaparse::advance_c<typename S::type, N::type::value>
      {};
    };

    // distance
    template <class S>
    struct distance_impl;

    template <>
    struct distance_impl<mpllibs::metaparse::string_iterator_tag>
    {
      typedef distance_impl type;

      template <class A, class B>
      struct apply :
        mpllibs::metaparse::distance<typename A::type, typename B::type>
      {};
    };

    // next
    template <class S>
    struct next;

    template <class S, int N>
    struct next<mpllibs::metaparse::string_iterator<S, N> > :
      mpllibs::metaparse::string_iterator<S, N + 1>
    {};

    // prior
    template <class S>
    struct prior;

    template <class S, int N>
    struct prior<mpllibs::metaparse::string_iterator<S, N> > :
      mpllibs::metaparse::string_iterator<S, N - 1>
    {};

    // deref
    template <class S>
    struct deref;

    template <class S, int N>
    struct deref<mpllibs::metaparse::string_iterator<S, N> > :
      mpllibs::metaparse::at_c<S, N>
    {};

    // equal_to
    template <class A, class B>
    struct equal_to_impl;

    #ifdef MPLLIBS_EQUAL_TO
      #error MPLLIBS_EQUAL_TO already defined
    #endif
    #define MPLLIBS_EQUAL_TO(T) \
      template <class X> \
      struct equal_to_impl<T, X> \
      { \
        typedef equal_to_impl type; \
        \
        template <class, class> \
        struct apply : false_ {}; \
      }; \
      \
      template <class X> \
      struct equal_to_impl<X, T> : equal_to_impl<T, X> {}

    template <>
    struct equal_to_impl<
      mpllibs::metaparse::string_iterator_tag,
      mpllibs::metaparse::string_iterator_tag
    >
    {
      typedef equal_to_impl type;

      template <class A, class B>
      struct apply : is_same<typename A::type, typename B::type> {};
    };
    
    MPLLIBS_EQUAL_TO(mpllibs::metaparse::string_iterator_tag);

    template <>
    struct equal_to_impl<
      mpllibs::metaparse::string_tag,
      mpllibs::metaparse::string_tag
    >
    {
      typedef equal_to_impl type;

      template <class A, class B>
      struct apply : boost::mpl::equal<typename A::type, typename B::type> {};
    };

    MPLLIBS_EQUAL_TO(mpllibs::metaparse::string_tag);

    #undef MPLLIBS_EQUAL_TO

    // c_str
    template <class S>
    struct c_str;

    template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C)>
    struct c_str<
      mpllibs::metaparse::string<
        BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C)
      >
    >
    {
      typedef c_str type;
      static const char value[MPLLIBS_STRING_MAX_LENGTH + 1];
    };

    template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C)>
    const char
      c_str<
        mpllibs::metaparse::string<
          BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C)
        >
      >::value[MPLLIBS_STRING_MAX_LENGTH + 1] =
        {BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C), 0};

    template <>
    struct c_str<mpllibs::metaparse::string<> > :
      mpllibs::metaparse::impl::empty_string<>
    {
      typedef c_str type;
    };

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
              EOF BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > \
        > \
      { \
        typedef c_str type; \
        static const char value[n + 1]; \
      }; \
      \
      template <BOOST_PP_ENUM_PARAMS(n, int C)> \
      const char c_str< \
        mpllibs::metaparse::string< \
          BOOST_PP_ENUM_PARAMS(n, C) BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(MPLLIBS_STRING_MAX_LENGTH, n), \
            EOF BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > \
      >::value[n + 1] = {BOOST_PP_ENUM_PARAMS(n, C) BOOST_PP_COMMA_IF(n) 0}; \

    BOOST_PP_REPEAT_FROM_TO(
      1,
      MPLLIBS_STRING_MAX_LENGTH,
      MPLLIBS_STRING_CASE,
      ~
    )

    #undef MPLLIBS_STRING_CASE

    template <class S, int Removed>
    struct c_str<mpllibs::metaparse::string_suffix<S, Removed> > :
      mpllibs::metaparse::string_suffix<S, Removed>
    {};
  }
}

#ifdef BOOST_NO_CONSTEXPR

  // Include it only when it is needed
  #include <boost/static_assert.hpp>

  #ifdef MPLLIBS_STRING
    #error MPLLIBS_STRING already defined
  #endif
  #define MPLLIBS_STRING(s) \
    BOOST_STATIC_ASSERT_MSG(false, "MPLLIBS_STRING is not supported")

#else

  #ifdef MPLLIBS_STRING_N
    #error MPLLIBS_STRING_N already defined
  #endif
  #define MPLLIBS_STRING_N(z, n, s) mpllibs::metaparse::impl::string_at((s), n)

  #ifdef MPLLIBS_STRING
    #error MPLLIBS_STRING already defined
  #endif
  #define MPLLIBS_STRING(s) \
    mpllibs::metaparse::string< \
      BOOST_PP_ENUM(MPLLIBS_STRING_MAX_LENGTH, MPLLIBS_STRING_N, s) \
    >

#endif

#endif

