# list monad

This is the C++ template metaprogramming equivalent of Haskell's List monad.
Monadic values are `boost::mpl::list` values.

## General information

* header: `<mpllibs/metamonad/list.hpp>`
* tag of monad: [`list_tag`](list_tag.html)
* `return`'s logic: creates a one-element list from the argument
* `bind`'s logic: maps the operation on all elements of the input list and
  concatenates the resulting lists.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


