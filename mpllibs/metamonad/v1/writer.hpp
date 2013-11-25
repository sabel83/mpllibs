#ifndef MPLLIBS_METAMONAD_V1_WRITER_HPP
#define MPLLIBS_METAMONAD_V1_WRITER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/writer_tag.hpp>
#include <mpllibs/metamonad/v1/monad.hpp>
#include <mpllibs/metamonad/v1/lambda.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/mappend.hpp>
#include <mpllibs/metamonad/v1/mempty.hpp>
#include <mpllibs/metamonad/v1/first.hpp>
#include <mpllibs/metamonad/v1/second.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class M>
      struct monad<writer_tag<M> > : monad_defaults<writer_tag<M> >
      {
        typedef lambda_c<t, pair<t, mempty<M> > > return_;

        typedef
          lambda_c<a, f,
            pair<
              first<apply<f, first<a> > >,
              mappend<M, second<a>, second<apply<f, first<a> > > >
            >
          >
          bind;
      };
    }
  }
}

#endif

