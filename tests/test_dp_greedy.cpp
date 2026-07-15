#include "harness.h"

namespace climbing_stairs {
#include "../Data Structures & Algorithms/climbing-stairs/submission-1.cpp"
}
namespace house_robber {
#include "../Data Structures & Algorithms/house-robber/submission-2.cpp"
}
namespace coin_change {
#include "../Data Structures & Algorithms/coin-change/submission-3.cpp"
}
namespace maximum_subarray {
#include "../Data Structures & Algorithms/maximum-subarray/submission-2.cpp"
}
namespace buy_and_sell_crypto {
#include "../Data Structures & Algorithms/buy-and-sell-crypto/submission-0.cpp"
}

TEST(climbing_stairs_basic) {
    climbing_stairs::Solution s;
    CHECK_EQ(s.climbStairs(2), 2);
    CHECK_EQ(s.climbStairs(3), 3);
    CHECK_EQ(s.climbStairs(5), 8);
}

TEST(house_robber_basic) {
    house_robber::Solution s;
    vector<int> a{5};
    CHECK_EQ(s.rob(a), 5);
    vector<int> b{2, 3};
    CHECK_EQ(s.rob(b), 3);
    vector<int> c{2, 1, 7, 9, 3, 1};
    CHECK_EQ(s.rob(c), 12);
}

TEST(coin_change_basic) {
    coin_change::Solution s;
    vector<int> coins{1, 2, 5};
    CHECK_EQ(s.coinChange(coins, 11), 3);
    vector<int> coins2{2};
    CHECK_EQ(s.coinChange(coins2, 3), -1);
    CHECK_EQ(s.coinChange(coins, 0), 0);
}

TEST(maximum_subarray_basic) {
    maximum_subarray::Solution s;
    vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    CHECK_EQ(s.maxSubArray(a), 6);
    vector<int> b{5, 4, -1, 7, 8};
    CHECK_EQ(s.maxSubArray(b), 23);
    vector<int> c{-3};
    CHECK_EQ(s.maxSubArray(c), -3);
}

TEST(buy_and_sell_crypto_basic) {
    buy_and_sell_crypto::Solution s;
    vector<int> p{7, 1, 5, 3, 6, 4};
    CHECK_EQ(s.maxProfit(p), 5);
    vector<int> p2{7, 6, 4, 3, 1};
    CHECK_EQ(s.maxProfit(p2), 0);
}
