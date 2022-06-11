#
# @lc app=leetcode id=349 lang=python3
#
# [349] Intersection of Two Arrays
#
# https://leetcode.com/problems/intersection-of-two-arrays/description/
#
# algorithms
# Easy (69.03%)
# Likes:    2876
# Dislikes: 1903
# Total Accepted:    664.5K
# Total Submissions: 960.8K
# Testcase Example:  '[1,2,2,1]\n[2,2]'
#
# Given two integer arrays nums1 and nums2, return an array of their
# intersection. Each element in the result must be unique and you may return
# the result in any order.
#
#
# Example 1:
#
#
# Input: nums1 = [1,2,2,1], nums2 = [2,2]
# Output: [2]
#
#
# Example 2:
#
#
# Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
# Output: [9,4]
# Explanation: [4,9] is also accepted.
#
#
#
# Constraints:
#
#
# 1 <= nums1.length, nums2.length <= 1000
# 0 <= nums1[i], nums2[i] <= 1000
#
#
#

# @lc code=start
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1

        res = []
        nums1 = sorted(nums1)
        nums2 = set(nums2)

        for i in nums2:
            l, r = 0, len(nums1)-1

            while l <= r:
                m = (l+r)//2
                if nums1[m] == i:
                    res.append(i)
                    break
                elif nums1[m] < i:
                    l = m+1
                else:
                    r = m-1
        return res

# @lc code=end
