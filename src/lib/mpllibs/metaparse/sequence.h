#ifndef MPLLIBS_PARSER_SEQUENCE_H
#define MPLLIBS_PARSER_SEQUENCE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/unless_nothing.h>
#include <mpllibs/metaparse/util/pair.h>
#include <mpllibs/metaparse/util/make_pair.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <class list_to_append, class pair>
      struct append_to_first :
        mpllibs::metaparse::util::make_pair<
          boost::mpl::push_back<
            list_to_append,
            typename boost::mpl::first<pair>::type
          >,
          boost::mpl::second<pair>
        >
      {};
    
      template <class accum, class s, class parser>
      struct apply_impl :
        mpllibs::metaparse::util::unless_nothing<
          boost::mpl::apply<parser, typename s::type>,
          mpllibs::metaparse::impl::append_to_first<
            typename accum::type,
            typename boost::mpl::apply<parser, typename s::type>::type
          >
        >
      {};
    
      struct apply_parser
      {
        template <class state, class parser>
        struct apply :
          mpllibs::metaparse::util::unless_nothing<
            state,
            mpllibs::metaparse::impl::apply_impl<
              boost::mpl::first<state>,
              boost::mpl::second<state>,
              parser
            >
          >
        {};
      };
    
      template <class ps, class s>
      struct sequence_impl :
        boost::mpl::fold<
          ps,
          mpllibs::metaparse::util::pair<boost::mpl::deque<>, s>,
          mpllibs::metaparse::impl::apply_parser
        >
      {};
    }
  
    template <class p1, class p2>
    struct sequence
    {
      template <class s>
      struct apply :
        mpllibs::metaparse::impl::sequence_impl<boost::mpl::vector<p1, p2>, s>
      {};
    };
  }
}

#endif

