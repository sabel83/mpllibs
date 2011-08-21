#ifndef MPLLIBS_METAPARSE_FOLDR_HPP
#define MPLLIBS_METAPARSE_FOLDR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class State, class BackwardOp>
    struct foldr
    {
    private:
      template <class Res>
      struct apply_unchecked
      {
      private:
        typedef
          // foldr never returns error
          // I need to use apply_wrap, and not apply, because apply would
          // build a metafunction class from foldr<P, State, BackwardOp>
          // when BackwardOp is a lambda expression.
          boost::mpl::apply_wrap2<
            foldr,
            typename get_remaining<Res>::type,
            typename get_position<Res>::type
          >
          parsed_remaining;
      public:
        typedef
          boost::mpl::apply_wrap2<
            return_<
              typename boost::mpl::apply<
                BackwardOp,
                typename get_result<Res>::type,
                typename get_result<parsed_remaining>::type
              >::type
            >,
            typename get_remaining<parsed_remaining>::type,
            typename get_position<parsed_remaining>::type
          >
          type;
      };
    public:
      typedef foldr type;
    
      template <class S, class Pos>
      struct apply :
        boost::mpl::eval_if<
          typename is_error<boost::mpl::apply<P, S, Pos> >::type,
          boost::mpl::apply_wrap2<return_<typename State::type>, S, Pos>,
          apply_unchecked<boost::mpl::apply<P, S, Pos> >
        >
      {};

      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "foldr<";
          mpllibs::metatest::to_stream_argument_list<
            P,
            State,
            BackwardOp
          >::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

