#ifndef MPLLIBS_METAPARSE_LIT_HPP
#define MPLLIBS_METAPARSE_LIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept_when.hpp>
#include <mpllibs/metaparse/one_char.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/push_back.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      template <class C>
      struct literal_expected :
        boost::mpl::push_back<boost::mpl::string<'expe','cted',': '>, C>
      {};
    }
  
    template <class C>
    struct lit :
      accept_when<
        one_char,
        typename boost::mpl::lambda<
          boost::mpl::equal_to<boost::mpl::_1, C>
        >::type,
        mpllibs::metaparse::errors::literal_expected<C>
      >
    {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, mpllibs::metaparse::lit, "lit")

#endif


