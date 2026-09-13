class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)

        if n == 0:
            return 0

        prev = [0] * n

        for i in range(1, n + 1):
            curr = [0] * n

            for j in range(0, n - i + 1):
                curr[j] = prev[j] + nums[i + j - 1]

                if curr[j] >= target:
                    return i

            prev = curr
        return 0