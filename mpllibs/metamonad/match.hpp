#ifndef MPLLIBS_METAMONAD_MATCH_HPP
#define MPLLIBS_METAMONAD_MATCH_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/is_exception.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/unbox.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/zip_view.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>

#include <boost/type_traits.hpp>

#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct _ : tmp_value<_> {};

    MPLLIBS_METAFUNCTION(bad_match, (Pattern)(Value))
    ((tmp_value<bad_match<Pattern, Value> >));

    MPLLIBS_METAFUNCTION(var, (Name)) ((tmp_value<var<Name> >));

    template <class Pattern, class Value>
    struct match : exception<bad_match<Pattern, Value> > {};

    template <class Value>
    struct match<_, Value> : boost::mpl::map<> {};

    template <class Value>
    struct match<Value, Value> : boost::mpl::map<> {};

    template <class Name, class Value>
    struct match<var<Name>, Value> :
      boost::mpl::map<boost::mpl::pair<Name, Value> >
    {};

    namespace impl
    {
      MPLLIBS_METAFUNCTION_CLASS(merge_map_value, (S)(P))
      ((
        boost::mpl::eval_if<
          typename is_exception<S>::type,
          returns<S>,
          lazy<
            boost::mpl::eval_if<
              boost::mpl::has_key<
                already_lazy<S>,
                boost::mpl::first<already_lazy<P> >
              >,
              boost::mpl::eval_if<
                boost::is_same<
                  boost::mpl::at<
                    already_lazy<S>,
                    boost::mpl::first<already_lazy<P> >
                  >,
                  boost::mpl::second<already_lazy<P> >
                >,
                already_lazy<S>,
                exception<
                  bad_match<
                    boost::mpl::first<already_lazy<P> >,
                    boost::mpl::second<already_lazy<P> >
                  >
                >
              >,
              boost::mpl::insert<already_lazy<S>, already_lazy<P> >
            >
          >
        >
      ));

      MPLLIBS_METAFUNCTION(merge_map, (A)(B))
      ((
        boost::mpl::eval_if<
          typename is_exception<A>::type,
          returns<A>,
          boost::mpl::eval_if<
            typename is_exception<B>::type,
            returns<B>,
            boost::mpl::fold<B, A, merge_map_value>
          >
        >
      ));
  
      MPLLIBS_METAFUNCTION_CLASS(match_impl_op, (S)(P))
      ((
        boost::mpl::eval_if<
          typename is_exception<S>::type,
          returns<S>,
          lazy<
            merge_map<
              already_lazy<S>,
              match<
                unbox<boost::mpl::front<already_lazy<P> > >,
                unbox<boost::mpl::back<already_lazy<P> > >
              >
            >
          >
        >
      ));
  
      // Elements of Ps and Vs are boxed because Ps or Vs may contain mpl::na in
      // which case Ps and Vs have different sizes and zip_view can not handle
      // that.
      MPLLIBS_METAFUNCTION(match_impl, (Ps)(Vs))
      ((
        boost::mpl::fold<
          boost::mpl::zip_view<boost::mpl::vector<Ps, Vs> >,
          boost::mpl::map<>,
          match_impl_op
        >
      ));
    }

    #ifdef MPLLIBS_WRAPPED
      #error MPLLIBS_WRAPPED already defined
    #endif
    #define MPLLIBS_WRAPPED(z, n, name) box<BOOST_PP_CAT(name, n)>

    #ifdef MPLLIBS_MATCH_TEMPLATE
      #error MPLLIBS_MATCH_TEMPLATE already defined
    #endif
    #define MPLLIBS_MATCH_TEMPLATE(z, n, unused) \
      template < \
        template <BOOST_PP_ENUM(n, class BOOST_PP_TUPLE_EAT(3), ~)> class T, \
        BOOST_PP_ENUM_PARAMS(n, class P), \
        BOOST_PP_ENUM_PARAMS(n, class V) \
      > \
      struct \
        match<T<BOOST_PP_ENUM_PARAMS(n, P)>, T<BOOST_PP_ENUM_PARAMS(n, V)> > : \
        impl::match_impl< \
          boost::mpl::vector<BOOST_PP_ENUM(n, MPLLIBS_WRAPPED, P)>, \
          boost::mpl::vector<BOOST_PP_ENUM(n, MPLLIBS_WRAPPED, V)> \
        > \
      {};

    BOOST_PP_REPEAT_FROM_TO(
      1,
      BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
      MPLLIBS_MATCH_TEMPLATE,
      ~
    )

    #undef MPLLIBS_MATCH_TEMPLATE
    #undef MPLLIBS_WRAPPED

  }
}

#endif

