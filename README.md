mpllibs
=======

[![Build Status](https://secure.travis-ci.org/sabel83/mpllibs.png?branch=master "Build Status")](http://travis-ci.org/sabel83/mpllibs)

Introduction
------------

Welcome to the website of *mpllibs*. This is a collection of C++ template
metaprogramming libraries.

Components
----------

*mpllibs* contains the following libraries:

* [metamonad](http://abel.web.elte.hu/mpllibs/metamonad) -
    Library implementing monads and exceptions in C++ template metaprograms
* [safe\_printf](http://abel.web.elte.hu/mpllibs/safe_printf) -
    A type-safe `printf`, `fprintf` and `sprintf` implementation

Metaparse has been moved to [Boost](http://boost.org/libs/metaparse) and is
available from
[version 1.61](http://www.boost.org/users/history/version_1_61_0.html). Changes
to the Mpllibs version:

* The namespace has changed from `mpllibs::metaparse` to `boost::metaparse`.
* `mpllibs::metaparse::v1` is not included in the Boost version. The `v1` of the
  Boost version is an updated (see the rest of the bullet points) version of
  `mpllibs::metaparse::v2`.
* Renamings:
    * `MPLLIBS_STRING` -> `BOOST_METAPARSE_STRING`
    * `MPLLIBS_DEFINE_ERROR` -> `BOOST_METAPARASE_DEFINE_ERROR`
    * `MPLLIBS_LIMIT` -> `BOOST_METAPARSE_LIMIT`
    * `any*` -> `repeated*`
    * `fold*p` -> `fold*_start_with_parser`
    * `fold*f*` -> `fold*_reject_incomplete*`
    * `repeatf*` -> `repeat_reject_incomplete*`
* Removals:
    * `parser_tag`

Getting the library
-------------------

* Download the source code from [github](http://github.com/sabel83/mpllibs).
* [build and install](http://abel.web.elte.hu/mpllibs/build.html) the library

License
-------

The libraries are published under the
[Boost Software License](http://www.boost.org/LICENSE_1_0.txt).



