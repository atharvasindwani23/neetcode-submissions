#ifndef NEETCODE_COMMON_LIST_NODE_H
#define NEETCODE_COMMON_LIST_NODE_H

// Singly-linked list node used by the linked-list problems in this repo.
//
// The NeetCode / LeetCode judge injects this definition automatically, so the
// submission files only carry it as a comment. This header exists as a single
// canonical reference and provides helpers for building/inspecting lists when
// you want to run a solution locally.

#include <initializer_list>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace neetcode {

// Build a list from values; returns the head (nullptr for an empty list).
inline ListNode *buildList(std::initializer_list<int> values) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

inline ListNode *buildList(const std::vector<int> &values) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// Collect list values into a vector.
inline std::vector<int> toVector(const ListNode *head) {
    std::vector<int> out;
    for (const ListNode *n = head; n != nullptr; n = n->next) {
        out.push_back(n->val);
    }
    return out;
}

// Free every node in a (non-cyclic) list.
inline void freeList(ListNode *head) {
    while (head != nullptr) {
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}

}  // namespace neetcode

#endif  // NEETCODE_COMMON_LIST_NODE_H
