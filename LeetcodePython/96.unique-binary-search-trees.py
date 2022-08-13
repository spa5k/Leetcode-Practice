#
# @lc app=leetcode id=96 lang=python3
#
# [96] Unique Binary Search Trees
#
# https://leetcode.com/problems/unique-binary-search-trees/description/
#
# algorithms
# Medium (58.57%)
# Likes:    7612
# Dislikes: 306
# Total Accepted:    501.8K
# Total Submissions: 854.4K
# Testcase Example:  '3'
#
# Given an integer n, return the number of structurally unique BST's (binary
# search trees) which has exactly n nodes of unique values from 1 to n.
#
#
# Example 1:
#
#
# Input: n = 3
# Output: 5
#
#
# Example 2:
#
#
# Input: n = 1
# Output: 1
#
#
#
# Constraints:
#
#
# 1 <= n <= 19
#
#
#

# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        numTree = [1] * (n+1)

        # 0 node = 1 tree
        # 1 node = 1 tree
        for nodes in range(2, n+1):
            total = 0
            for root in range(1, nodes+1):
                left = root - 1
                right = nodes - root
                total += numTree[left] * numTree[right]
            numTree[nodes] = total
        return numTree[n]

# @lc code=end
