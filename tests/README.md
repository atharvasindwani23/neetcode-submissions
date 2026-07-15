# Unit tests

Lightweight, dependency-free unit tests for the C++ solutions in this repo.

## Running

```bash
cd tests
make          # compile + run every test
make clean    # remove the built binary
```

Requires only a C++17 compiler (`g++`/`clang++`). No external libraries.

## Why a custom harness?

Each solution file is a bare `class Solution { ... };` with no `#include`s and
no `using namespace std;` — that scaffolding is normally supplied by the
NeetCode judge. To exercise a solution as a unit test we:

1. include [`harness.h`](harness.h), which pulls in the standard library and
   `using namespace std;`, and
2. `#include` the chosen submission inside a uniquely named namespace, so that
   many `class Solution` definitions can coexist in one test binary.

`harness.h` provides `TEST(name)`, `CHECK(cond)`, and `CHECK_EQ(actual, expected)`.
Failing assertions are reported without aborting, so one run surfaces every
failure. Leftover debug prints inside solutions are silenced during execution.

## Adding a test

```cpp
#include "harness.h"

namespace my_problem {
#include "../Data Structures & Algorithms/<problem-folder>/submission-0.cpp"
}

TEST(my_problem_basic) {
    my_problem::Solution s;
    CHECK_EQ(s.someMethod(...), expected);
}
```

Group related problems into one `test_<category>.cpp`; the `Makefile` picks up
every `test_*.cpp` automatically.

## Coverage

Before this suite the repository had **no tests at all**. These tests establish
a foundation covering a representative solution from each major category
(arrays & hashing, two pointers / sliding window, stack, binary search,
DP / greedy, bit manipulation). Extend by adding more `TEST` cases and
`test_*.cpp` files.
