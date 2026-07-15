#include "harness.h"

namespace concatenation_of_array {
#include "../Data Structures & Algorithms/concatenation-of-array/submission-0.cpp"
}
namespace duplicate_integer {
#include "../Data Structures & Algorithms/duplicate-integer/submission-1.cpp"
}
namespace is_anagram {
#include "../Data Structures & Algorithms/is-anagram/submission-0.cpp"
}
namespace two_integer_sum {
#include "../Data Structures & Algorithms/two-integer-sum/submission-0.cpp"
}
namespace anagram_groups {
#include "../Data Structures & Algorithms/anagram-groups/submission-0.cpp"
}
namespace top_k_elements {
#include "../Data Structures & Algorithms/top-k-elements-in-list/submission-0.cpp"
}
namespace products_except_self {
#include "../Data Structures & Algorithms/products-of-array-discluding-self/submission-0.cpp"
}
namespace single_number {
#include "../Data Structures & Algorithms/single-number/submission-1.cpp"
}
namespace majority_element {
#include "../Data Structures & Algorithms/majority-element/submission-0.cpp"
}
namespace missing_number {
#include "../Data Structures & Algorithms/missing-number/submission-0.cpp"
}
namespace plus_one {
#include "../Data Structures & Algorithms/plus-one/submission-3.cpp"
}

// Normalizes a list of groups so it can be compared regardless of ordering.
static vector<vector<string>> normalizeGroups(vector<vector<string>> groups) {
    for (auto& g : groups) sort(g.begin(), g.end());
    sort(groups.begin(), groups.end());
    return groups;
}

TEST(concatenation_of_array_basic) {
    concatenation_of_array::Solution s;
    vector<int> a{1, 2, 1};
    CHECK_EQ(s.getConcatenation(a), (vector<int>{1, 2, 1, 1, 2, 1}));
    vector<int> b{1, 3, 2, 1};
    CHECK_EQ(s.getConcatenation(b), (vector<int>{1, 3, 2, 1, 1, 3, 2, 1}));
}

TEST(duplicate_integer_basic) {
    duplicate_integer::Solution s;
    vector<int> dup{1, 2, 3, 3};
    vector<int> uniq{1, 2, 3, 4};
    CHECK_EQ(s.hasDuplicate(dup), true);
    CHECK_EQ(s.hasDuplicate(uniq), false);
}

TEST(is_anagram_basic) {
    is_anagram::Solution s;
    CHECK_EQ(s.isAnagram("racecar", "carrace"), true);
    CHECK_EQ(s.isAnagram("jar", "jam"), false);
    CHECK_EQ(s.isAnagram("aacc", "ccac"), false);
}

TEST(two_integer_sum_basic) {
    two_integer_sum::Solution s;
    vector<int> nums{3, 4, 5, 6};
    CHECK_EQ(s.twoSum(nums, 7), (vector<int>{0, 1}));
    vector<int> nums2{4, 5, 6};
    CHECK_EQ(s.twoSum(nums2, 10), (vector<int>{0, 2}));
}

TEST(anagram_groups_basic) {
    anagram_groups::Solution s;
    vector<string> strs{"act", "pots", "tops", "cat", "stop", "hat"};
    auto got = normalizeGroups(s.groupAnagrams(strs));
    auto exp = normalizeGroups({{"act", "cat"}, {"pots", "tops", "stop"}, {"hat"}});
    CHECK_EQ(got, exp);
}

TEST(top_k_elements_basic) {
    top_k_elements::Solution s;
    vector<int> nums{1, 2, 2, 3, 3, 3};
    auto got = s.topKFrequent(nums, 2);
    sort(got.begin(), got.end());
    CHECK_EQ(got, (vector<int>{2, 3}));
}

TEST(products_except_self_basic) {
    products_except_self::Solution s;
    vector<int> nums{1, 2, 4, 6};
    CHECK_EQ(s.productExceptSelf(nums), (vector<int>{48, 24, 12, 8}));
    vector<int> nums2{-1, 0, 1, 2, 3};
    CHECK_EQ(s.productExceptSelf(nums2), (vector<int>{0, -6, 0, 0, 0}));
}

TEST(single_number_basic) {
    single_number::Solution s;
    vector<int> nums{1, 2, 3, 2, 1};
    CHECK_EQ(s.singleNumber(nums), 3);
}

TEST(majority_element_basic) {
    majority_element::Solution s;
    vector<int> nums{1, 1, 1, 2, 3};
    CHECK_EQ(s.majorityElement(nums), 1);
}

TEST(missing_number_basic) {
    missing_number::Solution s;
    vector<int> nums{3, 0, 1};
    CHECK_EQ(s.missingNumber(nums), 2);
    vector<int> nums2{0, 1};
    CHECK_EQ(s.missingNumber(nums2), 2);
}

TEST(plus_one_basic) {
    plus_one::Solution s;
    vector<int> d{1, 2, 3};
    CHECK_EQ(s.plusOne(d), (vector<int>{1, 2, 4}));
    vector<int> d2{4, 3, 2, 1};
    CHECK_EQ(s.plusOne(d2), (vector<int>{4, 3, 2, 2}));
}
