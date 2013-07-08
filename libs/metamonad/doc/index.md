# mpllibs::metamonad

This library provides basic building blocks for constructing non-trivial
template metaprograms. The main things the library provides for template
metaprogramming:

* Let expressions
* Lambda expressions
* Algebraic data-types
* Pattern matching, case expressions
* Haskell typeclasses in template metaprograms
* Monads for template metaprograms
* The do notation
* Compile-time exceptions

The library provides metafunctions for the monadic operations, that can be
overridden.
The library implements an embedded domain specific language based on
Haskell's do notation for monads. Template metaprograms using it are easier to
read and to maintain. Even though the library was built based on Haskell,
developers can use it without knowing the Haskell language.

The library implements an error handling mechanism for template metaprograms
that is similar to exception handling in runtime code. The library calls this
technique compile-time exception handling and it is based on monads.

* [User manual](manual.html)
* [Library reference](reference.html)
* [Examples](
    https://github.com/sabel83/mpllibs/tree/master/libs/metamonad/example
  )

## Related publications

Ábel Sinkovics: <br />
*Boosting MPL with Haskell elements*, <br />
C++Now!, Aspen, Colorado, 13th May, 2013. <br />
[Talk](http://www.youtube.com/watch?v=aIj034VCUD8)

Ábel Sinkovics, Zoltán Porkoláb: <br />
*Implementing monads for C++ template metaprograms*, <br />
In Science of Computer Programming, Available online 23 January 2013, ISSN
0167-6423, 10.1016/j.scico.2013.01.002.

Ábel Sinkovics, Endre Sajó, Zoltán Porkoláb: <br />
*Towards more reliable C++ template metaprograms*, <br />
In Jaan Penjam: 12th Symposium on Programming Languages and Software Tools
(SPLST'11), Tallinn, Estonia, 5-7 October, 2011., pp. 260-271.

Ábel Sinkovics: <br />
*Nested Lamda Expressions with Let Expressions in C++ Template Metaprorgams*,
<br />
In Zoltán Porkoláb, Nortbert Pataki: Proceedings of Workshop of Generative
Technologies (WGT'11), Saarbrücken, Germany, 27th March, 2011., pp. 63-76.

Ábel Sinkovics: <br />
*Functional Extensions to the Boost Metaprogram Library*, <br />
In Electr. Notes Theor. Comput. Sci., 264(5):85-101, 2010

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](../../../index.html)
<br />
