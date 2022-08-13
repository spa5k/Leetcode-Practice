#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#
# https://leetcode.com/problems/minimum-size-subarray-sum/description/
#
# algorithms
# Medium (42.15%)
# Likes:    6170
# Dislikes: 182
# Total Accepted:    498.7K
# Total Submissions: 1.2M
# Testcase Example:  '7\n[2,3,1,2,4,3]'
#
# Given an array of positive integers nums and a positive integer target,
# return the minimal length of a contiguous subarray [numsl, numsl+1, ...,
# numsr-1, numsr] of which the sum is greater than or equal to target. If there
# is no such subarray, return 0 instead.
#
#
# Example 1:
#
#
# Input: target = 7, nums = [2,3,1,2,4,3]
# Output: 2
# Explanation: The subarray [4,3] has the minimal length under the problem
# constraint.
#
#
# Example 2:
#
#
# Input: target = 4, nums = [1,4,4]
# Output: 1
#
#
# Example 3:
#
#
# Input: target = 11, nums = [1,1,1,1,1,1,1,1]
# Output: 0
#
#
#
# Constraints:
#
#
# 1 <= target <= 10^9
# 1 <= nums.length <= 10^5
# 1 <= nums[i] <= 10^5
#
#
#
# Follow up: If you have figured out the O(n) solution, try coding another
# solution of which the time complexity is O(n log(n)).
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        total = 0
        min_length = len(nums) + 1
        for right in range(len(nums)):
            total += nums[right]

            while total >= target:
                min_length = min(min_length, right - left + 1)
                total = total - nums[left]
                left += 1
        if min_length <= len(nums):
            return min_length
        else:
            return 0


# @lc code=end


# class Solution:
#     def minSubArrayLen(self, target: int, nums: List[int]) -> int:
#         left = 0
#         total = 0
#         min_length = len(nums)+1

#         for right in range(len(nums)):
#             total = total+nums[right]

#             while total >= target:
#                 min_length = min(min_length, right-left+1)
#                 total = total-nums[left]
#                 left += 1

#         return min_length if min_length <= len(nums)else 0
