# Currying

A [template metafunction](metafunction.html) supports _currying_ when it accepts
less arguments than it normally expects. When less arguments are provided, then
it returns a [template metafunction class](metafunction_class.html) expecting
the remaining arguments. That template metafunction class is also expected to
support currying.

For example assuming the following metafunction is given:

```cpp
template <class A, class B>
struct plus;
```

It takes two values, adds them and returns their result. For example:

```cpp
static_assert(
  plus<
    std::integral_constant<int, 11>,
    std::integral_constant<int, 2>
  >::type::value == 13,
  "This should work"
);
```

If it supports currying, then the following should also work:

```cpp
using inc = plus<std::integral_constant<int, 1>>;

static_assert(
  inc::apply<std::integral_constant<int, 12>>::type::value == 13,
  "This should work"
);
```

The above example defines the `inc` template metafunction class by calling
`plus` with just one argument: the [boxed](boxed_value.html) `1` value.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

