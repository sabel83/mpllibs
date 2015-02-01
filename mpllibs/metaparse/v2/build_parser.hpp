#ifndef MPLLIBS_METAPARSE_V2_BUILD_PARSER_HPP
#define MPLLIBS_METAPARSE_V2_BUILD_PARSER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/fwd/build_parser.hpp>
#include <mpllibs/metaparse/v2/start.hpp>
#include <mpllibs/metaparse/v2/get_result.hpp>
#include <mpllibs/metaparse/v2/get_position.hpp>
#include <mpllibs/metaparse/v2/get_message.hpp>
#include <mpllibs/metaparse/v2/get_line.hpp>
#include <mpllibs/metaparse/v2/get_col.hpp>
#include <mpllibs/metaparse/v2/is_error.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>

#include <boost/static_assert.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <int Line, int Col, class Msg>
      struct x__________________PARSING_FAILED__________________x
      {
        BOOST_STATIC_ASSERT(Line == Line + 1);
      };

      template <class P>
      struct build_parser
      {
        typedef build_parser type;
        
        template <class S>
        struct apply :
          boost::mpl::eval_if<
            typename is_error<boost::mpl::apply<P, S, start> >::type,
            x__________________PARSING_FAILED__________________x<
              get_line<
                get_position<boost::mpl::apply<P, S, start> >
              >::type::value,
              get_col<
                get_position<boost::mpl::apply<P, S, start> >
              >::type::value,
              typename get_message<boost::mpl::apply<P, S, start> >::type
            >,
            get_result<boost::mpl::apply<P, S, start> >
          >
        {};
      };
    }
  }
}

#endif

