#ifndef MPLLIBS_METAMONAD_V1_READER_HPP
#define MPLLIBS_METAMONAD_V1_READER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/reader_tag.hpp>
#include <mpllibs/metamonad/v1/monad.hpp>
#include <mpllibs/metamonad/v1/lambda.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <>
      struct monad<reader_tag> : monad_defaults<reader_tag>
      {
        typedef lambda_c<t, _, t> return_;
        typedef lambda_c<a, f, r, apply<apply<f, apply<a, r> >, r> > bind;
      };
    }
  }
}

#endif

