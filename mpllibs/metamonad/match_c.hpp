#ifndef MPLLIBS_METAMONAD_MATCH_C_HPP
#define MPLLIBS_METAMONAD_MATCH_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/is_exception.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/lazy_argument.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/unbox.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/unused_arg.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/instantiate.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/first.hpp>
#include <mpllibs/metamonad/second.hpp>
#include <mpllibs/metamonad/pair.hpp>
#include <mpllibs/metamonad/is_same.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/zip_view.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/push_back.hpp>

#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_LAZY_METAFUNCTION(bad_match, (Pattern)(Value))
    ((tmp_value<bad_match<Pattern, Value> >));

    template <class Pattern, class Value>
    struct match_impl :
      exception<bad_match<syntax<Pattern>, syntax<Value> > >
    {};

    template <class Pattern, class Value>
    struct match_c_impl : match_impl<Pattern, Value> {};

    template <class Value>
    struct match_c_impl<_, Value> : boost::mpl::map<> {};

    template <class Value>
    struct match_c_impl<Value, Value> : boost::mpl::map<> {};

    template <class Name, class Value>
    struct match_c_impl<var<Name>, Value> :
      boost::mpl::map<pair<var<Name>, syntax<Value> > >
    {};

    namespace impl
    {
      MPLLIBS_LAZY_METAFUNCTION(lazy_match_c_impl, (Pattern)(Value))
      ((match_c_impl<Pattern, Value>));
      
      MPLLIBS_METAFUNCTION(map_insert_impl, (P)(Pair))
      ((
        BOOST_PP_CAT(instantiate, BOOST_MPL_LIMIT_MAP_SIZE)<
          boost::mpl::map
        >::apply<
          typename if_<
            second<P>,
            boost::mpl::push_back<typename first<P>::type, Pair>,
            first<P>
          >::type
        >
      ));

      // It is needed because
      //   boost::mpl::insert<
      //     boost::mpl::map<>,
      //     pair<boost::mpl::int_<1>, boost::mpl::int_<2>>
      //   >::type:type
      // is
      //   boost::mpl::map<>
      MPLLIBS_METAFUNCTION(map_insert, (Map)(Pair))
      ((
        map_insert_impl<
          typename boost::mpl::fold<
            typename Map::type,
            pair<boost::mpl::vector<>, boost::mpl::true_>,
            lambda_c<s, c,
              if_<
                second<s>,
                if_<
                  is_same<first<c>, first<Pair> >,
                  pair<
                    lazy<
                      boost::mpl::push_back<
                        lazy_protect_args<first<s> >,
                        lazy_protect_args<Pair>
                      >
                    >,
                    boost::mpl::false_
                  >,
                  pair<
                    lazy<
                      boost::mpl::push_back<
                        lazy_protect_args<first<s> >,
                        already_lazy<c>
                      >
                    >,
                    boost::mpl::true_
                  >
                >,
                pair<
                  lazy<
                    boost::mpl::push_back<
                      lazy_protect_args<first<s> >,
                      already_lazy<c>
                    >
                  >,
                  boost::mpl::false_
                >
              >
            >
          >::type,
          typename Pair::type
        >
      ));

      typedef
        lambda_c<s, p,
          if_<
            is_exception<s>,
            s,
            if_<
              lazy<
                boost::mpl::has_key<
                  already_lazy<s>,
                  lazy_protect_args<first<p> >
                >
              >,
              if_<
                is_same<
                  lazy<
                    boost::mpl::at<
                      already_lazy<s>,
                      lazy_protect_args<first<p> >
                    >
                  >,
                  second<p>
                >,
                s,
                exception<bad_match<first<p>, second<p> > >
              >,
              map_insert<s, p>
            >
          >
        >
        merge_map_value;

      MPLLIBS_METAFUNCTION(merge_map, (A)(B))
      ((
        if_<
          is_exception<A>,
          A,
          if_<
            is_exception<B>,
            B,
            boost::mpl::fold<
              typename B::type,
              typename A::type,
              merge_map_value
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
          lambda_c<s, p,
            if_<
              is_exception<s>,
              s,
              merge_map<
                s,
                impl::lazy_match_c_impl<
                  unbox<boost::mpl::front<p> >,
                  unbox<boost::mpl::back<p> >
                >
              >
            >
          >
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
        match_impl< \
          T<BOOST_PP_ENUM_PARAMS(n, P)>, T<BOOST_PP_ENUM_PARAMS(n, V)> \
        > : \
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

    #ifdef MPLLIBS_PROTECT_MATCH
      #error MPLLIBS_PROTECT_MATCH already defined
    #endif
    #define MPLLIBS_PROTECT_MATCH(f) \
      template <class T> \
      struct f; \
      \
      template <class P, class E> \
      struct match_c_impl<f<P>, f<E> > : exception<bad_match<f<P>, f<E> > > {};\
      \
      template <class E> \
      struct match_c_impl<f<E>, f<E> > : boost::mpl::map<> {};

    MPLLIBS_PROTECT_MATCH(box)
    MPLLIBS_PROTECT_MATCH(syntax)

    #undef MPLLIBS_PROTECT_MATCH

    MPLLIBS_METAFUNCTION(match_c, (P)(V)) ((match_c_impl<P, typename V::type>));
  }
}

#endif

