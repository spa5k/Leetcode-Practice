#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#
# https://leetcode.com/problems/maximum-product-subarray/description/
#
# algorithms
# Medium (33.63%)
# Likes:    8739
# Dislikes: 273
# Total Accepted:    576K
# Total Submissions: 1.7M
# Testcase Example:  '[2,3,-2,4]'
#
# Given an integer array nums, find a contiguous non-empty subarray within the
# array that has the largest product, and return the product.
#
# It is guaranteed that the answer will fit in a 32-bit integer.
#
# A subarray is a contiguous subsequence of the array.
#
#
# Example 1:
#
#
# Input: nums = [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.
#
#
# Example 2:
#
#
# Input: nums = [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
#
#
#
# Constraints:
#
#
# 1 <= nums.length <= 2 * 10^4
# -10 <= nums[i] <= 10
# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
# integer.
#
#
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = max(nums)

        currMin, currMax = 1, 1

        for n in nums:
            if n == 0:  # it means if you find 0, then all of min max turns into 0
                currMax, currMin = 1, 1
                continue
            tmp = currMax*n
            # update current max to max among tmp, current Min *n or simply the n
            currMax = max(tmp, n*currMin, n)
            currMin = min(tmp, n*currMin, n)  # same for current Min
            res = max(res, currMax)  # update the res accordingly.
        return res
# @lc code=end
