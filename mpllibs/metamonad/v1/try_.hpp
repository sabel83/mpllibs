#ifndef MPLLIBS_METAMONAD_V1_TRY__HPP
#define MPLLIBS_METAMONAD_V1_TRY__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/try_.hpp>
#include <mpllibs/metamonad/v1/impl/handle_catch.hpp>

#include <mpllibs/metamonad/v1/make_monadic.hpp>
#include <mpllibs/metamonad/v1/exception.hpp>
#include <mpllibs/metamonad/v1/eval_case.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/var.hpp>
#include <mpllibs/metamonad/v1/second.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        struct try_a_;
        struct try_e_;
        struct try_s_;
  
        typedef var<try_a_> try_a;
        typedef var<try_e_> try_e;
        typedef var<try_s_> try_s;
      }

      template <
        class Expr, 
        BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, class Catch)
      >
      struct try_ :
        eval_case<
          make_monadic<exception_tag, Expr>,
          matches_c<
            exception<impl::try_e>,
            second<
              boost::mpl::fold<
                boost::mpl::vector<
                  BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY,Catch)
                >,
                pair<boost::mpl::true_, exception<impl::try_e> >,
                lambda_c<impl::try_s, impl::try_a,
                  eval_case<
                    impl::try_s,
                    matches_c<
                      pair<boost::mpl::true_, _>,
                      impl::handle_catch<impl::try_e, impl::try_a>
                    >,
                    matches_c<pair<boost::mpl::false_, _>, impl::try_s>
                  >
                >
              >
            >
          >,
          matches_c<_, make_monadic<exception_tag, Expr> >
        >
      {};
    }
  }
}

#endif

