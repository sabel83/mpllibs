#ifndef MPLLIBS_PARSER_KEYWORD_H
#define MPLLIBS_PARSER_KEYWORD_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/lit.h>
#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/sequence.h>
#include <mpllibs/metaparse/last_of.h>

#include <mpllibs/metaparse/util/lazy_if.h>
#include <mpllibs/metaparse/util/define_data.h>

#include <mpllibs/metatest/to_stream.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    MPLLIBS_METAPARSE_DEFINE_DATA(accepted_keyword);

    template <class s, class result_type>
    struct keyword;
    
    namespace impl
    {
      template <class s, class result_type>
      struct nonemptyKeyword :
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit<typename boost::mpl::front<s>::type>,
          mpllibs::metaparse::keyword<
            typename boost::mpl::pop_front<s>::type,
            result_type
          >
        >
      {};
    }
    
    // Does not consume/check anything after the keyword
    template <class s, class result_type = mpllibs::metaparse::accepted_keyword>
    struct keyword :
      mpllibs::metaparse::util::lazy_if<
        boost::mpl::empty<s>,
        mpllibs::metaparse::return_<result_type>,
        mpllibs::metaparse::impl::nonemptyKeyword<s, result_type>
      >::type
    {};
  }
}

DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metaparse::accepted_keyword,
  "Accepted keyword"
)

#endif

