#ifndef MPLLIBS_METAMONAD_DO_TRY_HPP
#define MPLLIBS_METAMONAD_DO_TRY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/do.hpp>
#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/get_data.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/tag.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/or.hpp>

#include <boost/type_traits/is_same.hpp>

/*
 * Catching exceptions happens by using
 *   do_try<...>
 *     ::catch_<Tag1, Name1>
 *       ::apply<Body1>
 *     ::catch_<Tag2, Name2>
 *       ::apply<Body2>
 * instead of
 *   do_try<...>
 *     ::catch_<Tag1, Name1, Body1>
 *     ::catch_<Tag2, Name2, Body2>
 * to avoid ambiguity related to
 *  http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_defects.html#147
 * caused by do_try<...>::catch_<...>::catch_<...> patterns.
 */

namespace mpllibs
{
  namespace metamonad
  {
    struct catch_any : tmp_value<catch_any> {};

    namespace impl
    {
      // evaluates result lazily
      template <class Result>
      struct skip_further_catches : returns<Result>
      {
        template <class ExceptionTag, class Name>
        MPLLIBS_METAFUNCTION_CLASS(catch_, (Body)) ((skip_further_catches));
      };
      
      MPLLIBS_METAFUNCTION(lazy_skip_further_catches, (Result))
      ((skip_further_catches<typename Result::type>));
      
      template <class Exception>
      struct was_exception : returns<Exception>
      {
        template <class ExceptionTag, class Name>
        MPLLIBS_METAFUNCTION_CLASS(catch_, (Body))
        ((
          typename boost::mpl::if_<
            boost::mpl::or_<
              boost::is_same<
                ExceptionTag,
                typename boost::mpl::tag<
                  typename get_data<Exception>::type
                >::type
              >,
              boost::is_same<ExceptionTag, catch_any>
            >,
            lazy_skip_further_catches<
              typename let<
                Name, typename get_data<Exception>::type,
                Body
              >::type
            >,
            was_exception
          >::type
        ));
      };
    }

    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_DO_MAX_ARGUMENT,
        class E,
        boost::mpl::na
      )
    >
    struct do_try :
      boost::mpl::if_<
        typename boost::is_same<
          exception_tag,
          typename boost::mpl::tag<
            typename do_<exception_monad,
              BOOST_PP_ENUM_PARAMS(MPLLIBS_DO_MAX_ARGUMENT, E)
            >::type
          >::type
        >::type,
        mpllibs::metamonad::impl::was_exception<
          typename do_<exception_monad,
            BOOST_PP_ENUM_PARAMS(MPLLIBS_DO_MAX_ARGUMENT, E)
          >::type
        >,
        mpllibs::metamonad::impl::skip_further_catches<
          typename do_<exception_monad,
            BOOST_PP_ENUM_PARAMS(MPLLIBS_DO_MAX_ARGUMENT, E)
          >::type
        >
      >::type
    {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  MPLLIBS_DO_MAX_ARGUMENT,
  mpllibs::metamonad::do_try,
  "do_try"
)

#endif

