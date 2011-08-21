#ifndef MPLLIBS_METATEST_CHARACTER_PRINTER_HPP
#define MPLLIBS_METATEST_CHARACTER_PRINTER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

namespace mpllibs
{
  namespace metatest
  {
    class character_printer
    {
    public:
      character_printer(std::ostream& o_) : _o(o_) {}
    
      void operator()(unsigned char c_)
      {
        switch (c_)
        {
        case '\0': _o << "\\0"; break;
        case '\n': _o << "\\n"; break;
        case '\t': _o << "\\t"; break;
        case '\b': _o << "\\b"; break;
        case '\v': _o << "\\v"; break;
        case '\r': _o << "\\r"; break;
        case '\f': _o << "\\f"; break;
        case '\a': _o << "\\a"; break;
        case '\\': _o << "\\\\"; break;
        case '\?': _o << "\\?"; break;
        case '\'': _o << "\\\'"; break;
        case '\"': _o << "\\\""; break;
        default:
          if (c_ > 31 && c_ != 127)
          {
            _o << c_;
          }
          else
          {
            using std::ios_base;
            using std::ios;
            
            _o << "\\x";
            
            const ios_base::fmtflags f = _o.flags();
            _o.flags(ios::hex);
            _o << (c_ & 0xf0) << (c_ & 0x0f);
            _o.flags(f);
          }
        }
      }
    private:
      std::ostream& _o;
    };
  }
}    

#endif

