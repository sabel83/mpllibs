#ifndef MPLLIBS_METAMONAD_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/metafunction.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/curried_call.hpp>

#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/cat.hpp>

#ifdef MPLLIBS_METAFUNCTION
  #error MPLLIBS_METAFUNCTION already defined
#endif
#define MPLLIBS_METAFUNCTION(name, args) \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct BOOST_PP_CAT(name, ___impl); \
  \
  template <MPLLIBS_EXPAND_ARGS_USAGE_WITH_NA(args)> \
  struct name : \
    BOOST_PP_CAT(mpllibs::metamonad::curried_call, BOOST_PP_SEQ_SIZE(args))< \
      BOOST_PP_CAT(name, ___impl), \
      MPLLIBS_EXPAND_ARGS_REF(args) \
    > \
  {}; \
  \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct BOOST_PP_CAT(name, ___impl) : MPLLIBS_METAFUNCTION_BODY

#endif

