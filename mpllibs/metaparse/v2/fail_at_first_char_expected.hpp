#ifndef MPLLIBS_METAPARSE_V2_FAIL_AT_FIRST_CHAR_EXPECTED_HPP
#define MPLLIBS_METAPARSE_V2_FAIL_AT_FIRST_CHAR_EXPECTED_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/impl/void_.hpp>
#include <mpllibs/metaparse/v2/accept.hpp>
#include <mpllibs/metaparse/v2/reject.hpp>
#include <mpllibs/metaparse/v2/is_error.hpp>
#include <mpllibs/metaparse/v2/get_position.hpp>

#include <mpllibs/metaparse/v2/error/expected_to_fail.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P>
      struct fail_at_first_char_expected
      {
      private:
        template <class S, class Pos>
        struct apply_err :
          boost::mpl::eval_if<
            typename boost::mpl::equal_to<
              Pos,
              typename get_position<boost::mpl::apply<P, S, Pos> >::type
            >::type,
            accept<impl::void_, S, Pos>,
            boost::mpl::apply<P, S, Pos>
          >
        {};
      public:
        typedef fail_at_first_char_expected type;

        template <class S, class Pos>
        struct apply :
          boost::mpl::eval_if<
            typename is_error<boost::mpl::apply<P, S, Pos> >::type,
            apply_err<S, Pos>,
            reject<error::expected_to_fail, Pos>
          >
        {};
      };
    }
  }
}

#endif

