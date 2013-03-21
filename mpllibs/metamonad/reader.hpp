#ifndef MPLLIBS_METAMONAD_READER_HPP
#define MPLLIBS_METAMONAD_READER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct reader_tag : tmp_tag<reader_tag> {};
    
    template <>
    struct monad<reader_tag> : monad_defaults<reader_tag>
    {
      typedef lambda_c<t, _, t> return_;
      
      typedef
        lambda_c<a, f, r,
          lazy<
            boost::mpl::apply_wrap1<
              boost::mpl::apply_wrap1<
                boost::mpl::lambda<lazy_protect_args<f> >,
                boost::mpl::apply_wrap1<
                  boost::mpl::lambda<lazy_protect_args<a> >,
                  already_lazy<r>
                >
              >,
              already_lazy<r>
            >
          >
        >
        bind;
    };
  }
}

#endif

