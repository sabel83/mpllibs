#ifndef MPLLIBS_PARSER_IF_H
#define MPLLIBS_PARSER_IF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_of.h>
#include <mpllibs/parser/always.h>
#include <mpllibs/parser/return.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class t, class f>
    struct if_ :
      mpllibs::parser::one_of<
        mpllibs::parser::always<p, t>,
        mpllibs::parser::return_<f>
      >
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/parser/lit.h>
#include <mpllibs/parser/digit.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace test_mpllibs_parser_if
  {
    namespace
    {
      typedef boost::mpl::list_c<char, 'a'> aString;
      typedef boost::mpl::list_c<char, '1'> oneString;

      struct TestTrue :
        mpllibs::test::test_equal<
          mpllibs::parser::if_<
            mpllibs::parser::digit,
            boost::mpl::int_<11>,
            boost::mpl::int_<13>
          >::apply<oneString>::type::first,
          boost::mpl::int_<11>
        >
      {};

      struct TestFalse :
        mpllibs::test::test_equal<
          mpllibs::parser::if_<
            mpllibs::parser::digit,
            boost::mpl::int_<11>,
            boost::mpl::int_<13>
          >::apply<aString>::type::first,
          boost::mpl::int_<13>
        >
      {};
    }
  }
}
#endif

#endif

