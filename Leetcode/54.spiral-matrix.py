#
# @lc app=leetcode id=54 lang=python3
#
# [54] Spiral Matrix
#
# https://leetcode.com/problems/spiral-matrix/description/
#
# algorithms
# Medium (39.28%)
# Likes:    5394
# Dislikes: 739
# Total Accepted:    607.4K
# Total Submissions: 1.5M
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# Given an m x n matrix, return all elements of the matrix in spiral order.
#
#
# Example 1:
#
#
# Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
# Output: [1,2,3,6,9,8,7,4,5]
#
#
# Example 2:
#
#
# Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
# Output: [1,2,3,4,8,12,11,10,9,5,6,7]
#
#
#
# Constraints:
#
#
# m == matrix.length
# n == matrix[i].length
# 1 <= m, n <= 10
# -100 <= matrix[i][j] <= 100
#
#
#

# @lc code=start
class Solution:
    def spiralOrder(self, array: List[List[int]]) -> List[int]:
        res = []

        startRow, endRow = 0, len(array)-1
        startCol, endCol = 0, len(array[0])-1

        while startRow <= endRow and startCol <= endCol:
            for col in range(startCol, endCol+1):
                res.append(array[startRow][col])

            for row in range(startRow+1, endRow+1):
                res.append(array[row][endCol])

            for col in reversed(range(startCol, endCol)):
                if startRow == endRow:
                    break
                res.append(array[endRow][col])

            for row in reversed(range(startRow+1, endRow)):
                if startCol == endCol:
                    break

                res.append(array[row][startCol])

            startCol += 1
            startRow += 1
            endRow -= 1
            endCol -= 1
        return res


# @lc code=end
