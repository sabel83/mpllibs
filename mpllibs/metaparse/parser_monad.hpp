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

#include <mpllibs/metamonad/try_.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    MPLLIBS_DEFINE_TAG(parser_tag);
  }
  
  namespace metamonad
  {
    template <class Tag>
    struct return__impl;
    
    template <>
    struct return__impl<mpllibs::metaparse::parser_tag>
    {
      template <class T>
      struct apply : mpllibs::metaparse::return_<T> {};
    };
    
    template <class Tag>
    struct bind_impl;
    
    template <>
    struct bind_impl<mpllibs::metaparse::parser_tag>
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
    };
  }
}

#endif

