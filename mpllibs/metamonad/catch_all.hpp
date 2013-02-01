#ifndef MPLLIBS_METAMONAD_CATCH_ALL_HPP
#define MPLLIBS_METAMONAD_CATCH_ALL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class E, class Handler>
    struct catch_all :
      eval_case<E,
        matches_c<exception<e>,
          boost::mpl::apply_wrap1<typename Handler::type, e>
        >,
        matches_c<_, E>
      >
    {};
  }
}

#endif

