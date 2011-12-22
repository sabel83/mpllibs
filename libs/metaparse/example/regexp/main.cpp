// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/foldl.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/build_parser.hpp>

#include <boost/xpressive/xpressive.hpp>

#include <boost/mpl/string.hpp>

using mpllibs::metaparse::foldl;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::transform;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::one_of;
using mpllibs::metaparse::always;

using boost::mpl::string;
using boost::mpl::c_str;

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
 * regexp ::= ('.' | char_lit)*
 * char_lit ::= any character except: .
 */

typedef
  foldl<
    one_of<always<lit_c<'.'>, r_any_char>, transform<one_char, r_char_lit> >,
    r_epsilon,
    r_append
  >
  regexp;

typedef build_parser<regexp> regexp_parser;

void test_string(const std::string& s)
{
  using boost::xpressive::regex_match;
  using boost::xpressive::smatch;
  using boost::mpl::apply_wrap1;

  using std::cout;
  using std::endl;

  typedef string<'.','b','c'> regexp;

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


