#ifndef MPLLIBS_METAMONAD_CATCH_JUST_HPP
#define MPLLIBS_METAMONAD_CATCH_JUST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class E, class Pred, class Handler>
    struct catch_just :
      eval_case<E,
        matches_c<exception<e>,
          lazy<
            boost::mpl::eval_if<
              boost::mpl::apply_wrap1<
                lazy_protect_args<Pred>,
                already_lazy<e>
              >,
              boost::mpl::apply_wrap1<
                lazy_protect_args<Handler>,
                already_lazy<e>
              >,
              already_lazy<E>
            >
          >
        >,
        matches_c<_, E>
      >
    {};
  }
}

#endif

