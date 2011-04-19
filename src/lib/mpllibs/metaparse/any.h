#ifndef MPLLIBS_PARSER_ANY_H
#define MPLLIBS_PARSER_ANY_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/is_error.h>

#include <boost/mpl/list.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/push_front.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p>
    struct any
    {
    private:
      template <class res>
      struct apply_unchecked :
        boost::mpl::apply<
          mpllibs::metaparse::return_<
            typename boost::mpl::push_front<
              typename mpllibs::metaparse::get_result<
                // any never returns error
                boost::mpl::apply<
                  any,
                  typename mpllibs::metaparse::get_remaining<res>::type,
                  typename mpllibs::metaparse::get_position<res>::type
                >
              >::type,
              typename mpllibs::metaparse::get_result<res>::type
            >::type
          >,
          typename mpllibs::metaparse::get_remaining<
            // any never returns error
            boost::mpl::apply<
              any,
              typename mpllibs::metaparse::get_remaining<res>::type,
              typename mpllibs::metaparse::get_position<res>::type
            >
          >::type,
          typename mpllibs::metaparse::get_position<
            // any never returns error
            boost::mpl::apply<
              any,
              typename mpllibs::metaparse::get_remaining<res>::type,
              typename mpllibs::metaparse::get_position<res>::type
            >
          >::type
        >
      {};
    public:
      template <class s, class pos>
      struct apply :
        boost::mpl::eval_if<
          typename mpllibs::metaparse::is_error<
            boost::mpl::apply<p, s, pos>
          >::type,
          boost::mpl::apply<
            mpllibs::metaparse::return_<boost::mpl::list<> >,
            s,
            pos
          >,
          apply_unchecked<boost::mpl::apply<p, s, pos> >
        >
      {};
    };
  }
}

#endif

