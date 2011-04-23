// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any.h>
#include <mpllibs/metaparse/sequence.h>
#include <mpllibs/metaparse/lit_c.h>
#include <mpllibs/metaparse/debug_parsing_error.h>

#include <mpllibs/metaparse/build_parser.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metaparse::sequence;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::any;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::debug_parsing_error;

using boost::mpl::list_c;
using boost::mpl::apply;

/*
 * The grammar
 *
 * s ::= a*b
 */
typedef sequence<any<lit_c<'a'> >, lit_c<'b'> > s;

typedef build_parser<s> test_parser;

typedef list_c<char, 'a','a','a','c'> invalid_input;

debug_parsing_error<test_parser, invalid_input> debug;

int main()
{
  // This causes an error
  // apply<TestParser, invalid_input>::type();
}


