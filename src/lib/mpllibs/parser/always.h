#ifndef MPLLIBS_PARSER_ALWAYS_H
#define MPLLIBS_PARSER_ALWAYS_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/return.h>
#include <mpllibs/parser/second_of.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class result>
    struct always :
      mpllibs::parser::second_of<p, mpllibs::parser::return_<result> >
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/parser/nothing.h>
#include <mpllibs/parser/digit.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/list_c.hpp>

namespace mpllibs
{
  namespace test_parser_always
  {
    namespace
    {
      typedef boost::mpl::list_c<char, '1'> oneString;
      typedef boost::mpl::list_c<char, 'a'> aString;

      struct TestResult :
        mpllibs::test::test_equal<
          mpllibs::parser::always<
            mpllibs::parser::digit,
            boost::mpl::int_<13>
          >::apply<oneString>::type::first,
          boost::mpl::int_<13>
        >
      {};

      struct TestFail :
        mpllibs::test::test_equal<
          mpllibs::parser::always<
            mpllibs::parser::digit,
            boost::mpl::int_<13>
          >::apply<aString>::type,
          mpllibs::parser::nothing
        >
      {};
    }
  }
}
#endif

#endif

