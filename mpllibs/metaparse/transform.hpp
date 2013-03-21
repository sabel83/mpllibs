#ifndef MPLLIBS_METAPARSE_TRANSFORM_HPP
#define MPLLIBS_METAPARSE_TRANSFORM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>
#include <mpllibs/metaparse/unless_error.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class T>
    struct transform
    {
    private:
      template <class R>
      struct apply_transformation_function :
        boost::mpl::apply<T, typename R::type>
      {};
      
    public:
      typedef transform type;
      
      template <class S, class Pos>
      struct apply :
        mpllibs::metaparse::unless_error<
          boost::mpl::apply<P, S, Pos>,
          boost::mpl::apply_wrap2<
            return_<
              apply_transformation_function<
                get_result<boost::mpl::apply<P, S, Pos> >
              >
            >,
            get_remaining<boost::mpl::apply<P, S, Pos> >,
            get_position<boost::mpl::apply<P, S, Pos> >
          >
        >
      {};
    };
  }
}

#endif

