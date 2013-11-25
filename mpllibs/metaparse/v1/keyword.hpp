#ifndef MPLLIBS_METAPARSE_V1_KEYWORD_HPP
#define MPLLIBS_METAPARSE_V1_KEYWORD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/impl/accepted_keyword.hpp>
#include <mpllibs/metaparse/v1/lit.hpp>
#include <mpllibs/metaparse/v1/return_.hpp>
#include <mpllibs/metaparse/v1/is_error.hpp>
#include <mpllibs/metaparse/v1/get_remaining.hpp>
#include <mpllibs/metaparse/v1/get_position.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      // Does not consume/check anything after the keyword
      template <class Kw, class ResultType = impl::accepted_keyword>
      struct keyword
      {
      private:
        struct nonempty
        {
        private:
          typedef lit<typename boost::mpl::front<Kw>::type> next_char_parser;

          typedef
            keyword<typename boost::mpl::pop_front<Kw>::type, ResultType>
            rest_parser;
          
          template <class S, class Pos>
          struct apply_unchecked :
            boost::mpl::apply_wrap2<
              rest_parser,
              typename get_remaining<
                boost::mpl::apply_wrap2<next_char_parser, S, Pos>
              >::type,
              typename get_position<
                boost::mpl::apply_wrap2<next_char_parser, S, Pos>
              >::type
            >
          {};
        public:
          template <class S, class Pos>
          struct apply :
            boost::mpl::eval_if<
              typename is_error<
                boost::mpl::apply_wrap2<next_char_parser, S, Pos>
              >::type,
              boost::mpl::apply_wrap2<next_char_parser, S, Pos>,
              apply_unchecked<S, Pos>
            >
          {};
        };
      public:
        typedef keyword type;
        
        template <class S, class Pos>
        struct apply :
          boost::mpl::apply_wrap2<
            typename boost::mpl::if_<
              boost::mpl::empty<Kw>,
              return_<ResultType>,
              nonempty
            >::type,
            S,
            Pos
          >
        {};
      };
    }
  }
}

#endif

