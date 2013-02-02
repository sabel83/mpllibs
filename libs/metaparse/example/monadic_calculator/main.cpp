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
#include <mpllibs/metaparse/foldlp.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/entire_input.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <mpllibs/metaparse/build_parser.hpp>

#include <mpllibs/metamonad/do_c.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/name.hpp>

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
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/bool.hpp>

using mpllibs::metaparse::sequence;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::last_of;
using mpllibs::metaparse::first_of;
using mpllibs::metaparse::space;
using mpllibs::metaparse::any;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::int_;
using mpllibs::metaparse::foldlp;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::one_of;
using mpllibs::metaparse::token;
using mpllibs::metaparse::entire_input;

using mpllibs::metatest::to_stream;

using mpllibs::metamonad::do_c;
using mpllibs::metamonad::exception;
using mpllibs::metamonad::exception_tag;
using mpllibs::metamonad::set;
using mpllibs::metamonad::tmp_tag;
using mpllibs::metamonad::tmp_value;

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
using boost::mpl::equal_to;
using boost::mpl::bool_;

using namespace mpllibs::metamonad::name;

/*
 * The grammar
 *
 * expression ::= plus_exp
 * plus_exp ::= prod_exp ((plus_token | minus_token) prod_exp)*
 * prod_exp ::= int_token ((mult_token | div_token) int_token)*
 */

typedef token<lit_c<'+'> > plus_token;
typedef token<lit_c<'-'> > minus_token;
typedef token<lit_c<'*'> > mult_token;
typedef token<lit_c<'/'> > div_token;
 
typedef token<int_> int_token;

struct division_by_zero_tag : tmp_tag<division_by_zero_tag> {};
struct division_by_zero : tmp_value<division_by_zero, division_by_zero_tag> {};

template <class T, char C>
struct is_c : bool_<T::type::value == C> {};

struct eval_plus
{
  template <class C, class State>
  struct apply :
    do_c<
      exception_tag,
      set<s, State>,
      set<v, back<C> >,
      eval_if<is_c<front<C>, '+'>, plus<s, v>, minus<s, v> >
    >
  {};
};

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(eval_plus)
  
struct eval_mult
{
  template <class C, class State>
  struct apply :
    do_c<
      exception_tag,
      set<s, State>,
      set<v, back<C> >,
      eval_if<
        is_c<front<C>, '*'>,
        times<s, v>,
        eval_if<
          equal_to<v, boost::mpl::int_<0> >,
          exception<division_by_zero>,
          divides<s, v>
        >
      >
    >
  {};
};

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(eval_mult)

typedef
  foldlp<
    sequence<one_of<mult_token, div_token>, int_token>,
    int_token,
    eval_mult
  >
  prod_exp;
  
typedef
  foldlp<
    sequence<one_of<plus_token, minus_token>, prod_exp>,
    prod_exp,
    eval_plus
  >
  plus_exp;

typedef last_of<any<space>, plus_exp> expression;

typedef build_parser<entire_input<expression> > calculator_parser;

#ifdef _S
  #error _S already defined
#endif
#define _S MPLLIBS_STRING

#ifdef BOOST_NO_CONSTEXPR

int main()
{
  using std::cout;
  using std::endl;
  using boost::mpl::string;
  
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

#else

int main()
{
  using std::cout;
  using std::endl;
  
  to_stream<
    apply_wrap1<calculator_parser, _S("13")>::type
  >::run(cout) << endl;

  to_stream<
    apply_wrap1<calculator_parser, _S(" 1+ 2*4-6/2")>::type
  >::run(cout) << endl;

  to_stream<
    apply_wrap1<calculator_parser, _S("11/0")>::type
  >::run(cout) << endl;

  to_stream<
    apply_wrap1<calculator_parser, _S("19 + 83/0 + 11")>::type
  >::run(cout) << endl;
}

#endif

