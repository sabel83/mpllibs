# mpllibs::safe_printf

This library contains type-safe implementations of the `printf` functions.
It requires the format string to be available at compile time and typechecks
the rest of the arguments based on that as part of the compilation process.
In case of invalid usage, it emits compliation errors. These functions are
wrappers of the C functions without runtime overhead (they do have compile
time overhead, however).

## Functions

* [printf](printf.html)
* [sprintf](sprintf.html)
* [fprintf](fprintf.html)

## Metafunctions

* [expected_types](expected_types.html)
* [valid_arguments](valid_arguments.html)

## Versioning

* [Versioning](versioning.html)

## Related publications

Ábel Sinkovics, Zoltán Porkoláb: <br />
*Domain-Specific Language Integration with C++ Template Metaprogramming*, <br />
In Marjan Mernik (Ed): Formal and Practical Aspects of Domain-Specific
Languages: Recent Developments. Published by Information Science Reference (an
imprint of IGI Global), Hershey PA, USA. ISBN 978-1-4666-2092-6 (hardcover) -
ISBN 978-1-4666-2093-3 (ebook) - ISBN 978-1-4666-2094-0 pp. 33-56.
doi:10.4018/978-1-4666-2092-6.ch002

Zoltán Porkoláb, Ábel Sinkovics: <br />
*Domain-specific Language Integration with Compile-time Parser Generator
Library*, <br />
In Eelco Visser, Jaakko Järvi, editors, Proceedings of the ninth
international conference on Generative programming and component
engineering (GPCE 2010). ACM, October 2010, pp. 137-146.

Zalán Szűgyi, Ábel Sinkovics, Norbert Pataki, Zoltán Porkoláb: <br />
*C++ Metastring Library and its Applications*, <br />
In Proceedings of Generative and Transformational Techniques in Software
Engineering 2009, LNCS 6491, pp. 467-486

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](../../../index.html)


