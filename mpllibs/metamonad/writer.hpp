#ifndef MPLLIBS_METAMONAD_WRITER_HPP
#define MPLLIBS_METAMONAD_WRITER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/mappend.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/pair.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class M>
    struct writer_tag {};
    
    template <class M>
    struct monad<writer_tag<M> > : monad_defaults<writer_tag<M> >
    {
      typedef
        lambda_c<t,
          lazy<
            boost::mpl::pair<already_lazy<t>, mpllibs::metamonad::mempty<M> >
          >
        >
        return_;

      typedef
        lambda_c<a, f,
          lazy<
            boost::mpl::pair<
              boost::mpl::first<
                boost::mpl::apply_wrap1<
                  boost::mpl::lambda<f>,
                  boost::mpl::first<a>
                >
              >,
              mpllibs::metamonad::mappend<
                already_lazy<M>,
                boost::mpl::second<a>,
                boost::mpl::second<
                  boost::mpl::apply_wrap1<
                    boost::mpl::lambda<f>,
                    boost::mpl::first<a>
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

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::writer_tag,
  "writer_tag"
)

#endif

