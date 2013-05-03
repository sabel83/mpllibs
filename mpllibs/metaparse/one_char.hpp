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
#include <mpllibs/metaparse/define_error.hpp>

#include <boost/mpl/empty.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/char.hpp>
#include <boost/mpl/string.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      MPLLIBS_DEFINE_ERROR(unexpected_end_of_input, "Unexpected end of input");
    }
    
    struct one_char
    {
    private:
      template <class C, class Pos>
      struct next_pos :
        boost::mpl::eval_if<
          typename boost::mpl::or_<
            typename boost::mpl::equal_to<
              boost::mpl::char_<'\r'>,
              typename C::type
            >::type,
            typename boost::mpl::and_<
              typename boost::mpl::equal_to<
                boost::mpl::char_<'\n'>,
                typename C::type
              >::type,
              typename boost::mpl::not_<
                typename boost::mpl::equal_to<
                  boost::mpl::char_<'\r'>,
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
            fail<mpllibs::metaparse::errors::unexpected_end_of_input>,
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

#endif


