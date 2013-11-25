#ifndef MPLLIBS_METAMONAD_V1_CASE_HPP
#define MPLLIBS_METAMONAD_V1_CASE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/case_.hpp>
#include <mpllibs/metamonad/v1/impl/maybe.hpp>
#include <mpllibs/metamonad/v1/impl/case_check_match.hpp>
#include <mpllibs/metamonad/v1/impl/get_just_data.hpp>

#include <mpllibs/metamonad/v1/exception.hpp>
#include <mpllibs/metamonad/v1/eval_let.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/is_same.hpp>
#include <mpllibs/metamonad/v1/no_case_matched.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        // Custom names are needed to avoid "let"'s A be the same as one of the
        // names used
        struct let_case_c_;
        struct let_case_r_;
        struct let_case_s_;

        typedef var<let_case_c_> let_case_c;
        typedef var<let_case_r_> let_case_r;
        typedef var<let_case_s_> let_case_s;
      }

      template <class E, BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_CASE_SIZE, class C)>
      struct case_ :
        eval_let<
          impl::let_case_r,
          syntax<
            boost::mpl::fold<
              boost::mpl::vector<
                BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_CASE_SIZE, C)
              >,
              nothing,
              lambda_c<impl::let_case_s, impl::let_case_c,
                // s:
                //  nothing -> no case matched so far
                //  just<X> -> a case matched, the result is X
                if_<
                  is_same<nothing, impl::let_case_s>,
                  impl::case_check_match<E, impl::let_case_c>,
                  impl::let_case_s
                >
              >
            >
          >,
          syntax<
            if_<
              is_same<nothing, impl::let_case_r>,
              exception<no_case_matched<E> >,
              impl::get_just_data<impl::let_case_r>
            >
          >
        >
      {};
    }
  }
}

#endif

