#ifndef MPLLIBS_METAMONAD_V1_IMPL_DEFINE_TD_METAFUNCTION_GET_TAG_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_DEFINE_TD_METAFUNCTION_GET_TAG_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/define_td_metafunction_eval_arg.hpp>

#include <boost/mpl/tag.hpp>

#ifdef MPLLIBS_V1_DEFINE_TD_METAFUNCTION_GET_TAG
#  error MPLLIBS_V1_DEFINE_TD_METAFUNCTION_GET_TAG already defined
#endif
#define MPLLIBS_V1_DEFINE_TD_METAFUNCTION_GET_TAG(z, n, unused) \
  typename boost::mpl::tag< \
    MPLLIBS_V1_DEFINE_TD_METAFUNCTION_EVAL_ARG(z, n, unused) \
  >::type

#endif

