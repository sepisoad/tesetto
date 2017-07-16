# tesetto
Dumb C Single Header Unit Test Library 

## usage

```c
#include "tesseto.h"

int main() {
  begin_tests();

  check_bool(true, true);
  check_bool(true, false);
  check_bool(true, true);
  check_int(-10, -10);
  check_int(-10, 10);
  check_uint(0, 10);
  check_uint(120, 120);
  check_char('a', 'b');
  check_char('z', 'z');
  check_string("aa", "cc");
  check_string("vvv", "vvv");
  check_double(-10.2, -10.2);
  check_double(-10.2, 10.2);
  
  finish_tests();
}
```

for more information please read the header file, it's less than 200 lines of code.
