#ifndef MPLLIBS_PARSER_FAIL_H
#define MPLLIBS_PARSER_FAIL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/nothing.h>

namespace mpllibs
{
  namespace parser
  {
    struct fail
    {
      template <class S>
      struct apply : mpllibs::parser::nothing {};
    };
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/list_c.hpp>

namespace mpllibs
{ 
  namespace mpllibs_parser_test_fail
  {
    namespace
    {
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;

      struct TestFailForNonEmptyString :
        mpllibs::test::test_equal<
          mpllibs::parser::fail::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};
    }
  }
}
#endif

#endif

