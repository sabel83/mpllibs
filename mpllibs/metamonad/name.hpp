#ifndef MPLLIBS_METAMONAD_NAME_HPP
#define MPLLIBS_METAMONAD_NAME_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/var.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      struct a_;
      struct b_;
      struct c_;
      struct d_;
      struct e_;
      struct f_;
      struct g_;
      struct h_;
      struct i_;
      struct j_;
      struct k_;
      struct l_;
      struct m_;
      struct n_;
      struct o_;
      struct p_;
      struct q_;
      struct r_;
      struct s_;
      struct t_;
      struct u_;
      struct v_;
      struct w_;
      struct x_;
      struct y_;
      struct z_;
    }
    namespace name
    {
      typedef var<impl::a_> a;
      typedef var<impl::b_> b;
      typedef var<impl::c_> c;
      typedef var<impl::d_> d;
      typedef var<impl::e_> e;
      typedef var<impl::f_> f;
      typedef var<impl::g_> g;
      typedef var<impl::h_> h;
      typedef var<impl::i_> i;
      typedef var<impl::j_> j;
      typedef var<impl::k_> k;
      typedef var<impl::l_> l;
      typedef var<impl::m_> m;
      typedef var<impl::n_> n;
      typedef var<impl::o_> o;
      typedef var<impl::p_> p;
      typedef var<impl::q_> q;
      typedef var<impl::r_> r;
      typedef var<impl::s_> s;
      typedef var<impl::t_> t;
      typedef var<impl::u_> u;
      typedef var<impl::v_> v;
      typedef var<impl::w_> w;
      typedef var<impl::x_> x;
      typedef var<impl::y_> y;
      typedef var<impl::z_> z;
    }
    using namespace name;
  }
}

#endif

