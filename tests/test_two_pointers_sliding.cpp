#include "harness.h"

namespace is_palindrome {
#include "../Data Structures & Algorithms/is-palindrome/submission-0.cpp"
}
namespace max_water_container {
#include "../Data Structures & Algorithms/max-water-container/submission-0.cpp"
}
namespace trapping_rain_water {
#include "../Data Structures & Algorithms/trapping-rain-water/submission-0.cpp"
}
namespace longest_substring {
#include "../Data Structures & Algorithms/longest-substring-without-duplicates/submission-12.cpp"
}

TEST(is_palindrome_basic) {
    is_palindrome::Solution s;
    CHECK_EQ(s.isPalindrome("Was it a car or a cat I saw?"), true);
    CHECK_EQ(s.isPalindrome("tab a cat"), false);
}

TEST(max_water_container_basic) {
    max_water_container::Solution s;
    vector<int> h{1, 7, 2, 5, 4, 7, 3, 6};
    CHECK_EQ(s.maxArea(h), 36);
    vector<int> h2{2, 2, 2};
    CHECK_EQ(s.maxArea(h2), 4);
}

TEST(trapping_rain_water_basic) {
    trapping_rain_water::Solution s;
    vector<int> h{0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
    CHECK_EQ(s.trap(h), 9);
    vector<int> flat{4, 2, 0, 3, 2, 5};
    CHECK_EQ(s.trap(flat), 9);
}

TEST(longest_substring_basic) {
    longest_substring::Solution s;
    CHECK_EQ(s.lengthOfLongestSubstring("zxyzxyz"), 3);
    CHECK_EQ(s.lengthOfLongestSubstring("xxxx"), 1);
    CHECK_EQ(s.lengthOfLongestSubstring(""), 0);
}
