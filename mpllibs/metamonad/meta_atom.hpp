#ifndef MPLLIBS_METAMONAD_META_ATOM_HPP
#define MPLLIBS_METAMONAD_META_ATOM_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// I use a template class to avoid linking issues

#ifdef MPLLIBS_DEFINE_META_ATOM
  #error MPLLIBS_DEFINE_META_ATOM already defined
#endif
#define MPLLIBS_DEFINE_META_ATOM(tag_type, name) \
  struct name \
  { \
  private: \
    template <class> \
    struct name_of_class_impl \
    { \
      static const char* value; \
    }; \
  public: \
    typedef name type; \
    typedef tag_type tag; \
    typedef name_of_class_impl<int> name_of_class; \
  }; \
  \
  template <class T> \
  const char* name::name_of_class_impl<T>::value = #name

#endif

