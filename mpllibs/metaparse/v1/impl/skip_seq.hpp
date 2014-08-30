#ifndef MPLLIBS_METAPARSE_V1_IMPL_SKIP_SEQ_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_SKIP_SEQ_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/is_error.hpp>
#include <mpllibs/metaparse/v1/accept.hpp>
#include <mpllibs/metaparse/v1/get_remaining.hpp>
#include <mpllibs/metaparse/v1/get_position.hpp>
#include <mpllibs/metaparse/v1/get_result.hpp>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        struct skip_seq
        {
        private:
          template <class ParsingResult, class NewResultValue>
          struct change_result :
            accept<
              NewResultValue,
              typename get_remaining<ParsingResult>::type,
              typename get_position<ParsingResult>::type
            >
          {};
        
          template <class Result, class P>
          struct apply_unchecked :
            boost::mpl::eval_if<
              typename is_error<
                boost::mpl::apply<
                  P,
                  typename get_remaining<Result>::type,
                  typename get_position<Result>::type
                >
              >::type,
              boost::mpl::apply<
                P,
                typename get_remaining<Result>::type,
                typename get_position<Result>::type
              >,
              change_result<
                boost::mpl::apply<
                  P,
                  typename get_remaining<Result>::type,
                  typename get_position<Result>::type
                >,
                typename get_result<Result>::type
              >
            >
          {};
          
        public:
          template <class Result, class P>
          struct apply :
            boost::mpl::eval_if<
              is_error<Result>,
              Result,
              apply_unchecked<Result, P>
            >
          {};
        };
      }
    }
  }
}

#endif

