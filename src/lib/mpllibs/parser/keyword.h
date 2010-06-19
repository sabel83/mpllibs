#ifndef MPLLIBS_PARSER_KEYWORD_H
#define MPLLIBS_PARSER_KEYWORD_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/lit.h>
#include <mpllibs/parser/return.h>
#include <mpllibs/parser/sequence.h>
#include <mpllibs/parser/second_of.h>

#include <mpllibs/util/lazy_if.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>

namespace mpllibs
{
  namespace parser
  {
    struct accepted_keyword {};

    template <class s, class result_type>
    struct keyword;
    
    namespace impl
    {
      template <class s, class result_type>
      struct nonemptyKeyword :
        mpllibs::parser::second_of<
          mpllibs::parser::sequence<
            mpllibs::parser::lit<typename boost::mpl::front<s>::type>,
            mpllibs::parser::keyword<
              typename boost::mpl::pop_front<s>::type,
              result_type
            >
          >,
          mpllibs::parser::return_<result_type>
        >
      {};
    }
    
    // Does not consume/check anything after the keyword
    template <class s, class result_type = accepted_keyword>
    struct keyword :
      mpllibs::util::lazy_if<
        boost::mpl::empty<s>,
        mpllibs::parser::return_<result_type>,
        mpllibs::parser::impl::nonemptyKeyword<s, result_type>
      >::type
    {};
  }
}

#endif

