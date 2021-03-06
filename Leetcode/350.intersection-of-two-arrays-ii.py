#
# @lc app=leetcode id=350 lang=python3
#
# [350] Intersection of Two Arrays II
#
# https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
#
# algorithms
# Easy (54.90%)
# Likes:    4450
# Dislikes: 704
# Total Accepted:    798.3K
# Total Submissions: 1.5M
# Testcase Example:  '[1,2,2,1]\n[2,2]'
#
# Given two integer arrays nums1 and nums2, return an array of their
# intersection. Each element in the result must appear as many times as it
# shows in both arrays and you may return the result in any order.
#
#
# Example 1:
#
#
# Input: nums1 = [1,2,2,1], nums2 = [2,2]
# Output: [2,2]
#
#
# Example 2:
#
#
# Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
# Output: [4,9]
# Explanation: [9,4] is also accepted.
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
# Follow up:
#
#
# What if the given array is already sorted? How would you optimize your
# algorithm?
# What if nums1's size is small compared to nums2's size? Which algorithm is
# better?
# What if elements of nums2 are stored on disk, and the memory is limited such
# that you cannot load all elements into the memory at once?
#
#
#

# @lc code=start
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        for val in nums1:
            res, pos = self.search(val, nums2)
            if res == True:
                del nums2[pos]
                result.append(val)
        return result

    def search(self, val, a):
        a.sort()
        l = 0
        h = len(a)-1
        while l <= h:
            mid = (l + h) // 2
            if a[mid] == val:
                return True, mid
            elif a[mid] < val:
                l = mid + 1
            else:
                h = mid - 1
        return False, -1
# @lc code=end
