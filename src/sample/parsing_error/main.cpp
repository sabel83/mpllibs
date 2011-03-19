#include <mpllibs/metaparse/any.h>
#include <mpllibs/metaparse/sequence.h>
#include <mpllibs/metaparse/lit_c.h>
#include <mpllibs/metaparse/DebugParsingError.h>

#include <mpllibs/metaparse/build_parser.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metaparse::sequence;
using mpllibs::metaparse::lit_c;
using mpllibs::metaparse::any;
using mpllibs::metaparse::build_parser;
using mpllibs::metaparse::DebugParsingError;

using boost::mpl::list_c;
using boost::mpl::apply;

/*
 * The grammar
 *
 * S ::= a*b
 */
typedef sequence<any<lit_c<'a'> >, lit_c<'b'> > S;

typedef build_parser<S> TestParser;

typedef list_c<char, 'a','a','a','c'> invalid_input;

DebugParsingError<TestParser, invalid_input> debug;

int main()
{
  // This causes an error
  // apply<TestParser, invalid_input>::type();
}


