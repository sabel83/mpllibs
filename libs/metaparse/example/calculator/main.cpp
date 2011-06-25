// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/first_of.hpp>
#include <mpllibs/metaparse/space.hpp>
#include <mpllibs/metaparse/int.hpp>
#include <mpllibs/metaparse/any_foldr.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/parser_monad.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metaparse/util/lazy_equal_to.hpp>

#include <mpllibs/metaparse/build_parser.hpp>

#include <mpllibs/metamonad/do_.hpp>
#include <mpllibs/metamonad/try_.hpp>

#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/char.hpp>

using mpllibs::metaparse::sequence;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::last_of;
using mpllibs::metaparse::first_of;
using mpllibs::metaparse::space;
using mpllibs::metaparse::any;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::int_;
using mpllibs::metaparse::any_foldr;
using mpllibs::metaparse::parser_tag;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::one_of;

using mpllibs::metaparse::util::lazy_equal_to;

using mpllibs::metatest::to_stream;

using boost::mpl::apply_wrap1;
using boost::mpl::fold;
using boost::mpl::front;
using boost::mpl::back;
using boost::mpl::plus;
using boost::mpl::minus;
using boost::mpl::times;
using boost::mpl::divides;
using boost::mpl::eval_if;
using boost::mpl::bool_;
using boost::mpl::string;
using boost::mpl::equal_to;
using boost::mpl::char_;

/*
 * The grammar
 *
 * expression ::= plus_exp
 * plus_exp ::= prod_exp ((plus_token | minus_token) prod_exp)*
 * prod_exp ::= int_token ((mult_token | div_token) int_token)*
 */

template <class P>
struct token : first_of<P, any<space> > {};

typedef token<lit_c<'+'> > plus_token;
typedef token<lit_c<'-'> > minus_token;
typedef token<lit_c<'*'> > mult_token;
typedef token<lit_c<'/'> > div_token;
 
typedef token<int_> int_token;

struct x;

struct division_by_zero_tag
{
  typedef division_by_zero_tag type;
};

struct division_by_zero
{
  typedef division_by_zero type;
  typedef division_by_zero_tag tag;
};

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(division_by_zero);

struct new_value;
struct state;

struct eval_plus
{
  template <class C, class State>
  struct apply :
    MPLLIBS_TRY<
      MPLLIBS_SET<state, State>,
      MPLLIBS_SET<new_value, back<C> >,
      eval_if<
        lazy_equal_to<front<C>, char_<'+'> >,
        plus<state, new_value>,
        minus<state, new_value>
      >
    >
  {};
};
  
struct eval_mult
{
  template <class C, class State>
  struct apply :
    MPLLIBS_TRY<
      MPLLIBS_SET<state, State>,
      MPLLIBS_SET<new_value, back<C> >,
      eval_if<
        lazy_equal_to<front<C>, char_<'*'> >,
        times<state, new_value>,
        eval_if<
          equal_to<new_value, boost::mpl::int_<0> >,
          MPLLIBS_THROW<division_by_zero>,
          divides<state, new_value>
        >
      >
    >
  {};
};

typedef
  MPLLIBS_DO<parser_tag>::apply<
    MPLLIBS_SET<x, int_token>,
    any_foldr<
      sequence<one_of<mult_token, div_token>, int_token>,
      get_result<x>,
      eval_mult
    >
  >::type
  prod_exp;
  
typedef
  MPLLIBS_DO<parser_tag>::apply<
    MPLLIBS_SET<x, prod_exp>,
    any_foldr<
      sequence<one_of<plus_token, minus_token>, prod_exp>,
      get_result<x>,
      eval_plus
    >
  >::type
  plus_exp;

typedef last_of<any<space>, plus_exp> expression;

typedef build_parser<expression> calculator_parser;

int main()
{
  using std::cout;
  using std::endl;
  
  to_stream<
    apply_wrap1<calculator_parser, string<'13'> >::type
  >::run(cout) << endl;

  to_stream<
    apply_wrap1<calculator_parser, string<' 1+ ','2*4-','6/2'> >::type
  >::run(cout) << endl;

  to_stream<
    apply_wrap1<calculator_parser, string<'11/0'> >::type
  >::run(cout) << endl;

  to_stream<
    apply_wrap1<calculator_parser, string<'19 +',' 83/','0 + ','11'> >::type
  >::run(cout) << endl;
}


