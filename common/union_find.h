#ifndef NEETCODE_COMMON_UNION_FIND_H
#define NEETCODE_COMMON_UNION_FIND_H

// Disjoint-set / union-find with path compression and union by size.
//
// Several graph problems in this repo (connected components, redundant
// connection, accounts merge, etc.) re-implement this from scratch. This is the
// canonical version to copy from.

#include <numeric>
#include <vector>

namespace neetcode {

class UnionFind {
public:
    explicit UnionFind(int n) : parent_(n), size_(n, 1), count_(n) {
        std::iota(parent_.begin(), parent_.end(), 0);
    }

    int find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];  // path compression
            x = parent_[x];
        }
        return x;
    }

    // Returns true if x and y were in different sets (i.e. a merge happened).
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (size_[rx] < size_[ry]) std::swap(rx, ry);
        parent_[ry] = rx;
        size_[rx] += size_[ry];
        --count_;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int componentSize(int x) { return size_[find(x)]; }

    // Number of disjoint sets remaining.
    int count() const { return count_; }

private:
    std::vector<int> parent_;
    std::vector<int> size_;
    int count_;
};

}  // namespace neetcode

#endif  // NEETCODE_COMMON_UNION_FIND_H
