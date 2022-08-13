#
# @lc app=leetcode id=643 lang=python3
#
# [643] Maximum Average Subarray I
#
# https://leetcode.com/problems/maximum-average-subarray-i/description/
#
# algorithms
# Easy (43.08%)
# Likes:    1538
# Dislikes: 156
# Total Accepted:    138.3K
# Total Submissions: 318.3K
# Testcase Example:  '[1,12,-5,-6,50,3]\n4'
#
# You are given an integer array nums consisting of n elements, and an integer
# k.
#
# Find a contiguous subarray whose length is equal to k that has the maximum
# average value and return this value. Any answer with a calculation error less
# than 10^-5 will be accepted.
#
#
# Example 1:
#
#
# Input: nums = [1,12,-5,-6,50,3], k = 4
# Output: 12.75000
# Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
#
#
# Example 2:
#
#
# Input: nums = [5], k = 1
# Output: 5.00000
#
#
#
# Constraints:
#
#
# n == nums.length
# 1 <= k <= n <= 10^5
# -10^4 <= nums[i] <= 10^4
#
#
#

# @lc code=start
# class Solution:
from typing import List


def findMaxAverage(self, nums: List[int], k: int) -> float:
    sub = sum(nums[:k])
    res = sub

    for r in range(k, len(nums)):
        sub += (
            nums[r] - nums[r - k]
        )  # window element added from one and subtracted from the other end
        res = max(sub, res)
    return res / k


print(findMaxAverage("", [1, 12, -5, -6, 50, 3], 4))
# @lc code=end
