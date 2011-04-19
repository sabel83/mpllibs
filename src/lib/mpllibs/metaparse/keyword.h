#ifndef MPLLIBS_PARSER_KEYWORD_H
#define MPLLIBS_PARSER_KEYWORD_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/lit.h>
#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/get_remaining.h>
#include <mpllibs/metaparse/get_position.h>
#include <mpllibs/metaparse/util/define_data.h>

#include <mpllibs/metatest/to_stream.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    MPLLIBS_METAPARSE_DEFINE_DATA(accepted_keyword);

    template <class s, class result_type>
    struct keyword;
    
    namespace impl
    {
      template <class kw, class result_type>
      struct nonemptyKeyword
      {
      private:
        typedef
          mpllibs::metaparse::lit<typename boost::mpl::front<kw>::type>
          nextCharParser;

        typedef
          mpllibs::metaparse::keyword<
            typename boost::mpl::pop_front<kw>::type,
            result_type
          >
          restParser;
        
        template <class s, class pos>
        struct apply_unchecked :
          boost::mpl::apply<
            restParser,
            typename mpllibs::metaparse::get_remaining<
              boost::mpl::apply<nextCharParser, s, pos>
            >::type,
            typename mpllibs::metaparse::get_position<
              boost::mpl::apply<nextCharParser, s, pos>
            >::type
          >
        {};
      public:
        template <class s, class pos>
        struct apply :
          boost::mpl::eval_if<
            typename mpllibs::metaparse::is_error<
              boost::mpl::apply<nextCharParser, s, pos>
            >::type,
            boost::mpl::apply<nextCharParser, s, pos>,
            apply_unchecked<s, pos>
          >
        {};
      };
    }
    
    // Does not consume/check anything after the keyword
    template <class s, class result_type = mpllibs::metaparse::accepted_keyword>
    struct keyword :
      boost::mpl::if_<
        boost::mpl::empty<s>,
        mpllibs::metaparse::return_<result_type>,
        mpllibs::metaparse::impl::nonemptyKeyword<s, result_type>
      >::type
    {};
  }
}

DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metaparse::accepted_keyword,
  "Accepted keyword"
)

#endif

