#ifndef MPLLIBS_METAMONAD_V1_IMPL_CASE_CHECK_MATCH_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_CASE_CHECK_MATCH_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/maybe.hpp>

#include <mpllibs/metamonad/v1/matches_c.hpp>
#include <mpllibs/metamonad/v1/matches.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/is_exception.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>
#include <mpllibs/metamonad/v1/match_let.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class E, class C>
        struct case_check_match;

        template <class P, class E1, class E2>
        struct case_check_match<E1, matches_c<P, E2> > :
          case_check_match<E1, matches<syntax<P>, syntax<E2> > >
        {};

        template <class P, class E1, class E2>
        struct case_check_match<E1, matches<P, E2> > :
          if_<
            is_exception<match<P, E1> >,
            nothing,
            just<match_let<P, E1, E2> >
          >
        {};
      }
    }
  }
}

#endif

