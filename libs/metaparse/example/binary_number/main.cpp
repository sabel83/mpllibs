// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/foldl1.hpp>
#include <mpllibs/metaparse/build_parser.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/entire_input.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <mpllibs/metaparse/util/digit_to_int.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>

#include <iostream>

using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::foldl1;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::transform;
using mpllibs::metaparse::one_of;
using mpllibs::metaparse::entire_input;

using mpllibs::metaparse::util::digit_to_int;

using boost::mpl::int_;
using boost::mpl::plus;
using boost::mpl::times;

/*
 * The grammar
 *
 * expression ::= ('1' | '0')*
 */

struct next_element
{
  template <class B, class Acc>
  struct apply : plus<times<Acc, int_<2> >, B> {};
};

typedef
  foldl1<
    transform<one_of<lit_c<'0'>, lit_c<'1'> >, digit_to_int>,
    int_<0>,
    next_element
  >
  S;

typedef build_parser<entire_input<S> > binary_parser;

template <class S>
struct binary : binary_parser::apply<S>::type {};

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
  
  cout
    << binary<string<'100'> >::value << endl
    << binary<string<'1011'> >::value << endl
    << binary<string<'1'> >::value << endl;
}
#else
int main()
{
  using std::cout;
  using std::endl;
  
  cout
    << binary<_S("100")>::value << endl
    << binary<_S("1011")>::value << endl
    << binary<_S("1")>::value << endl;
}
#endif


