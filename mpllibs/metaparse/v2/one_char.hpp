#ifndef MPLLIBS_METAPARSE_V2_ONE_CHAR_HPP
#define MPLLIBS_METAPARSE_V2_ONE_CHAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/error/unexpected_end_of_input.hpp>
#include <mpllibs/metaparse/v2/next_char.hpp>
#include <mpllibs/metaparse/v2/next_line.hpp>
#include <mpllibs/metaparse/v2/accept.hpp>
#include <mpllibs/metaparse/v2/reject.hpp>
#include <mpllibs/metaparse/v2/get_prev_char.hpp>

#include <boost/mpl/empty.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      struct one_char
      {
      private:
        template <class C, class Pos>
        struct next_pos :
          boost::mpl::eval_if<
            boost::mpl::bool_<
              C::type::value == '\r'
              || (
                C::type::value == '\n'
                && get_prev_char<Pos>::type::value != '\r'
              )
            >,
            next_line<Pos, C>,
            next_char<Pos, C>
          >
        {};
      public:
        typedef one_char type;
        
        template <class S, class Pos>
        struct apply :
          boost::mpl::eval_if<
            typename boost::mpl::empty<S>::type,
            reject<error::unexpected_end_of_input, Pos>,
            accept<
              boost::mpl::front<S>,
              boost::mpl::pop_front<S>,
              next_pos<boost::mpl::front<S>, Pos>
            >
          >
        {};
      };
    }
  }
}

#endif

