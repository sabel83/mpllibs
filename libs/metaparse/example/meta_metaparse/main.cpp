// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_MPL_LIMIT_STRING_SIZE 64
#define MPLLIBS_STRING_MAX_LENGTH BOOST_MPL_LIMIT_STRING_SIZE

#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/build_parser.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/foldr1.hpp>
#include <mpllibs/metaparse/foldlp.hpp>
#include <mpllibs/metaparse/alphanum.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/lit.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/entire_input.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/int.hpp>
#include <mpllibs/metaparse/middle_of.hpp>
#include <mpllibs/metaparse/keyword.hpp>
#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/one_char_except_c.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/bool.hpp>

using boost::mpl::map;
using boost::mpl::eval_if;
using boost::mpl::insert;
using boost::mpl::pair;
using boost::mpl::apply_wrap1;
using boost::mpl::apply_wrap2;
using boost::mpl::size;
using boost::mpl::at;
using boost::mpl::push_front;
using boost::mpl::lambda;
using boost::mpl::c_str;
using boost::mpl::has_key;
using boost::mpl::front;
using boost::mpl::back;
using boost::mpl::if_;
using boost::mpl::bool_;

using mpllibs::metaparse::digit;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::any;
using mpllibs::metaparse::alphanum;
using mpllibs::metaparse::lit;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::one_of;
using mpllibs::metaparse::token;
using mpllibs::metaparse::foldlp;
using mpllibs::metaparse::entire_input;
using mpllibs::metaparse::transform;
using mpllibs::metaparse::sequence;
using mpllibs::metaparse::last_of;
using mpllibs::metaparse::int_;
using mpllibs::metaparse::middle_of;
using mpllibs::metaparse::keyword;
using mpllibs::metaparse::always;
using mpllibs::metaparse::one_char_except_c;

#ifdef BOOST_NO_CONSTEXPR
int main()
{
  std::cout << "Please use a compiler that supports constexpr" << std::endl;
}
#else

///////////////////////
// Parser parser

#ifdef _S
  #error _S already defined
#endif
#define _S MPLLIBS_STRING

/*
 * The grammar
 *
 * rule_definition ::= name_token define_token expression
 * expression ::= seq_expression (or_token seq_expression)*
 * seq_expression ::= name_expression+
 * name_expression ::= (char_token | name_token | open_bracket_token expression close_bracket_token) repeat_token*
 */

struct build_repeat
{
  typedef build_repeat type;

  template <class FState>
  struct apply_impl
  {
    typedef apply_impl type;

    template <class G>
    struct apply : any<typename apply_wrap1<FState, G>::type> {};
  };

  template <class T, class FState>
  struct apply : apply_impl<FState> {};
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
      sequence<
        typename apply_wrap1<FState, G>::type,
        typename apply_wrap1<FP, G>::type
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
      one_of<
        typename apply_wrap1<FState, G>::type,
        typename apply_wrap1<FP, G>::type
      >
    {};
  };

  template <class FP, class FState>
  struct apply : apply_impl<FP, FState> {};
};

template <class G, class Name>
struct get_parser
{
  typedef apply_wrap1<typename at<typename G::rules, Name>::type, G> p;

  template <class Actions>
  struct impl : transform<typename p::type, typename Actions::type> {};

  typedef
    typename eval_if<
      typename has_key<typename G::actions, Name>::type,
      impl<at<typename G::actions, Name>>,
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
    struct apply : lit<C> {};
  };

  template <class C>
  struct apply : apply_impl<C> {};
};

typedef token<lit_c<'*'>> repeat_token;
typedef token<lit_c<'|'>> or_token;
typedef token<lit_c<'('>> open_bracket_token;
typedef token<lit_c<')'>> close_bracket_token;
typedef token<keyword<boost::mpl::string<':',':','='>>> define_token;
typedef
  middle_of<
    lit_c<'\''>,
    one_of<
      last_of<
        lit_c<'\\'>,
        one_of<
          always<lit_c<'n'>, boost::mpl::char_<'\n'>>,
          always<lit_c<'r'>, boost::mpl::char_<'\r'>>,
          always<lit_c<'t'>, boost::mpl::char_<'\t'>>,
          lit_c<'\\'>,
          lit_c<'\''>
        >
      >,
      one_char_except_c<'\''>
    >,
    token<lit_c<'\''>>
  >
  char_token;

typedef
  token<
    mpllibs::metaparse::foldr1<
      one_of<alphanum, lit_c<'_'>>,
      boost::mpl::string<>,
      lambda<push_front<boost::mpl::_2, boost::mpl::_1>>::type
    >
  >
  name_token;

struct expression;

typedef
  foldlp<
    repeat_token,
    one_of<
      transform<char_token, build_char>,
      transform<name_token, build_name>,
      middle_of<open_bracket_token, expression, close_bracket_token>
    >,
    build_repeat
  >
  name_expression;

typedef foldlp<name_expression, name_expression, build_sequence> seq_expression;

struct expression :
  foldlp<last_of<or_token, seq_expression>, seq_expression, build_selection>
{};

typedef sequence<name_token, define_token, expression> rule_definition;

typedef build_parser<entire_input<rule_definition>> parser_parser;

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
  typedef typename apply_wrap1<parser_parser, S>::type p;
  typedef typename front<p>::type name;
  typedef typename back<p>::type exp;

  struct the_parser
  {
    typedef the_parser type;

    template <class G>
    struct apply : apply_wrap1<exp, G> {};
  };

  typedef pair<name, the_parser> type;
};

typedef build_parser<name_token> name_parser;

template <class S>
struct rebuild : apply_wrap1<name_parser, S> {};

struct no_action;

template <class G, class P, class F>
struct add_rule;

template <class G, class Name, class P, class F>
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
    apply_wrap2<
      typename get_parser<grammar_builder, typename rebuild<Start>::type>::type,
      S,
      Pos
    >
  {};

  template <class Name, class P, class Action = no_action>
  struct import :
    add_import<grammar_builder, typename rebuild<Name>::type, P, Action>
  {};

  template <class Def, class Action = no_action>
  struct rule : add_rule<grammar_builder, build_parsed_parser<Def>, Action> {};
};

template <class Start, class Rules, class Actions, class P>
struct add_rule<grammar_builder<Start, Rules, Actions>, P, no_action> :
  grammar_builder<
    Start,
    typename insert<Rules, typename P::type>::type,
    Actions
  >
{};

template <class Start, class Rules, class Actions, class P, class F>
struct add_rule<grammar_builder<Start, Rules, Actions>, P, F> :
  grammar_builder<
    Start,
    typename insert<Rules, typename P::type>::type,
    typename insert<Actions, pair<typename P::name, F>>::type
  >
{};

template <class Start, class Rules, class Actions, class Name, class P>
struct add_import<grammar_builder<Start, Rules, Actions>, Name, P, no_action> :
  grammar_builder<
    Start,
    typename insert<Rules, pair<Name, build_native_parser<P>>>::type,
    Actions
  >
{};

template <class Start, class Rules, class Actions, class Name, class P, class F>
struct add_import<grammar_builder<Start, Rules, Actions>, Name, P, F> :
  grammar_builder<
    Start,
    typename insert<Rules, pair<Name, build_native_parser<P>>>::type,
    typename insert<Actions, pair<Name, F>>::type
  >
{};

template <class Start = boost::mpl::string<'S'> >
struct grammar : grammar_builder<Start, map<>, map<> > {};

///////////////////////
// Real parser

template <class T, char C>
struct is_c : bool_<T::type::value == C> {};

struct build_plus_impl
{
  template <class A, class B>
  class _plus
  {
  public:
    typedef _plus type;

    template <class T>
    T operator()(T t) const
    {
      return _left(t) + _right(t);
    }
  private:
    typename A::type _left;
    typename B::type _right;
  };

  template <class A, class B>
  class _minus
  {
  public:
    typedef _minus type;

    template <class T>
    T operator()(T t) const
    {
      return _left(t) - _right(t);
    }
  private:
    typename A::type _left;
    typename B::type _right;
  };

  template <class State, class C>
  struct apply :
    if_<
      typename is_c<front<C>, '+'>::type,
      _plus<State, typename back<C>::type>,
      _minus<State, typename back<C>::type>
    >
  {};
};

struct build_plus
{
  typedef build_plus type;

  template <class Seq>
  struct apply :
    boost::mpl::fold<
      typename back<Seq>::type,
      typename front<Seq>::type,
      build_plus_impl
    >
  {};
};

struct build_mult_impl
{
  template <class A, class B>
  class _mult
  {
  public:
    typedef _mult type;

    template <class T>
    T operator()(T t) const
    {
      return _left(t) * _right(t);
    }
  private:
    typename A::type _left;
    typename B::type _right;
  };

  template <class A, class B>
  class _div
  {
  public:
    typedef _div type;

    template <class T>
    T operator()(T t) const
    {
      return _left(t) / _right(t);
    }
  private:
    typename A::type _left;
    typename B::type _right;
  };

  template <class State, class C>
  struct apply :
    if_<
      typename is_c<front<C>, '*'>::type,
      _mult<State, typename back<C>::type>,
      _div<State, typename back<C>::type>
    >
  {};
};

struct build_mult
{
  typedef build_mult type;

  template <class Seq>
  struct apply :
    boost::mpl::fold<
      typename back<Seq>::type,
      typename front<Seq>::type,
      build_mult_impl
    >
  {};
};

struct build_value
{
  typedef build_value type;

  template <class V>
  struct apply
  {
    typedef apply type;

    template <class T>
    int operator()(T) const
    {
      return V::type::value;
    }
  };
};

struct build_arg
{
  typedef build_arg type;

  template <class>
  struct apply
  {
    typedef apply type;
  
    template <class T>
    T operator()(T t) const
    {
      return t;
    }
  };
};

struct keep_front
{
  typedef keep_front type;

  template <class Seq>
  struct apply : front<Seq> {};
};

typedef
  grammar<_S("plus_exp")>
    ::import<_S("int_token"), token<int_>, build_value>::type

    ::rule<_S("ws ::= (' ' | '\n' | '\r' | '\t')*")>::type
    ::rule<_S("plus_token ::= '+' ws"), keep_front>::type
    ::rule<_S("minus_token ::= '-' ws"), keep_front>::type
    ::rule<_S("mult_token ::= '*' ws"), keep_front>::type
    ::rule<_S("div_token ::= '/' ws"), keep_front>::type
    ::rule<_S("arg_token ::= '_' ws"), keep_front>::type

    ::rule<_S("plus_exp ::= prod_exp ((plus_token | minus_token) prod_exp)*"), build_plus>::type
    ::rule<_S("prod_exp ::= value_exp ((mult_token | div_token) value_exp)*"), build_mult>::type
    ::rule<_S("value_exp ::= int_token | arg_exp")>::type
    ::rule<_S("arg_exp ::= arg_token"), build_arg>::type
  g;

typedef build_parser<entire_input<g>> function_parser;

#ifdef LAMBDA
  #error LAMBDA already defined
#endif
#define LAMBDA(exp) apply_wrap1<function_parser, MPLLIBS_STRING(#exp)>::type

LAMBDA(13) f1;
LAMBDA(2 + 3) f2;
LAMBDA(2 * 3) f3;
LAMBDA(1+ 2*4-6/2) f4;
LAMBDA(2 * _) f5;

int main()
{
  using std::cout;
  using std::endl;

  cout
    << f1(11) << endl
    << f2(11) << endl
    << f3(11) << endl
    << f4(11) << endl
    << f5(11) << endl
    << f5(1.1) << endl
    ;
}

#endif


