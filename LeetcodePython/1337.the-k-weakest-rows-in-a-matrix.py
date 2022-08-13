#
# @lc app=leetcode id=1337 lang=python3
#
# [1337] The K Weakest Rows in a Matrix
#
# https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
#
# algorithms
# Easy (74.34%)
# Likes:    2362
# Dislikes: 131
# Total Accepted:    160.1K
# Total Submissions: 215.5K
# Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
#
# You are given an m x n binary matrix mat of 1's (representing soldiers) and
# 0's (representing civilians). The soldiers are positioned in front of the
# civilians. That is, all the 1's will appear to the left of all the 0's in
# each row.
#
# A row i is weaker than a row j if one of the following is true:
#
#
# The number of soldiers in row i is less than the number of soldiers in row
# j.
# Both rows have the same number of soldiers and i < j.
#
#
# Return the indices of the k weakest rows in the matrix ordered from weakest
# to strongest.
#
#
# Example 1:
#
#
# Input: mat =
# [[1,1,0,0,0],
# ⁠[1,1,1,1,0],
# ⁠[1,0,0,0,0],
# ⁠[1,1,0,0,0],
# ⁠[1,1,1,1,1]],
# k = 3
# Output: [2,0,3]
# Explanation:
# The number of soldiers in each row is:
# - Row 0: 2
# - Row 1: 4
# - Row 2: 1
# - Row 3: 2
# - Row 4: 5
# The rows ordered from weakest to strongest are [2,0,3,1,4].
#
#
# Example 2:
#
#
# Input: mat =
# [[1,0,0,0],
# ⁠[1,1,1,1],
# ⁠[1,0,0,0],
# ⁠[1,0,0,0]],
# k = 2
# Output: [0,2]
# Explanation:
# The number of soldiers in each row is:
# - Row 0: 1
# - Row 1: 4
# - Row 2: 1
# - Row 3: 1
# The rows ordered from weakest to strongest are [0,2,3,1].
#
#
#
# Constraints:
#
#
# m == mat.length
# n == mat[i].length
# 2 <= n, m <= 100
# 1 <= k <= m
# matrix[i][j] is either 0 or 1.
#
#
#

# @lc code=start
import heapq
from typing import List


class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        heap = []

        for i, row in enumerate(mat):
            r = self.bs(self, row)
            heapq.heappush(heap, (-r, -i, i))
        while len(heap) > k:
            heapq.heappop(heap)
        res = [0]*k
        for i in range(k-1, -1, -1):
            res[i] = heapq.heappop(heap)[2]
        return res

    def bs(self, row):
        left, right = 0, len(row)
        while left < right:
            mid = left + (right-left)//2
            if row[mid] == 1:
                left = mid + 1
            else:
                right = mid
        return left


print(Solution.kWeakestRows(Solution, [[1, 1, 0, 0, 0], [
      1, 1, 1, 1, 0], [1, 0, 0, 0, 0], [1, 1, 0, 0, 0], [1, 1, 1, 1, 1]], 3))
# @lc code=end
