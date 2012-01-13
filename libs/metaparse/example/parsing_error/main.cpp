// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/debug_parsing_error.hpp>

#include <mpllibs/metaparse/build_parser.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/apply.hpp>

using mpllibs::metaparse::sequence;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::any;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::debug_parsing_error;

using boost::mpl::apply;

/*
 * The grammar
 *
 * s ::= a*b
 */
typedef sequence<any<lit_c<'a'> >, lit_c<'b'> > s;

typedef build_parser<s> test_parser;

typedef MPLLIBS_STRING("aaac") invalid_input;

debug_parsing_error<test_parser, invalid_input> debug;

int main()
{
  // This causes an error
  // apply<TestParser, invalid_input>::type();
}


