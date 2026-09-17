# `common/` — shared reference utilities

This directory is a **non-invasive reference library** for the duplicated code
patterns that show up across the C++ submissions in this repo. It is
documentation + reusable snippets — **the submission files are not modified and
do not depend on these headers.**

## Why it's separate (and not `#include`d by submissions)

The solutions here are synced from NeetCode / LeetCode. The online judge:

- compiles each submission **in isolation**, and
- injects the standard includes, `using namespace std;`, and the `ListNode` /
  `TreeNode` definitions for you (which is why those appear only as comments in
  the submissions).

So a submission cannot `#include "common/..."` — it would fail to compile on the
judge, and the change would be overwritten on the next sync anyway. Instead,
this library serves two purposes:

1. A **single canonical copy** of each repeated pattern, so there is one place
   to read/verify the "right" version.
2. **Runnable helpers** (list/tree builders, etc.) for exercising a solution
   locally, outside the judge.

## Contents

| Header | Canonical pattern | Example submissions that duplicate it |
|---|---|---|
| `list_node.h` | `ListNode` definition + `buildList` / `toVector` / `freeList` | `merge-two-sorted-linked-lists`, `middle-of-the-linked-list`, `merge-k-sorted-linked-lists` (~25 files carry the comment block) |
| `tree_node.h` | `TreeNode` definition + `buildTree` (level-order) / `inorder` / `freeTree` | `depth-of-binary-tree`, `valid-binary-search-tree`, `house-robber-iii` (~71 files carry the comment block) |
| `union_find.h` | Disjoint-set (path compression + union by size) | `count-connected-components`, `count-number-of-islands` (edge form) |
| `grid.h` | 4/8-direction moves, `inBounds`, `floodFillDfs`, `floodFillBfs` | `count-number-of-islands`, `pacific-atlantic-water-flow`, `word-ladder` (BFS) |
| `binary_search.h` | "binary search on the answer" (`lowestTrue` / `highestTrue`) | `eating-bananas`, `boats-to-save-people` |

## Local usage example

```cpp
#include "common/list_node.h"
#include "common/tree_node.h"
#include <cassert>

int main() {
    ListNode* head = neetcode::buildList({1, 2, 3});
    assert((neetcode::toVector(head) == std::vector<int>{1, 2, 3}));
    neetcode::freeList(head);

    TreeNode* root = neetcode::buildTree({1, std::nullopt, 2, 3});
    assert((neetcode::inorder(root) == std::vector<int>{1, 3, 2}));
    neetcode::freeTree(root);
}
```

Compile with any C++17 compiler from the repo root:

```
g++ -std=c++17 -I. your_local_test.cpp -o test && ./test
```

All headers are header-only, self-contained (they include what they use), and
guarded, so they can be included in any combination.
