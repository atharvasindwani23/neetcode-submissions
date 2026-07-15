#include "harness.h"

namespace sqrtx {
#include "../Data Structures & Algorithms/sqrtx/submission-1.cpp"
}
namespace eating_bananas {
#include "../Data Structures & Algorithms/eating-bananas/submission-2.cpp"
}

TEST(sqrtx_basic) {
    sqrtx::Solution s;
    CHECK_EQ(s.mySqrt(0), 0);
    CHECK_EQ(s.mySqrt(1), 1);
    CHECK_EQ(s.mySqrt(4), 2);
    CHECK_EQ(s.mySqrt(8), 2);
    CHECK_EQ(s.mySqrt(2147395600), 46340);
}

TEST(eating_bananas_basic) {
    eating_bananas::Solution s;
    vector<int> p1{3, 6, 7, 11};
    CHECK_EQ(s.minEatingSpeed(p1, 8), 4);
    vector<int> p2{30, 11, 23, 4, 20};
    CHECK_EQ(s.minEatingSpeed(p2, 5), 30);
    CHECK_EQ(s.minEatingSpeed(p2, 6), 23);
}
