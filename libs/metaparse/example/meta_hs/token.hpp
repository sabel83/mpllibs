#ifndef META_HS_TOKEN_HPP
#define META_HS_TOKEN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <ast.hpp>
#include <except_keywords.hpp>

#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/int.hpp>
#include <mpllibs/metaparse/foldlp.hpp>
#include <mpllibs/metaparse/alphanum.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/letter.hpp>
#include <mpllibs/metaparse/keyword.hpp>

#include <boost/mpl/string.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector.hpp>

namespace token
{
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::always<
        mpllibs::metaparse::lit_c<'+'>,
        boost::mpl::string<'.+.'>
      >
    >
    plus;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::always<
        mpllibs::metaparse::lit_c<'-'>,
        boost::mpl::string<'.-.'>
      >
    >
    minus;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::always<
        mpllibs::metaparse::lit_c<'*'>,
        boost::mpl::string<'.*.'>
      >
    >
    mult;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::always<
        mpllibs::metaparse::lit_c<'/'>,
        boost::mpl::string<'./.'>
      >
    >
    div;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::one_of<
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'='>,
          mpllibs::metaparse::lit_c<'='>,
          mpllibs::metaparse::return_<boost::mpl::string<'.==.'> >
        >,
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'/'>,
          mpllibs::metaparse::lit_c<'='>,
          mpllibs::metaparse::return_<boost::mpl::string<'./=.'> >
        >,
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'<'>,
          mpllibs::metaparse::one_of<
            mpllibs::metaparse::always<
              mpllibs::metaparse::lit_c<'='>,
              boost::mpl::string<'.<=.'>
            >,
            mpllibs::metaparse::return_<boost::mpl::string<'.<.'> >
          >
        >,
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'>'>,
          mpllibs::metaparse::one_of<
            mpllibs::metaparse::always<
              mpllibs::metaparse::lit_c<'='>,
              boost::mpl::string<'.>=.'>
            >,
            mpllibs::metaparse::return_<boost::mpl::string<'.>.'> >
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
              boost::mpl::push_back<boost::mpl::string<>, boost::mpl::_1>
            >::type
          >,
          boost::mpl::lambda<
            boost::mpl::push_back<boost::mpl::_2, boost::mpl::_1>
          >::type
        >,
        boost::mpl::vector<
          boost::mpl::string<'if'>,
          boost::mpl::string<'then'>,
          boost::mpl::string<'else'>
        >
      >
    >
    name;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::keyword<boost::mpl::string<'if'> >
    >
    if_;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::keyword<boost::mpl::string<'then'> >
    >
    then;
  
  typedef
    mpllibs::metaparse::token<
      mpllibs::metaparse::keyword<boost::mpl::string<'else'> >
    >
    else_;
}

#endif


