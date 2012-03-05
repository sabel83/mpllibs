#ifndef META_HS_GRAMMAR_HPP
#define META_HS_GRAMMAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <token.hpp>
#include <semantic.hpp>

#include <mpllibs/metaparse/middle_of.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/foldlp.hpp>
#include <mpllibs/metaparse/foldrp.hpp>
#include <mpllibs/metaparse/entire_input.hpp>
#include <mpllibs/metaparse/build_parser.hpp>

namespace grammar
{
  /*
   * The grammar
   *
   * definition ::= token::name+ token::define expression
   * expression ::= cmp_exp
   * cmp_exp ::= plus_exp (token::cmp plus_exp)*
   * plus_exp ::= mult_exp ((token::plus | token::minus) mult_exp)*
   * mult_exp ::= application ((token::mult | token::div) application)*
   * application ::= single_exp+
   * single_exp ::= if_exp | token::name | token::int_ | bracket_exp
   * if_exp ::= token::if_ expression token::then expression token::else_ expression
   * bracket_exp ::= token::open_bracket expression token::close_bracket
   */
  
  struct expression;
  
  typedef
    mpllibs::metaparse::middle_of<
      token::open_bracket,
      expression,
      token::close_bracket
    >
    bracket_exp;
  
  typedef
    mpllibs::metaparse::transform<
      mpllibs::metaparse::sequence<
        mpllibs::metaparse::last_of<token::if_, expression>,
        mpllibs::metaparse::last_of<token::then, expression>,
        mpllibs::metaparse::last_of<token::else_, expression>
      >,
      semantic::if_
    >
    if_exp;
  
  typedef
    mpllibs::metaparse::one_of<
      if_exp,
      mpllibs::metaparse::transform<token::name, semantic::ref>,
      mpllibs::metaparse::transform<token::int_, semantic::value>,
      bracket_exp
    >
    single_exp;
  
  typedef
    mpllibs::metaparse::foldlp<single_exp, single_exp, semantic::application>
    application;
  
  typedef
    mpllibs::metaparse::foldlp<
      mpllibs::metaparse::sequence<
        mpllibs::metaparse::one_of<token::mult, token::div>,
        application
      >,
      application,
      semantic::binary_op
    >
    mult_exp;
  
  typedef
    mpllibs::metaparse::foldlp<
      mpllibs::metaparse::sequence<
        mpllibs::metaparse::one_of<token::plus, token::minus>,
        mult_exp
      >,
      mult_exp,
      semantic::binary_op
    >
    plus_exp;
  
  typedef
    mpllibs::metaparse::foldlp<
      mpllibs::metaparse::sequence<token::cmp, plus_exp>,
      plus_exp,
      semantic::binary_op
    >
    cmp_exp;
  
  struct expression : cmp_exp {};
  
  typedef
    mpllibs::metaparse::transform<
      mpllibs::metaparse::sequence<
        token::name,
        mpllibs::metaparse::foldrp<
          token::name,
          mpllibs::metaparse::last_of<token::define, expression>,
          semantic::lambda
        >
      >,
      semantic::pair
    >
    definition;
  
  typedef
    mpllibs::metaparse::build_parser<
      mpllibs::metaparse::entire_input<definition>
    >
    def_parser;
}

#endif

