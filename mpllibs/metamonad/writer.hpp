#ifndef MPLLIBS_METAMONAD_WRITER_HPP
#define MPLLIBS_METAMONAD_WRITER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/mappend.hpp>
#include <mpllibs/metamonad/first.hpp>
#include <mpllibs/metamonad/second.hpp>
#include <mpllibs/metamonad/pair.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class M>
    struct writer_tag {};
    
    template <class M>
    struct monad<writer_tag<M> > : monad_defaults<writer_tag<M> >
    {
      typedef lambda_c<t, pair<t, mempty<M> > > return_;

      typedef
        lambda_c<a, f,
          pair<
            first<
              lazy<
                boost::mpl::apply_wrap1<
                  lazy_protect_args<f>,
                  first<lazy_protect_args<a> >
                >
              >
            >,
            mappend<
              M,
              second<a>,
              second<
                lazy<
                  boost::mpl::apply_wrap1<
                    lazy_protect_args<f>,
                    first<lazy_protect_args<a> >
                  >
                >
              >
            >
          >
        >
        bind;
    };
  }
}

#endif

