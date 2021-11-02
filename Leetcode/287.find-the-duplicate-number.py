#
# @lc app=leetcode id=287 lang=python3
#
# [287] Find the Duplicate Number
#

# @lc code=start
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for num in nums:
            absValue = abs(num)

            if nums[absValue-1] < 0:
                return absValue

            nums[absValue-1] *= -1
        return -1

# @lc code=end
