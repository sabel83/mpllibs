```cpp
using exp_parser7 = build_parser< sequence< int_token,                           /* The first <number> */ any<sequence<plus_token, int_token>> /* The "+ <number>" elements */ > >;

```
