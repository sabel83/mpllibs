#ifndef MPLLIBS_METAMONAD_V1_IMPL_LET_DO_ARGS_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_LET_DO_ARGS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/do_c.hpp>
#include <mpllibs/metamonad/v1/fwd/do_.hpp>

#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/returns.hpp>
#include <mpllibs/metamonad/v1/eval_let_c.hpp>
#include <mpllibs/metamonad/v1/lazy.hpp>
#include <mpllibs/metamonad/v1/lazy_protect_args.hpp>
#include <mpllibs/metamonad/v1/eval_match_let_c.hpp>
#include <mpllibs/metamonad/v1/eval_case.hpp>
#include <mpllibs/metamonad/v1/eval_guard.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>
#include <mpllibs/metamonad/v1/is_same.hpp>
#include <mpllibs/metamonad/v1/set.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/push_back.hpp>

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
        struct let_do_c_;
        struct let_do_d_;
        struct let_do_n_;
        struct let_do_s_;
        struct let_do_v_;
        struct let_do_w_;

        typedef var<let_do_c_> let_do_c;
        typedef var<let_do_d_> let_do_d;
        typedef var<let_do_n_> let_do_n;
        typedef var<let_do_s_> let_do_s;
        typedef var<let_do_v_> let_do_v;
        typedef var<let_do_w_> let_do_w;

        MPLLIBS_V1_METAFUNCTION(let_do_args, (A)(E1)(V))
        ((
          boost::mpl::fold<
            V,
            pair<boost::mpl::vector<>, boost::mpl::true_>,
            lambda_c<let_do_s, let_do_c,
              eval_match_let_c<
                pair<let_do_v, let_do_d>,
                let_do_s,
                if_< let_do_d,
                  eval_case< eval_guard<let_do_c>,
                    matches_c<eval_guard<set<let_do_n, let_do_w> >,
                      if_<
                        is_same<A, let_do_n>,
                        pair<
                          boost::mpl::push_back<let_do_v, let_do_c>,
                          boost::mpl::false_
                        >,
                        pair<
                          lazy<
                            boost::mpl::push_back<
                              lazy_protect_args<let_do_v>,
                              lazy_protect_args<
                                eval_let_c<A, E1, set<let_do_n, let_do_w> >
                              >
                            >
                          >,
                          boost::mpl::true_
                        >
                      >
                    >,
                    matches_c<_,
                      pair<
                        lazy<
                          boost::mpl::push_back<
                            lazy_protect_args<let_do_v>,
                            lazy_protect_args<
                              eval_let_c<A, E1, returns<let_do_c> >
                            >
                          >
                        >,
                        boost::mpl::true_
                      >
                    >
                  >,
                  pair<
                    boost::mpl::push_back<let_do_v, let_do_c>,
                    boost::mpl::false_
                  >
                >
              >
            >
          >
        ));
      }
    }
  }
}

#endif

