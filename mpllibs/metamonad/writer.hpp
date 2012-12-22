#ifndef MPLLIBS_METAMONAD_WRITER_HPP
#define MPLLIBS_METAMONAD_WRITER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>
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
      MPLLIBS_METAFUNCTION_CLASS(return_, (T))
      ((returns<boost::mpl::pair<T, typename monoid<M>::mempty> >));
      
      MPLLIBS_METAFUNCTION_CLASS(bind, (A)(F))
      ((
        lazy<
          boost::mpl::pair<
            boost::mpl::first<
              boost::mpl::apply_wrap1<
                boost::mpl::lambda<F>,
                boost::mpl::first<A>
              >
            >,
            boost::mpl::apply<
              typename monoid<M>::mappend,
              boost::mpl::second<A>,
              boost::mpl::second<
                boost::mpl::apply_wrap1<
                  boost::mpl::lambda<F>,
                  boost::mpl::first<A>
                >
              >
            >
          >
        >
      ));
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::writer_tag,
  "writer_tag"
)

#endif

