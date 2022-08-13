#
# @lc app=leetcode id=220 lang=python3
#
# [220] Contains Duplicate III
#
# https://leetcode.com/problems/contains-duplicate-iii/description/
#
# algorithms
# Medium (21.59%)
# Likes:    2241
# Dislikes: 2194
# Total Accepted:    198.7K
# Total Submissions: 915.2K
# Testcase Example:  '[1,2,3,1]\n3\n0'
#
# Given an integer array nums and two integers k and t, return true if there
# are two distinct indices i and j in the array such that abs(nums[i] -
# nums[j]) <= t and abs(i - j) <= k.
#
#
# Example 1:
# Input: nums = [1,2,3,1], k = 3, t = 0
# Output: true
# Example 2:
# Input: nums = [1,0,1,1], k = 1, t = 2
# Output: true
# Example 3:
# Input: nums = [1,5,9,1,5,9], k = 2, t = 3
# Output: false
#
#
# Constraints:
#
#
# 1 <= nums.length <= 2 * 10^4
# -2^31 <= nums[i] <= 2^31 - 1
# 0 <= k <= 10^4
# 0 <= t <= 2^31 - 1
#
#
#

# @lc code=start
from sortedcontainers import SortedList


class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        SList = SortedList()
        for i in range(len(nums)):
            if i > k:
                SList.remove(nums[i - k - 1])
            pos1 = SortedList.bisect_left(SList, nums[i] - t)
            pos2 = SortedList.bisect_right(SList, nums[i] + t)

            if pos1 != pos2:
                return True

            SList.add(nums[i])

        return False


# @lc code=end
