#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#
# https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#
# algorithms
# Medium (37.00%)
# Likes:    10706
# Dislikes: 781
# Total Accepted:    1.2M
# Total Submissions: 3.2M
# Testcase Example:  '[4,5,6,7,0,1,2]\n0'
#
# There is an integer array nums sorted in ascending order (with distinct
# values).
#
# Prior to being passed to your function, nums is possibly rotated at an
# unknown pivot index k (1 <= k < nums.length) such that the resulting array is
# [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
# (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
# and become [4,5,6,7,0,1,2].
#
# Given the array nums after the possible rotation and an integer target,
# return the index of target if it is in nums, or -1 if it is not in nums.
#
# You must write an algorithm with O(log n) runtime complexity.
#
#
# Example 1:
# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4
# Example 2:
# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1
# Example 3:
# Input: nums = [1], target = 0
# Output: -1
#
#
# Constraints:
#
#
# 1 <= nums.length <= 5000
# -10^4 <= nums[i] <= 10^4
# All values of nums are unique.
# nums is an ascending array that is possibly rotated.
# -10^4 <= target <= 10^4
#
#
#

# @lc code=start
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1

        while l <= r:
            mid = (l+r)//2
            if nums[mid] == target:
                return mid

            # left sorted area
            if nums[mid] >= nums[l]:
                # if target is greater than middle
                # or is target is less than left most portion
                # it means we need to search on right
                if target > nums[mid] or target < nums[l]:
                    l = mid+1
                else:
                    r = mid-1
            else:
                if target < nums[mid] or target > nums[r]:
                    r = mid-1
                else:
                    l = mid+1
        return -1

# @lc code=end
