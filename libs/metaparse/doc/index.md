# mpllibs::metaparse

Metaparse is parser generator library for template metaprograms. The purpose of
this library is to support the creation of parsers that parse at compile time.
This library is inteded to be used for embedded domain specific language
creation for C++. The input of the generated parser is a compile time string,
see [`string`](string.html). The result of the parsing process is either an
error or any other result the writer of the parser specifies.

The library is similar to Boost.Spirit, however while parsers built with Spirit
parse at run-time, parsers built with Metaparse parse at compile-time. Parsers
built with Metaparse can output:

 * types
 * objects (types with public static members)
 * callable C++ functions (types with public static method)
 * template metafunction classes 

Based on C++11 features the library can provide advanced utilities for defining
the input string, the rest of the library works on C++98-based compilers as
well.

* [Tutorial](https://github.com/sabel83/metaparse_tutorial#metaparse-tutorial)
* [User manual](manual.html)
* [Library reference](reference.html)
* [Performance](performance.html)

Related publications and blogs
------------------------------

Ábel Sinkovics, Dave Abrahams: <br />
*Using strings in C++ template metaprograms*, <br />
[http://cpp-next.com/archive/2012/10/using-strings-in-c-template-metaprograms/](
  http://cpp-next.com/archive/2012/10/using-strings-in-c-template-metaprograms/
)

Ábel Sinkovics, Zoltán Porkoláb: <br />
*Domain-Specific Language Integration with C++ Template Metaprogramming*, <br />
In Marjan Mernik (Ed): Formal and Practical Aspects of Domain-Specific
Languages: Recent Developments. Published by Information Science Reference (an
imprint of IGI Global), Hershey PA, USA. ISBN 978-1-4666-2092-6 (hardcover) -
ISBN 978-1-4666-2093-3 (ebook) - ISBN 978-1-4666-2094-0 pp. 33-56.
doi:10.4018/978-1-4666-2092-6.ch002

Ábel Sinkovics, Zoltán Porkoláb: <br />
*Metaparse - Compile-time Parsing with C++ Template Metaprogramming*, <br />
In C++Now! Aspen, Colorado, 15th May, 2012. <br />
[Talk](http://www.youtube.com/watch?v=v3XoWi0XbZk)

Zoltán Porkoláb, Ábel Sinkovics: <br />
*Domain-specific Language Integration with Compile-time Parser Generator
Library*, <br />
In Eelco Visser, Jaakko Järvi, editors, Proceedings of the ninth
international conference on Generative programming and component
engineering (GPCE 2010). ACM, October 2010, pp. 137-146.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](../../../index.html)


