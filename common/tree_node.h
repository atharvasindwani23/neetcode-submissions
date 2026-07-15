#ifndef NEETCODE_COMMON_TREE_NODE_H
#define NEETCODE_COMMON_TREE_NODE_H

// Binary tree node used by the tree problems in this repo.
//
// As with ListNode, the judge injects this definition, so the submissions carry
// it only as a comment. This header is the single canonical reference plus a few
// helpers for local testing.

#include <optional>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

namespace neetcode {

// Build a tree from a level-order list where std::nullopt marks a missing child
// (the same convention LeetCode uses for its serialized "[1,null,2,3]" form).
inline TreeNode *buildTree(const std::vector<std::optional<int>> &level) {
    if (level.empty() || !level.front().has_value()) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(*level.front());
    std::queue<TreeNode *> q;
    q.push(root);
    std::size_t i = 1;
    while (!q.empty() && i < level.size()) {
        TreeNode *node = q.front();
        q.pop();
        if (i < level.size() && level[i].has_value()) {
            node->left = new TreeNode(*level[i]);
            q.push(node->left);
        }
        ++i;
        if (i < level.size() && level[i].has_value()) {
            node->right = new TreeNode(*level[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

inline void inorder(const TreeNode *root, std::vector<int> &out) {
    if (root == nullptr) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

inline std::vector<int> inorder(const TreeNode *root) {
    std::vector<int> out;
    inorder(root, out);
    return out;
}

inline void freeTree(TreeNode *root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

}  // namespace neetcode

#endif  // NEETCODE_COMMON_TREE_NODE_H
