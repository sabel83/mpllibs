#ifndef MPLLIBS_METAPARSE_ANY_HPP
#define MPLLIBS_METAPARSE_ANY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/push_front.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct any
    {
    private:
      template <class Res>
      struct apply_unchecked :
        boost::mpl::apply<
          return_<
            typename boost::mpl::push_front<
              typename get_result<
                // any never returns error
                boost::mpl::apply<
                  any,
                  typename get_remaining<Res>::type,
                  typename get_position<Res>::type
                >
              >::type,
              typename get_result<Res>::type
            >::type
          >,
          typename get_remaining<
            // any never returns error
            boost::mpl::apply<
              any,
              typename get_remaining<Res>::type,
              typename get_position<Res>::type
            >
          >::type,
          typename mpllibs::metaparse::get_position<
            // any never returns error
            boost::mpl::apply<
              any,
              typename get_remaining<Res>::type,
              typename get_position<Res>::type
            >
          >::type
        >
      {};
    public:
      template <class S, class Pos>
      struct apply :
        boost::mpl::eval_if<
          typename is_error<boost::mpl::apply<P, S, Pos> >::type,
          boost::mpl::apply<return_<boost::mpl::list<> >, S, Pos>,
          apply_unchecked<boost::mpl::apply<P, S, Pos> >
        >
      {};
    };
  }
}

#endif

