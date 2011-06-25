#ifndef MPLLIBS_METAPARSE_ONE_CHAR_HPP
#define MPLLIBS_METAPARSE_ONE_CHAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/next_char.hpp>
#include <mpllibs/metaparse/next_line.hpp>
#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/get_prev_char.hpp>

#include <mpllibs/metaparse/util/define_data.hpp>

#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/empty.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      MPLLIBS_METAPARSE_DEFINE_DATA(unexpected_end_of_input);
    }
    
    struct one_char
    {
    private:
      template <class C, class Pos>
      struct next_pos :
        boost::mpl::eval_if<
          typename boost::mpl::or_<
            typename boost::mpl::equal_to<
              boost::mpl::integral_c<char, '\r'>,
              typename C::type
            >::type,
            typename boost::mpl::and_<
              typename boost::mpl::equal_to<
                boost::mpl::integral_c<char, '\n'>,
                typename C::type
              >::type,
              typename boost::mpl::not_<
                typename boost::mpl::equal_to<
                  boost::mpl::integral_c<char, '\r'>,
                  typename get_prev_char<Pos>::type
                >::type
              >
            >::type
          >::type,
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
          boost::mpl::apply_wrap2<
            fail<
              mpllibs::metaparse::errors::unexpected_end_of_input
            >,
            S,
            Pos
          >,
          boost::mpl::apply_wrap2<
            return_<boost::mpl::front<S> >,
            boost::mpl::pop_front<S>,
            next_pos<boost::mpl::front<S>, Pos>
          >
        >
      {};
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metaparse::errors::unexpected_end_of_input,
  "Unexpected end of input"
)

#endif

