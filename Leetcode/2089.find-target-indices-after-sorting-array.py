#
# @lc app=leetcode id=2089 lang=python3
#
# [2089] Find Target Indices After Sorting Array
#
# https://leetcode.com/problems/find-target-indices-after-sorting-array/description/
#
# algorithms
# Easy (78.75%)
# Likes:    597
# Dislikes: 31
# Total Accepted:    52.8K
# Total Submissions: 67.1K
# Testcase Example:  '[1,2,5,2,3]\n2'
#
# You are given a 0-indexed integer array nums and a target element target.
#
# A target index is an index i such that nums[i] == target.
#
# Return a list of the target indices of nums after sorting nums in
# non-decreasing order. If there are no target indices, return an empty list.
# The returned list must be sorted in increasing order.
#
#
# Example 1:
#
#
# Input: nums = [1,2,5,2,3], target = 2
# Output: [1,2]
# Explanation: After sorting, nums is [1,2,2,3,5].
# The indices where nums[i] == 2 are 1 and 2.
#
#
# Example 2:
#
#
# Input: nums = [1,2,5,2,3], target = 3
# Output: [3]
# Explanation: After sorting, nums is [1,2,2,3,5].
# The index where nums[i] == 3 is 3.
#
#
# Example 3:
#
#
# Input: nums = [1,2,5,2,3], target = 5
# Output: [4]
# Explanation: After sorting, nums is [1,2,2,3,5].
# The index where nums[i] == 5 is 4.
#
#
#
# Constraints:
#
#
# 1 <= nums.length <= 100
# 1 <= nums[i], target <= 100
#
#
#

# @lc code=start
from typing import List


class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        # sort the array
        nums.sort()

        left = 0
        right = len(nums)-1
        res = []
        while left <= right:
            mid = (left+right) // 2
            if nums[mid] >= target:
                right = mid - 1
            else:
                left = mid + 1
        for i in range(left, len(nums)):
            if nums[i] == target:
                res.append(i)
            else:
                break

        return res


print(Solution.targetIndices(Solution, [1, 2, 5, 2, 3], 5))

# @lc code=end
