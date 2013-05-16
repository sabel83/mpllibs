#ifndef META_HS_SEMANTIC_HPP
#define META_HS_SEMANTIC_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <ast.hpp>

#include <mpllibs/metaparse/util/curry.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/pair.hpp>

namespace semantic
{
  struct ref
  {
    typedef ref type;
  
    template <class Name>
    struct apply : ast::ref<Name> {};
  };
  
  struct value
  {
    typedef value type;
  
    template <class V>
    struct apply : ast::value<V> {};
  };
  
  struct lambda
  {
    typedef lambda type;
  
    template <class ArgName, class F>
    struct apply : ast::lambda<F, ArgName> {};
  };
  
  struct application
  {
    typedef application type;
  
    template <class Arg, class F>
    struct apply : ast::application<F, Arg> {};
  };
  
  class if_
  {
  private:
    template <class C, class T, class F>
    struct lazy_if : boost::mpl::if_<typename C::type, T, F> {};
  public:
    typedef if_ type;
  
    template <class Seq>
    struct apply :
      boost::mpl::apply_wrap2<
        application,
        typename boost::mpl::at_c<Seq, 2>::type,
        typename boost::mpl::apply_wrap2<
          application,
          typename boost::mpl::at_c<Seq, 1>::type,
          typename boost::mpl::apply_wrap2<
            application,
            typename boost::mpl::at_c<Seq, 0>::type,
            ast::value<mpllibs::metaparse::util::curry3<lazy_if> >
          >::type
        >::type
      >
    {};
  };
  
  struct binary_op
  {
    typedef binary_op type;
  
    template <class C, class Exp>
    struct apply :
      boost::mpl::apply_wrap2<
        application,
        typename boost::mpl::back<C>::type,
        typename boost::mpl::apply_wrap2<
          application,
          Exp,
          typename boost::mpl::apply_wrap1<
            ref,
            typename boost::mpl::front<C>::type
          >::type
        >::type
      >
    {};
  };
  
  struct pair
  {
    typedef pair type;
  
    template <class Seq>
    struct apply :
      boost::mpl::pair<
        typename boost::mpl::front<Seq>::type,
        ast::top_bound<typename boost::mpl::back<Seq>::type>
      >
    {};
  };
}

#endif

