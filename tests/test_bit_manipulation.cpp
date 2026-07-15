#include "harness.h"

namespace number_of_one_bits {
#include "../Data Structures & Algorithms/number-of-one-bits/submission-0.cpp"
}
namespace sum_of_two_integers {
#include "../Data Structures & Algorithms/sum-of-two-integers/submission-0.cpp"
}
namespace counting_bits {
#include "../Data Structures & Algorithms/counting-bits/submission-0.cpp"
}

TEST(number_of_one_bits_basic) {
    number_of_one_bits::Solution s;
    CHECK_EQ(s.hammingWeight(0), 0);
    CHECK_EQ(s.hammingWeight(11), 3);
    CHECK_EQ(s.hammingWeight(128), 1);
}

TEST(sum_of_two_integers_basic) {
    sum_of_two_integers::Solution s;
    CHECK_EQ(s.getSum(1, 2), 3);
    CHECK_EQ(s.getSum(-1, 1), 0);
    CHECK_EQ(s.getSum(-2, -3), -5);
}

TEST(counting_bits_basic) {
    counting_bits::Solution s;
    CHECK_EQ(s.countBits(5), (vector<int>{0, 1, 1, 2, 1, 2}));
}
