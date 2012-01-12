// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/space.hpp>
#include <mpllibs/metaparse/int.hpp>
#include <mpllibs/metaparse/foldr.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/parser_monad.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/entire_input.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/always.hpp>

#include <mpllibs/metaparse/build_parser.hpp>

#include <mpllibs/metamonad/do.hpp>
#include <mpllibs/metamonad/do_try.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/meta_atom.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

using mpllibs::metaparse::sequence;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::last_of;
using mpllibs::metaparse::space;
using mpllibs::metaparse::any;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::int_;
using mpllibs::metaparse::foldr;
using mpllibs::metaparse::parser_tag;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::one_of;
using mpllibs::metaparse::token;
using mpllibs::metaparse::entire_input;
using mpllibs::metaparse::transform;
using mpllibs::metaparse::always;

using mpllibs::metamonad::do_try;
using mpllibs::metamonad::throw_;
using mpllibs::metamonad::do_;
using mpllibs::metamonad::set;

using boost::mpl::apply_wrap1;
using boost::mpl::front;
using boost::mpl::back;
using boost::mpl::if_;
using boost::mpl::bool_;

/*
 * The grammar
 *
 * expression ::= plus_exp
 * plus_exp ::= prod_exp ((plus_token | minus_token) prod_exp)*
 * prod_exp ::= value_exp ((mult_token | div_token) value_exp)*
 * value_exp ::= int_token | '_'
 */

typedef token<lit_c<'+'> > plus_token;
typedef token<lit_c<'-'> > minus_token;
typedef token<lit_c<'*'> > mult_token;
typedef token<lit_c<'/'> > div_token;
 
typedef token<int_> int_token;
typedef token<lit_c<'_'> > arg_token;

struct x;

MPLLIBS_DEFINE_TAG(division_by_zero_tag)
MPLLIBS_DEFINE_META_ATOM(division_by_zero_tag, division_by_zero)

template <class T, char C>
struct is_c : bool_<T::type::value == C>
{
  struct to_stream
  {
    static std::ostream& run(std::ostream& o)
    {
      o << "is_c";
      mpllibs::metatest::to_stream_argument_list<T>::run(o);
      return o << ", " << C << ">";
    }
  };
};

struct build_plus
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

  template <class C, class State>
  struct apply :
    if_<
      typename is_c<front<C>, '+'>::type,
      _plus<State, typename back<C>::type>,
      _minus<State, typename back<C>::type>
    >
  {};

  struct to_stream
  {
    static std::ostream& run(std::ostream& o)
    {
      return o << "build_plus";
    }
  };
};

struct build_mult
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

  template <class C, class State>
  struct apply :
    if_<
      typename is_c<front<C>, '*'>::type,
      _mult<State, typename back<C>::type>,
      _div<State, typename back<C>::type>
    >
  {};

  struct to_stream
  {
    static std::ostream& run(std::ostream& o)
    {
      return o << "build_mult";
    }
  };
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

  struct to_stream
  {
    static std::ostream& run(std::ostream& o)
    {
      return o << "build_value";
    }
  };
};

struct arg
{
  typedef arg type;

  template <class T>
  T operator()(T t) const
  {
    return t;
  }

  struct to_stream
  {
    static std::ostream& run(std::ostream& o)
    {
      return o << "arg";
    }
  };
};

typedef
  one_of<transform<int_token, build_value>, always<arg_token, arg>>
  value_exp;

typedef
  do_<parser_tag>::apply<
    set<x, value_exp>,
    foldr<
      sequence<one_of<mult_token, div_token>, value_exp>,
      get_result<x>,
      build_mult
    >
  >::type
  prod_exp;
  
typedef
  do_<parser_tag>::apply<
    set<x, prod_exp>,
    foldr<
      sequence<one_of<plus_token, minus_token>, prod_exp>,
      get_result<x>,
      build_plus
    >
  >::type
  plus_exp;

typedef last_of<any<space>, plus_exp> expression;

typedef build_parser<entire_input<expression> > function_parser;

#ifdef LAMBDA
  #error LAMBDA already defined
#endif
#define LAMBDA(exp) apply_wrap1<function_parser, _S(#exp)>::type

LAMBDA(13) f1;
LAMBDA(2 + 3) f2;
LAMBDA(2 * 2) f3;
LAMBDA( 1+ 2*4-6/2) f4;
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


