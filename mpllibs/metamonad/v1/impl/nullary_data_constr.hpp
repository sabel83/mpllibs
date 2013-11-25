#ifndef MPLLIBS_METAMONAD_V1_NULLARY_DATA_CONSTR_HPP
#define MPLLIBS_METAMONAD_V1_NULLARY_DATA_CONSTR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/calculated_value.hpp>
#include <mpllibs/metamonad/v1/algebraic_data_type_tag.hpp>

#include <boost/preprocessor/stringize.hpp>

#include <string>

#ifdef MPLLIBS_V1_NULLARY_DATA_CONSTR
#  error MPLLIBS_V1_NULLARY_DATA_CONSTR already defined
#endif
#define MPLLIBS_V1_NULLARY_DATA_CONSTR(name, arity) \
  struct name : \
    mpllibs::metamonad::v1::calculated_value< \
      name, \
      std::string, \
      mpllibs::metamonad::v1::algebraic_data_type_tag \
    > \
  { \
    static std::string get_value() { return BOOST_PP_STRINGIZE(name); } \
  };

#endif

