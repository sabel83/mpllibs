#ifndef META_HS_TOKEN_HPP
#define META_HS_TOKEN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <ast.hpp>
#include <except_keywords.hpp>

#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/always_c.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/return_.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/foldlp.hpp>
#include <mpllibs/metaparse/alphanum.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/letter.hpp>
#include <mpllibs/metaparse/keyword.hpp>

#include <boost/mpl/lambda.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector.hpp>

namespace token
{
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::always_c<'+',mpllibs::metaparse::string<'.','+','.'> >
    >
    plus;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::always_c<'-',mpllibs::metaparse::string<'.','-','.'> >
    >
    minus;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::always_c<'*',mpllibs::metaparse::string<'.','*','.'> >
    >
    mult;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::always_c<'/',mpllibs::metaparse::string<'.','/','.'> >
    >
    div;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::one_of<
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'='>,
          mpllibs::metaparse::lit_c<'='>,
          mpllibs::metaparse::return_<
            mpllibs::metaparse::string<'.','=','=','.'>
          >
        >,
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'/'>,
          mpllibs::metaparse::lit_c<'='>,
          mpllibs::metaparse::return_<
            mpllibs::metaparse::string<'.','/','=','.'>
          >
        >,
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'<'>,
          mpllibs::metaparse::one_of<
            mpllibs::metaparse::always_c<
              '=',
              mpllibs::metaparse::string<'.','<','=','.'>
            >,
            mpllibs::metaparse::return_<
              mpllibs::metaparse::string<'.','<','.'>
            >
          >
        >,
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'>'>,
          mpllibs::metaparse::one_of<
            mpllibs::metaparse::always_c<
              '=',
              mpllibs::metaparse::string<'.','>','=','.'>
            >,
            mpllibs::metaparse::return_<
              mpllibs::metaparse::string<'.','>','.'>
            >
          >
        >
      >
    >
    cmp;
  
  typedef
    mpllibs::metaparse::token<mpllibs::metaparse::lit_c<'('> >
    open_bracket;
  
  typedef
    mpllibs::metaparse::token<mpllibs::metaparse::lit_c<')'> >
    close_bracket;
  
  typedef
    mpllibs::metaparse::token<mpllibs::metaparse::lit_c<'='> >
    define;
  
  typedef mpllibs::metaparse::token<mpllibs::metaparse::int_> int_;
  
  typedef
    mpllibs::metaparse::token<
      except_keywords<
        mpllibs::metaparse::foldlp<
          mpllibs::metaparse::one_of<
            mpllibs::metaparse::alphanum,
            mpllibs::metaparse::lit_c<'_'>
          >,
          mpllibs::metaparse::transform<
            mpllibs::metaparse::one_of<
              mpllibs::metaparse::letter,
              mpllibs::metaparse::lit_c<'_'>
            >,
            boost::mpl::lambda<
              boost::mpl::push_back<
                mpllibs::metaparse::string<>,
                boost::mpl::_1
              >
            >::type
          >,
          boost::mpl::lambda<
            boost::mpl::push_back<boost::mpl::_1, boost::mpl::_2>
          >::type
        >,
        boost::mpl::vector<
          mpllibs::metaparse::string<'i','f'>,
          mpllibs::metaparse::string<'t','h','e','n'>,
          mpllibs::metaparse::string<'e','l','s','e'>
        >
      >
    >
    name;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::keyword<mpllibs::metaparse::string<'i','f'> >
    >
    if_;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::keyword<mpllibs::metaparse::string<'t','h','e','n'> >
    >
    then;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::keyword<mpllibs::metaparse::string<'e','l','s','e'> >
    >
    else_;
}

#endif


