#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSubArr = nums[0]

        currentSum = 0

        for n in nums:
            if currentSum < 0:
                currentSum = 0
            currentSum += n
            maxSubArr = max(currentSum, maxSubArr)
        return maxSubArr

# @lc code=end
