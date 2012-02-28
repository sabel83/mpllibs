#ifndef MPLLIBS_METAPARSE_GRAMMAR_HPP
#define MPLLIBS_METAPARSE_GRAMMAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/any1.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/lit.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/keyword.hpp>
#include <mpllibs/metaparse/middle_of.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/one_char_except_c.hpp>
#include <mpllibs/metaparse/foldr1.hpp>
#include <mpllibs/metaparse/foldlp.hpp>
#include <mpllibs/metaparse/alphanum.hpp>
#include <mpllibs/metaparse/build_parser.hpp>
#include <mpllibs/metaparse/entire_input.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/insert.hpp>

/*
 * The grammar
 *
 * rule_definition ::= name_token define_token expression
 * expression ::= seq_expression (or_token seq_expression)*
 * seq_expression ::= repeat_expression+
 * repeat_expression ::= name_expression (repeat_token | repeat1_token)*
 * name_expression ::= char_token | name_token | bracket_expression
 * bracket_expression ::= open_bracket_token expression close_bracket_token
 */

namespace mpllibs
{
  namespace metaparse
  {
    namespace grammar_util
    {
      template <char Op, class FState>
      struct repeat_apply_impl
      {
        typedef repeat_apply_impl type;
      
        template <class G>
        struct apply :
          mpllibs::metaparse::any<
            typename boost::mpl::apply_wrap1<FState, G>::type
          >
        {};
      };

      template <class FState>
      struct repeat_apply_impl<'+', FState>
      {
        typedef repeat_apply_impl type;
      
        template <class G>
        struct apply :
          mpllibs::metaparse::any1<
            typename boost::mpl::apply_wrap1<FState, G>::type
          >
        {};
      };

      struct build_repeat
      {
        typedef build_repeat type;
      
        template <class T, class FState>
        struct apply : repeat_apply_impl<T::type::value, FState> {};
      };
      
      struct build_sequence
      {
        typedef build_sequence type;
      
        template <class FP, class FState>
        struct apply_impl
        {
          typedef apply_impl type;
      
          template <class G>
          struct apply :
            mpllibs::metaparse::sequence<
              typename boost::mpl::apply_wrap1<FState, G>::type,
              typename boost::mpl::apply_wrap1<FP, G>::type
            >
          {};
        };
      
        template <class FP, class FState>
        struct apply : apply_impl<FP, FState> {};
      };
      
      struct build_selection
      {
        typedef build_selection type;
      
        template <class FP, class FState>
        struct apply_impl
        {
          typedef apply_impl type;
      
          template <class G>
          struct apply :
            mpllibs::metaparse::one_of<
              typename boost::mpl::apply_wrap1<FState, G>::type,
              typename boost::mpl::apply_wrap1<FP, G>::type
            >
          {};
        };
      
        template <class FP, class FState>
        struct apply : apply_impl<FP, FState> {};
      };
      
      template <class G, class Name>
      struct get_parser
      {
        typedef
          boost::mpl::apply_wrap1<
            typename boost::mpl::at<typename G::rules, Name>::type,
            G
          >
          p;
      
        template <class Actions>
        struct impl :
          mpllibs::metaparse::transform<
            typename p::type,
            typename Actions::type
          >
        {};
      
        typedef
          typename boost::mpl::eval_if<
            typename boost::mpl::has_key<typename G::actions, Name>::type,
            impl<boost::mpl::at<typename G::actions, Name> >,
            p
          >::type
          type;
      };
      
      struct build_name
      {
        typedef build_name type;
      
        template <class Name>
        struct apply_impl
        {
          typedef apply_impl type;
      
          template <class G>
          struct apply : get_parser<G, Name> {};
        };
      
        template <class Name>
        struct apply : apply_impl<Name> {};
      };
      
      struct build_char
      {
        typedef build_char type;
      
        template <class C>
        struct apply_impl
        {
          typedef apply_impl type;
      
          template <class G>
          struct apply : mpllibs::metaparse::lit<C> {};
        };
      
        template <class C>
        struct apply : apply_impl<C> {};
      };
      
      typedef
        mpllibs::metaparse::token<mpllibs::metaparse::lit_c<'*'> >
        repeat_token;

      typedef
        mpllibs::metaparse::token<mpllibs::metaparse::lit_c<'+'> >
        repeat1_token;

      typedef
        mpllibs::metaparse::token<mpllibs::metaparse::lit_c<'|'> >
        or_token;

      typedef
        mpllibs::metaparse::token<mpllibs::metaparse::lit_c<'('> >
        open_bracket_token;

      typedef
        mpllibs::metaparse::token<mpllibs::metaparse::lit_c<')'> >
        close_bracket_token;

      typedef
        mpllibs::metaparse::token<
          mpllibs::metaparse::keyword<boost::mpl::string<':',':','='> >
        >
        define_token;

      typedef
        mpllibs::metaparse::middle_of<
          mpllibs::metaparse::lit_c<'\''>,
          mpllibs::metaparse::one_of<
            mpllibs::metaparse::last_of<
              mpllibs::metaparse::lit_c<'\\'>,
              mpllibs::metaparse::one_of<
                mpllibs::metaparse::always<
                  mpllibs::metaparse::lit_c<'n'>,
                  boost::mpl::char_<'\n'>
                >,
                mpllibs::metaparse::always<
                  mpllibs::metaparse::lit_c<'r'>,
                  boost::mpl::char_<'\r'>
                >,
                mpllibs::metaparse::always<
                  mpllibs::metaparse::lit_c<'t'>,
                  boost::mpl::char_<'\t'>
                >,
                mpllibs::metaparse::lit_c<'\\'>,
                mpllibs::metaparse::lit_c<'\''>
              >
            >,
            mpllibs::metaparse::one_char_except_c<'\''>
          >,
          mpllibs::metaparse::token<mpllibs::metaparse::lit_c<'\''> >
        >
        char_token;
      
      typedef
        mpllibs::metaparse::token<
          mpllibs::metaparse::foldr1<
            mpllibs::metaparse::one_of<
              mpllibs::metaparse::alphanum,
              mpllibs::metaparse::lit_c<'_'>
            >,
            boost::mpl::string<>,
            boost::mpl::lambda<
              boost::mpl::push_front<boost::mpl::_2, boost::mpl::_1>
            >::type
          >
        >
        name_token;
      
      struct expression;
      
      typedef
        mpllibs::metaparse::middle_of<
          open_bracket_token,
          expression,
          close_bracket_token
        >
        bracket_expression;

      typedef
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::transform<char_token, build_char>,
          mpllibs::metaparse::transform<name_token, build_name>,
          bracket_expression
        >
        name_expression;

      typedef
        mpllibs::metaparse::foldlp<
          mpllibs::metaparse::one_of<repeat_token, repeat1_token>,
          name_expression,
          build_repeat
        >
        repeat_expression;
      
      typedef
        mpllibs::metaparse::foldlp<
          repeat_expression,
          repeat_expression,
          build_sequence
        >
        seq_expression;
      
      struct expression :
        mpllibs::metaparse::foldlp<
          mpllibs::metaparse::last_of<or_token, seq_expression>,
          seq_expression,
          build_selection
        >
      {};
      
      typedef
        mpllibs::metaparse::sequence<name_token, define_token, expression>
        rule_definition;
      
      typedef
        mpllibs::metaparse::build_parser<
          mpllibs::metaparse::entire_input<rule_definition>
        >
        parser_parser;
      
      template <class P>
      struct build_native_parser
      {
        typedef build_native_parser type;
      
        template <class G>
        struct apply
        {
          typedef P type;
        };
      };
      
      template <class S>
      struct build_parsed_parser
      {
        typedef typename boost::mpl::apply_wrap1<parser_parser, S>::type p;
        typedef typename boost::mpl::front<p>::type name;
        typedef typename boost::mpl::back<p>::type exp;
      
        struct the_parser
        {
          typedef the_parser type;
      
          template <class G>
          struct apply : boost::mpl::apply_wrap1<exp, G> {};
        };
      
        typedef boost::mpl::pair<name, the_parser> type;
      };
      
      typedef mpllibs::metaparse::build_parser<name_token> name_parser;
      
      template <class S>
      struct rebuild : boost::mpl::apply_wrap1<name_parser, S> {};
      
      struct no_action;
      
      template <class G, class P, class F>
      struct add_rule;
      
      template <class G, class Name, class P>
      struct add_import;
      
      template <class Start, class Rules, class Actions>
      struct grammar_builder
      {
        typedef grammar_builder type;
        typedef Rules rules;
        typedef Actions actions;
      
        // Make it a parser
        template <class S, class Pos>
        struct apply :
          boost::mpl::apply_wrap2<
            typename get_parser<
              grammar_builder,
              typename rebuild<Start>::type
            >::type,
            S,
            Pos
          >
        {};
      
        template <class Name, class P>
        struct import :
          add_import<grammar_builder, typename rebuild<Name>::type, P>
        {};
      
        template <class Def, class Action = no_action>
        struct rule :
          add_rule<grammar_builder, build_parsed_parser<Def>, Action>
        {};
      };
      
      template <class Start, class Rules, class Actions, class P>
      struct add_rule<grammar_builder<Start, Rules, Actions>, P, no_action> :
        grammar_builder<
          Start,
          typename boost::mpl::insert<Rules, typename P::type>::type,
          Actions
        >
      {};
      
      template <class Start, class Rules, class Actions, class P, class F>
      struct add_rule<grammar_builder<Start, Rules, Actions>, P, F> :
        grammar_builder<
          Start,
          typename boost::mpl::insert<Rules, typename P::type>::type,
          typename boost::mpl::insert<
            Actions,
            boost::mpl::pair<
              typename P::name,
              typename boost::mpl::lambda<F>::type
            >
          >
          ::type
        >
      {};
      
      template <class Start, class Rules, class Actions, class Name, class P>
      struct add_import<grammar_builder<Start, Rules, Actions>, Name, P> :
        grammar_builder<
          Start,
          typename boost::mpl::insert<
            Rules,
            boost::mpl::pair<Name, build_native_parser<P> >
          >::type,
          Actions
        >
      {};
    }

    template <class Start = boost::mpl::string<'S'> >
    struct grammar :
      grammar_util::grammar_builder<
        Start,
        boost::mpl::map<>,
        boost::mpl::map<>
      >
    {};
  }
}

#endif
