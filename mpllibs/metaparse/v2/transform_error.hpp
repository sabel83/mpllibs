#ifndef MPLLIBS_METAPARSE_V2_TRANSFORM_ERROR_HPP
#define MPLLIBS_METAPARSE_V2_TRANSFORM_ERROR_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/is_error.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class F>
      struct transform_error
      {
        template <class S, class Pos>
        struct apply :
          boost::mpl::eval_if<
            typename is_error<boost::mpl::apply<P, S, Pos> >::type,
            boost::mpl::apply<F, typename boost::mpl::apply<P, S, Pos>::type>,
            boost::mpl::apply<P, S, Pos>
          >
        {};
        
        typedef transform_error type;
      };
    }
  }
}

#endif

