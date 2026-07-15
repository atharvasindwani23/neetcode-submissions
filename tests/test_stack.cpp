#include "harness.h"

namespace validate_parentheses {
#include "../Data Structures & Algorithms/validate-parentheses/submission-3.cpp"
}
namespace eval_rpn {
#include "../Data Structures & Algorithms/evaluate-reverse-polish-notation/submission-0.cpp"
}
namespace baseball_game {
#include "../Data Structures & Algorithms/baseball-game/submission-0.cpp"
}
namespace daily_temperatures {
#include "../Data Structures & Algorithms/daily-temperatures/submission-2.cpp"
}

TEST(validate_parentheses_basic) {
    validate_parentheses::Solution s;
    CHECK_EQ(s.isValid("()"), true);
    CHECK_EQ(s.isValid("([{}])"), true);
    CHECK_EQ(s.isValid("(]"), false);
    CHECK_EQ(s.isValid("([)]"), false);
}

TEST(eval_rpn_basic) {
    eval_rpn::Solution s;
    vector<string> t1{"1", "2", "+", "3", "*"};
    CHECK_EQ(s.evalRPN(t1), 9);
    vector<string> t2{"4", "13", "5", "/", "+"};
    CHECK_EQ(s.evalRPN(t2), 6);
}

TEST(baseball_game_basic) {
    baseball_game::Solution s;
    vector<string> ops{"5", "2", "C", "D", "+"};
    CHECK_EQ(s.calPoints(ops), 30);
}

TEST(daily_temperatures_basic) {
    daily_temperatures::Solution s;
    vector<int> t{30, 38, 30, 36, 35, 40, 28};
    CHECK_EQ(s.dailyTemperatures(t), (vector<int>{1, 4, 1, 2, 1, 0, 0}));
}
