#ifndef META_HS_EXCEPT_BUILDER_HPP
#define META_HS_EXCEPT_BUILDER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <grammar.hpp>
#include <ast.hpp>
#include <bind.hpp>

#include <mpllibs/metaparse/util/curry.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

typedef boost::mpl::map<> empty_environment;

template <class Env = empty_environment>
struct builder
{
  typedef builder type;

  template <class Name, class Value>
  struct import :
    builder<
      typename boost::mpl::insert<
        Env,
        boost::mpl::pair<Name, ast::value<Value> >
      >::type
    >
  {};

#ifdef DEF_CLASS
  #error DEF_CLASS already defined
#endif
#define DEF_CLASS(z, n, unused) BOOST_PP_COMMA_IF(n) class

#ifdef IMPORT
  #error IMPORT already defined
#endif
#define IMPORT(z, n, unused) \
  template <class Name, template <BOOST_PP_REPEAT(n, DEF_CLASS, ~)> class F> \
  struct BOOST_PP_CAT(import, n) : \
    builder< \
      typename boost::mpl::insert< \
        Env, \
        boost::mpl::pair< \
          Name, \
          ast::value<BOOST_PP_CAT(mpllibs::metaparse::util::curry, n)<F> > \
        > \
      >::type \
    > \
  {};

BOOST_PP_REPEAT_FROM_TO(1, MPLLIBS_CURRY_MAX_ARGUMENT, IMPORT, ~)

#undef IMPORT
#undef DEF_CLASS

  template <class S>
  struct define :
    builder<
      typename boost::mpl::insert<
        Env,
        typename boost::mpl::apply_wrap1<grammar::def_parser, S>::type
      >::type
    >
  {};

  template <class S>
  struct get :
    bind<typename boost::mpl::at<Env, S>::type, Env, Env>::type::type
  {};
};

#endif

