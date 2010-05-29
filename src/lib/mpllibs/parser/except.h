#ifndef MPLLIBS_PARSER_EXCEPT_H
#define MPLLIBS_PARSER_EXCEPT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/nothing.h>

#include <mpllibs/util/make_pair.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/identity.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class result>
    struct except
    {
      template <class S>
      struct apply :
        boost::mpl::eval_if<
          typename boost::mpl::equal_to<
            typename p::template apply<S>::type,
            mpllibs::parser::nothing
          >::type,
          mpllibs::util::make_pair<boost::mpl::identity<result>, S>,
          mpllibs::parser::nothing
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
#include <mpllibs/parser/fail.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace test_mpllibs_parser_except
  {
    namespace
    {
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::int_<13> val;
      
      struct TestWithGood :
        mpllibs::test::test_equal<
          mpllibs::parser::except<
            mpllibs::parser::one_char,
            val
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};    

      struct TestWithBad :
        mpllibs::test::test_equal<
          mpllibs::parser::except<
            mpllibs::parser::fail,
            val
          >::apply<helloString>::type::first,
          val
        >
      {};    
    }
  }
}
#endif

#endif

