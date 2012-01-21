// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/foldl.hpp>
#include <mpllibs/metaparse/foldl1.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/one_char_except_c.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/build_parser.hpp>
#include <mpllibs/metaparse/middle_of.hpp>
#include <mpllibs/metaparse/entire_input.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/xpressive/xpressive.hpp>

#include <boost/mpl/bool.hpp>

using mpllibs::metaparse::foldl;
using mpllibs::metaparse::foldl1;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::transform;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::one_of;
using mpllibs::metaparse::always;
using mpllibs::metaparse::middle_of;
using mpllibs::metaparse::one_char_except_c;
using mpllibs::metaparse::entire_input;

using boost::mpl::c_str;
using boost::mpl::true_;
using boost::mpl::false_;

using boost::xpressive::sregex;
using boost::xpressive::as_xpr;

/*
 * Results of parsing
 */

struct r_epsilon
{
  typedef r_epsilon type;
  static const sregex value;
};

const sregex r_epsilon::value = as_xpr("");

struct r_any_char
{
  typedef r_any_char type;
  static const sregex value;
};

const sregex r_any_char::value = boost::xpressive::_;

struct r_char_lit
{
  template <class C>
  struct apply
  {
    typedef apply type;
    static const sregex value;
  };
};

template <class C>
const sregex r_char_lit::apply<C>::value = as_xpr(C::type::value);

struct r_append
{
  template <class A, class B>
  struct apply
  {
    typedef apply type;
    static const sregex value;
  };
};

template <class A, class B>
const sregex r_append::apply<A, B>::value = B::type::value >> A::type::value;

/*
 * The grammar
 *
 * regexp ::= (bracket_expr | non_bracket_expr)*
 * non_bracket_expr ::= '.' | char_lit
 * bracket_expr ::= '(' regexp ')'
 * char_lit ::= any character except: . ( )
 */

typedef
  foldl1<
    one_of<
      always<lit_c<'.'>, r_any_char>,
      transform<one_char_except_c<'.', '(', ')'>, r_char_lit>
    >,
    r_epsilon,
    r_append
  >
  non_bracket_expr;

typedef middle_of<lit_c<'('>, non_bracket_expr, lit_c<')'> > bracket_expr;

typedef
  foldl<one_of<bracket_expr, non_bracket_expr>, r_epsilon, r_append>
  regexp;

typedef build_parser<entire_input<regexp> > regexp_parser;

void test_string(const std::string& s)
{
  using boost::xpressive::regex_match;
  using boost::xpressive::smatch;
  using boost::mpl::apply_wrap1;

  using std::cout;
  using std::endl;

#ifdef BOOST_NO_CONSTEXPR
  typedef boost::mpl::string<'.(bc',')'> regexp;
#else
  typedef MPLLIBS_STRING(".(bc)") regexp;
#endif

  const sregex re = apply_wrap1<regexp_parser, regexp>::type::value;
  smatch w;

  cout
    << s << (regex_match(s, w, re) ? " matches " : " doesn't match ")
    << c_str<regexp>::type::value
    << endl;
}

int main()
{
  test_string("abc");
  test_string("aba");
}


