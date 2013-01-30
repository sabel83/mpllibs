#ifndef MPLLIBS_METAPARSE_PARSER_MONAD_HPP
#define MPLLIBS_METAPARSE_PARSER_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/monad.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    struct parser_tag : mpllibs::metamonad::tmp_tag<parser_tag> {};
  }
  
  namespace metamonad
  {
    template <>
    struct monad<mpllibs::metaparse::parser_tag> :
      monad_defaults<mpllibs::metaparse::parser_tag>
    {
      struct return_
      {
        typedef return_ type;
        
        template <class T>
        struct apply : mpllibs::metaparse::return_<T> {};
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
              typename mpllibs::metaparse::get_remaining<PrevResult>::type,
              typename mpllibs::metaparse::get_position<PrevResult>::type
            >
          {};
        public:
          typedef apply_impl type;
      
          template <class S, class Pos>
          struct apply :
            boost::mpl::eval_if<
              typename mpllibs::metaparse::is_error<
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
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metaparse::parser_tag>::bind,
  "monad<parser_tag>::bind"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metaparse::parser_tag>::return_,
  "monad<parser_tag>::return_"
)

#endif

