#ifndef MPLLIBS_PARSER_ACCEPT_WHEN_H
#define MPLLIBS_PARSER_ACCEPT_WHEN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/nothing.h>

#include <mpllibs/util/get_first.h>
#include <mpllibs/util/compose.h>
#include <mpllibs/util/lazy_eval_if.h>
#include <mpllibs/util/lazy_equal_to.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class pred>
    struct accept_when
    {
      template <class S>
      struct apply :
        boost::mpl::eval_if<
          mpllibs::util::lazy_equal_to<
            boost::mpl::apply<p, S>,
            mpllibs::parser::nothing
          >,
          mpllibs::parser::nothing,
          mpllibs::util::lazy_eval_if<
            boost::mpl::apply<
              mpllibs::util::compose<pred, mpllibs::util::get_first>,
              typename boost::mpl::apply<p, S>::type
            >,
            boost::mpl::apply<p, S>,
            mpllibs::parser::nothing
          >
        >
      {};
    };
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/parser/one_char.h>

#include <mpllibs/util/is_digit.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/list_c.hpp>

namespace mpllibs
{
  namespace mpllibs_parser_test_accept_when
  {
    namespace
    {
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char, '1', '9', '8', '3'> numberString;
      typedef boost::mpl::list_c<char> emptyString;
      
      struct TestWithText :
        mpllibs::test::test_equal<
          mpllibs::parser::accept_when<
            mpllibs::parser::one_char,
            mpllibs::util::is_digit
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};    

      struct TestWithNumber :
        mpllibs::test::test_equal<
          mpllibs::parser::accept_when<
            mpllibs::parser::one_char,
            mpllibs::util::is_digit
          >::apply<numberString>::type::first,
          boost::mpl::integral_c<char, '1'>
        >
      {};    

      struct TestWithEmptyString :
        mpllibs::test::test_equal<
          mpllibs::parser::accept_when<
            mpllibs::parser::one_char,
            mpllibs::util::is_digit
          >::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};    
    }
  }
}
#endif

#endif

