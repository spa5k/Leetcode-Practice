#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        total = 0
        current = nums[0]
        min_length = len(nums)+1

        for right in range(len(nums)):
            total = total+nums[right]

            while total >= target:
                min_length = min(min_length, right-left+1)
                total = total-nums[left]
                left += 1

        return min_length if min_length <= len(nums)else 0


# @lc code=end
