#ifndef MPLLIBS_METAMONAD_V1_IMPL_MATCH_C_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MATCH_C_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/fwd/match_c_impl.hpp>
#include <mpllibs/metamonad/v1/fwd/exception.hpp>
#include <mpllibs/metamonad/v1/fwd/box.hpp>

#include <mpllibs/metamonad/v1/impl/match_impl.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>
#include <mpllibs/metamonad/v1/bad_match.hpp>

#include <boost/mpl/map.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class Pattern, class Value>
        struct match_c_impl : match_impl<Pattern, Value> {};

        template <class Value>
        struct match_c_impl<_, Value> : boost::mpl::map<> {};

        template <class Value>
        struct match_c_impl<Value, Value> : boost::mpl::map<> {};

        template <class Name, class Value>
        struct match_c_impl<var<Name>, Value> :
          boost::mpl::map<pair<var<Name>, syntax<Value> > >
        {};

        #ifdef MPLLIBS_PROTECT_MATCH
        #  error MPLLIBS_PROTECT_MATCH already defined
        #endif
        #define MPLLIBS_PROTECT_MATCH(f) \
          template <class P, class E> \
          struct match_c_impl<f<P>, f<E> > : \
            exception<bad_match<f<P>, f<E> > > \
          {};\
          \
          template <class E> \
          struct match_c_impl<f<E>, f<E> > : boost::mpl::map<> {};
  
        MPLLIBS_PROTECT_MATCH(box)
        MPLLIBS_PROTECT_MATCH(syntax)

        #undef MPLLIBS_PROTECT_MATCH
      }
    }
  }
}

#endif

