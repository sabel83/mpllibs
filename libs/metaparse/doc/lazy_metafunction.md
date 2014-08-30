# Lazy template metafunction

A _lazy template metafunction_ is a [template metafunction](metafunction.html)
that accepts [nullary metafunction](nullary_metafunction.html)s as arguments,
that need to be evaluated first to get the value of the argument.

For example here is a `plus` metafunction for `int` values:

```cpp
template <class A, class B>
struct plus :
  std::integral_constant<int, A::value + B::value>
{};
```

This metafunction takes two [boxed](boxed_value.html) numbers as arguments,
unboxes them, adds their values and boxed the result again.

It works when it is called with boxed numbers. For example:

```cpp
static_assert(
  plus<
    std::intgeral_constant<int, 2>,
    std::integral_constant<int, 2>
  >::type::value == 4,
  "This should work"
);
```

However, when it is called with a nullary metafunction returning the boxed
value, it breaks:

```cpp
struct nullary_metafunction_returning_2
{
  using type = std::integral_constant<int, 2>;
};

// Fails to compile
plus<nullary_metafunction_returning_2, nullary_metafunction_returning_2>::type
```

So `plus` is _not_ a lazy template metafunction. To make it lazy, it has to
evaluate its arguments before using them:

```cpp
template <class A, class B>
struct lazy_plus :
  std::integral_constant<int, A::type::value + B::type::value>
{};
```

Note that it uses `A::type::value` and `B::type::value` instead of `A::value`
and `B::value`. It works when it is called with nullary metafunctions as well:

```cpp
static_assert(
  plus<
    nullary_metafunction_returning_2,
    nullary_metafunction_returning_2
  >::type::value == 4,
  "This should work"
);
```

Because it works with nullary metafunctions as arguments, it is a lazy template
metafunction.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

