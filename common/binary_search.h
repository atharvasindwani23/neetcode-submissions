#ifndef NEETCODE_COMMON_BINARY_SEARCH_H
#define NEETCODE_COMMON_BINARY_SEARCH_H

// Predicate ("binary search on the answer") template shared by problems like
// koko eating bananas, capacity to ship packages, split array largest sum, etc.
//
// Those submissions all hand-roll the same lo/hi loop; this centralizes the
// off-by-one-safe version.

#include <cstdint>

namespace neetcode {

// Given a monotonic predicate that is false ... false, true ... true over the
// inclusive range [lo, hi], return the smallest x in [lo, hi] with pred(x) true.
// If no value satisfies pred, returns hi + 1.
template <typename Pred>
long long lowestTrue(long long lo, long long hi, Pred pred) {
    long long ans = hi + 1;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;  // avoids overflow
        if (pred(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// Mirror of lowestTrue for a predicate that is true ... true, false ... false:
// returns the largest x in [lo, hi] with pred(x) true, or lo - 1 if none.
template <typename Pred>
long long highestTrue(long long lo, long long hi, Pred pred) {
    long long ans = lo - 1;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (pred(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

}  // namespace neetcode

#endif  // NEETCODE_COMMON_BINARY_SEARCH_H
