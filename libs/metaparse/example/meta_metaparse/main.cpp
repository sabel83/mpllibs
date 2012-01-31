// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/build_parser.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/foldr1.hpp>
#include <mpllibs/metaparse/foldlp.hpp>
#include <mpllibs/metaparse/alphanum.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/entire_input.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/int.hpp>

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
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::one_of;
using mpllibs::metaparse::token;
using mpllibs::metaparse::foldlp;
using mpllibs::metaparse::entire_input;
using mpllibs::metaparse::transform;
using mpllibs::metaparse::sequence;
using mpllibs::metaparse::last_of;
using mpllibs::metaparse::int_;

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
 * expression ::= seq_expression (or_token seq_expression)*
 * seq_expression ::= name_expression+
 * name_expression ::= name_token '*'*
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

typedef token<lit_c<'*'>> repeat_token;
typedef token<lit_c<'|'>> or_token;

typedef
  token<
    mpllibs::metaparse::foldr1<
      one_of<alphanum, lit_c<'_'>>,
      boost::mpl::string<>,
      lambda<push_front<boost::mpl::_2, boost::mpl::_1>>::type
    >
  >
  name_token;

typedef
  foldlp<repeat_token, transform<name_token, build_name>, build_repeat>
  name_expression;

typedef foldlp<name_expression, name_expression, build_sequence> seq_expression;

typedef
  foldlp<last_of<or_token, seq_expression>, seq_expression, build_selection>
  expression;

typedef build_parser<entire_input<expression>> parser_parser;

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
  typedef build_parsed_parser type;
  typedef typename apply_wrap1<parser_parser, S>::type p;

  template <class G>
  struct apply : apply_wrap1<p, G> {};
};

typedef build_parser<name_token> name_parser;

template <class S>
struct rebuild : apply_wrap1<name_parser, S> {};

template <class Rules = map<>, class Actions = map<>>
struct grammar
{
  typedef grammar type;
  typedef Rules rules;
  typedef Actions actions;

  template <class Name, class P>
  struct rule_ :
    grammar<
      typename insert<
        Rules,
        pair<typename rebuild<Name>::type, build_native_parser<P>>
      >::type,
      Actions
    >
  {};

  template <class Name, class Expr>
  struct rule :
    grammar<
      typename insert<
        Rules,
        pair<typename rebuild<Name>::type, build_parsed_parser<Expr>>
      >::type,
      Actions
    >
  {};

  template <class Name, class F>
  struct semantic_action :
    grammar<
      Rules,
      typename insert<Actions, pair<typename rebuild<Name>::type, F>>::type
    >
  {};
};

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

typedef
  grammar<>
    ::rule_<_S("plus_token"),  token<lit_c<'+'> > >::type
    ::rule_<_S("minus_token"), token<lit_c<'-'> > >::type
    ::rule_<_S("mult_token"),  token<lit_c<'*'> > >::type
    ::rule_<_S("div_token"),   token<lit_c<'/'> > >::type
    ::rule_<_S("arg_token"),   token<lit_c<'_'> > >::type
    ::rule_<_S("int_token"),   token<int_> >::type

    ::rule<_S("S"),         _S("plus_exp")>::type
    ::rule<_S("plus_exp"),  _S("prod_exp plus_exp_*")>::type
    ::rule<_S("plus_exp_"), _S("plus_op prod_exp")>::type
    ::rule<_S("plus_op"),   _S("plus_token | minus_token")>::type
    ::rule<_S("prod_exp"),  _S("value_exp prod_exp_*")>::type
    ::rule<_S("prod_exp_"), _S("prod_op value_exp")>::type
    ::rule<_S("prod_op"),   _S("mult_token | div_token")>::type
    ::rule<_S("value_exp"), _S("int_token | arg_token")>::type

    ::semantic_action<_S("int_token"), build_value>::type
    ::semantic_action<_S("arg_token"), build_arg>::type
    ::semantic_action<_S("prod_exp"),  build_mult>::type
    ::semantic_action<_S("plus_exp"),  build_plus>::type
  g;

typedef
  build_parser<entire_input<get_parser<g, rebuild<_S("S")>::type>::type> >
  function_parser;

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


