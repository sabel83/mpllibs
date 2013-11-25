#ifndef MPLLIBS_METAPARSE_V1_PARSER_MONAD_HPP
#define MPLLIBS_METAPARSE_V1_PARSER_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/parser_tag.hpp>
#include <mpllibs/metaparse/v1/is_error.hpp>
#include <mpllibs/metaparse/v1/return_.hpp>
#include <mpllibs/metaparse/v1/get_result.hpp>
#include <mpllibs/metaparse/v1/get_remaining.hpp>
#include <mpllibs/metaparse/v1/get_position.hpp>
#include <mpllibs/metaparse/v1/fail.hpp>

#include <mpllibs/metamonad/monad.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <>
      struct monad<metaparse::v1::parser_tag> :
        monad_defaults<metaparse::v1::parser_tag>
      {
        struct return_
        {
          typedef return_ type;
          
          template <class T>
          struct apply : metaparse::v1::return_<T> {};
        };
        
        struct bind
        {
        private:
          template <class P, class F>
          struct apply_impl
          {
          private:
            template <class PrevResult>
            struct apply_unchecked :
              boost::mpl::apply_wrap2<
                typename boost::mpl::apply<F, PrevResult>::type,
                typename metaparse::v1::get_remaining<PrevResult>::type,
                typename metaparse::v1::get_position<PrevResult>::type
              >
            {};
          public:
            typedef apply_impl type;
        
            template <class S, class Pos>
            struct apply :
              boost::mpl::eval_if<
                typename metaparse::v1::is_error<
                  boost::mpl::apply_wrap2<P, S, Pos>
                >::type,
                boost::mpl::apply_wrap2<P, S, Pos>,
                apply_unchecked<boost::mpl::apply_wrap2<P, S, Pos> >
              >
            {};
          };
        public:
          // P :: Parser
          // F :: previous_result -> Parser
          template <class P, class F>
          struct apply
          {
            typedef apply_impl<P, F> type;
          };
          
          typedef bind type;
        };

        struct fail
        {
          typedef fail type;

          template <class Msg>
          struct apply : metaparse::v1::fail<Msg> {};
        };
      };
    }
  }
}

#endif

