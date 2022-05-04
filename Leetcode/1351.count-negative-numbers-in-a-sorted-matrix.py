#
# @lc app=leetcode id=1351 lang=python3
#
# [1351] Count Negative Numbers in a Sorted Matrix
#
# https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
#
# algorithms
# Easy (75.18%)
# Likes:    2143
# Dislikes: 72
# Total Accepted:    171.6K
# Total Submissions: 228.2K
# Testcase Example:  '[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]'
#
# Given a m x n matrix grid which is sorted in non-increasing order both
# row-wise and column-wise, return the number of negative numbers in grid.
#
#
# Example 1:
#
#
# Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
# Output: 8
# Explanation: There are 8 negatives number in the matrix.
#
#
# Example 2:
#
#
# Input: grid = [[3,2],[1,0]]
# Output: 0
#
#
#
# Constraints:
#
#
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 100
# -100 <= grid[i][j] <= 100
#
#
#
# Follow up: Could you find an O(n + m) solution?
#

# @lc code=start
from typing import List


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0

        for row in grid:
            data = self.findFirstNegativeIndex(self, row)
            count += data
        return count

    def findFirstNegativeIndex(self, row: List[int]):
        l = 0
        r = len(row)-1
        res = 0
        found_negative = False
        while l <= r:
            middle = (l+r)//2

            if row[middle] < 0:
                res += r-middle+1
                r = middle-1
                found_negative = True
            else:
                l = middle+1
        return res

# @lc code=end
