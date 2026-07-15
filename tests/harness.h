// Minimal, dependency-free unit-test harness for the NeetCode C++ solutions.
//
// Each solution file in this repo is a bare `class Solution { ... };` with no
// includes and no `using namespace std;` (that scaffolding is supplied by the
// NeetCode judge). To unit-test a solution we therefore:
//   1) include this header (which pulls in the standard library + `using std`),
//   2) `#include` the desired submission inside a uniquely named namespace so
//      that multiple `class Solution` definitions can coexist in one binary.
//
// Tests register themselves via the TEST() macro and are executed by main()
// (see main.cpp). CHECK*/ macros record failures without aborting so a single
// run reports every failing assertion.
#pragma once

#include <bits/stdc++.h>
using namespace std;

namespace testkit {

inline int& failure_count() {
    static int f = 0;
    return f;
}

inline int& assertion_count() {
    static int a = 0;
    return a;
}

struct TestCase {
    const char* name;
    void (*fn)();
};

inline vector<TestCase>& registry() {
    static vector<TestCase> r;
    return r;
}

struct Registrar {
    Registrar(const char* name, void (*fn)()) { registry().push_back({name, fn}); }
};

inline int run() {
    int failed_tests = 0;
    for (const auto& tc : registry()) {
        int before = failure_count();
        // Several archived solutions contain leftover debug prints; silence
        // their stdout so only test results are shown. Failed CHECK messages
        // go to std::cout and are captured/replayed below.
        std::ostringstream captured;
        std::streambuf* old = std::cout.rdbuf(captured.rdbuf());
        tc.fn();
        std::cout.rdbuf(old);
        if (failure_count() > before) {
            printf("[FAIL] %s\n", tc.name);
            std::cout << captured.str();
            ++failed_tests;
        } else {
            printf("[PASS] %s\n", tc.name);
        }
    }
    printf("\n%zu tests run, %d assertions, %d test(s) failed\n",
           registry().size(), assertion_count(), failed_tests);
    return failed_tests == 0 ? 0 : 1;
}

}  // namespace testkit

#define TEST(name)                                                        \
    static void name();                                                   \
    static ::testkit::Registrar registrar_##name(#name, name);            \
    static void name()

#define CHECK(cond)                                                       \
    do {                                                                  \
        ++::testkit::assertion_count();                                   \
        if (!(cond)) {                                                    \
            ++::testkit::failure_count();                                 \
            std::cout << "  CHECK failed: " #cond " (" << __FILE__ << ":" \
                      << __LINE__ << ")\n";                               \
        }                                                                 \
    } while (0)

#define CHECK_EQ(actual, expected)                                        \
    do {                                                                  \
        ++::testkit::assertion_count();                                   \
        auto _got = (actual);                                             \
        auto _exp = (expected);                                           \
        if (!(_got == _exp)) {                                            \
            ++::testkit::failure_count();                                 \
            std::cout << "  CHECK_EQ failed at " << __FILE__ << ":"       \
                      << __LINE__ << "\n";                                \
        }                                                                 \
    } while (0)
