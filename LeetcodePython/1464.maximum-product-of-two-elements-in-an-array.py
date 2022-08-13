#
# @lc app=leetcode id=1464 lang=python3
#
# [1464] Maximum Product of Two Elements in an Array
#
# https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/
#
# algorithms
# Easy (78.40%)
# Likes:    924
# Dislikes: 157
# Total Accepted:    128.8K
# Total Submissions: 164.2K
# Testcase Example:  '[3,4,5,2]'
#
# Given the array of integers nums, you will choose two different indices i and
# j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
#
# Example 1:
#
#
# Input: nums = [3,4,5,2]
# Output: 12
# Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will
# get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 =
# 12.
#
#
# Example 2:
#
#
# Input: nums = [1,5,4,5]
# Output: 16
# Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get
# the maximum value of (5-1)*(5-1) = 16.
#
#
# Example 3:
#
#
# Input: nums = [3,7]
# Output: 12
#
#
#
# Constraints:
#
#
# 2 <= nums.length <= 500
# 1 <= nums[i] <= 10^3
#
#
#

# @lc code=start
import heapq
from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        heaper = []

        for i in nums:
            heapq.heappush(heaper, (-i))

        num1 = -heapq.heappop(heaper)
        num2 = -heapq.heappop(heaper)

        return (num1 - 1) * (num2 - 1)


# @lc code=end
