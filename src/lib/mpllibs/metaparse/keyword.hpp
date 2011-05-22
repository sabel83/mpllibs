#ifndef MPLLIBS_PARSER_KEYWORD_H
#define MPLLIBS_PARSER_KEYWORD_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/lit.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>
#include <mpllibs/metaparse/util/define_data.hpp>

#include <mpllibs/metatest/to_stream.hpp>

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

    template <class S, class ResultType>
    struct keyword;
    
    namespace impl
    {
      template <class Kw, class ResultType>
      struct nonempty_keyword
      {
      private:
        typedef
          mpllibs::metaparse::lit<typename boost::mpl::front<Kw>::type>
          next_char_parser;

        typedef
          mpllibs::metaparse::keyword<
            typename boost::mpl::pop_front<Kw>::type,
            ResultType
          >
          rest_parser;
        
        template <class S, class Pos>
        struct apply_unchecked :
          boost::mpl::apply<
            rest_parser,
            typename mpllibs::metaparse::get_remaining<
              boost::mpl::apply<next_char_parser, S, Pos>
            >::type,
            typename mpllibs::metaparse::get_position<
              boost::mpl::apply<next_char_parser, S, Pos>
            >::type
          >
        {};
      public:
        template <class S, class Pos>
        struct apply :
          boost::mpl::eval_if<
            typename mpllibs::metaparse::is_error<
              boost::mpl::apply<next_char_parser, S, Pos>
            >::type,
            boost::mpl::apply<next_char_parser, S, Pos>,
            apply_unchecked<S, Pos>
          >
        {};
      };
    }
    
    // Does not consume/check anything after the keyword
    template <class S, class ResultType = accepted_keyword>
    struct keyword :
      boost::mpl::if_<
        boost::mpl::empty<S>,
        return_<ResultType>,
        mpllibs::metaparse::impl::nonempty_keyword<S, ResultType>
      >::type
    {};
  }
}

DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metaparse::accepted_keyword,
  "Accepted keyword"
)

#endif

