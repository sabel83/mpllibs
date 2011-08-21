#ifndef MPLLIBS_METATEST_TO_STREAM_INTEGRAL_CONSTANT_HPP
#define MPLLIBS_METATEST_TO_STREAM_INTEGRAL_CONSTANT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/character_printer.hpp>

#include <boost/assert.hpp>

namespace mpllibs
{
  namespace metatest
  {
    template <class>
    struct to_stream;
  
    template <class ValueType, ValueType Value>
    struct to_stream_integral_constant
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        to_stream<ValueType>::run(o_ << "integral_c<");
        return o_ << ", " << Value << ">";
      }
    };

    template <bool Value>
    struct to_stream_integral_constant<bool, Value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << (Value ? "true_" : "false_");
      }
    };

    template <int Value>
    struct to_stream_integral_constant<int, Value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "int_<" << Value << ">";
      }
    };

    template <long Value>
    struct to_stream_integral_constant<long, Value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "long_<" << Value << ">";
      }
    };
    
    template <char Value>
    struct to_stream_integral_constant<char, Value>
    {
      typedef to_stream_integral_constant type;
        
      static std::ostream& run(std::ostream& o_)
      {
        BOOST_ASSERT(sizeof(char) == 1);

        o_ << "char_<\'";
        character_printer(o_).operator()(Value);
        return o_ << "\'>";
      }
    };
  }
}    

#endif

