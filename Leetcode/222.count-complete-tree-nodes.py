#
# @lc app=leetcode id=222 lang=python3
#
# [222] Count Complete Tree Nodes
#
# https://leetcode.com/problems/count-complete-tree-nodes/description/
#
# algorithms
# Medium (55.86%)
# Likes:    5440
# Dislikes: 323
# Total Accepted:    434.2K
# Total Submissions: 766.7K
# Testcase Example:  '[1,2,3,4,5,6]'
#
# Given the root of a complete binary tree, return the number of the nodes in
# the tree.
#
# According to Wikipedia, every level, except possibly the last, is completely
# filled in a complete binary tree, and all nodes in the last level are as far
# left as possible. It can have between 1 and 2^h nodes inclusive at the last
# level h.
#
# Design an algorithm that runs in less than O(n) time complexity.
#
#
# Example 1:
#
#
# Input: root = [1,2,3,4,5,6]
# Output: 6
#
#
# Example 2:
#
#
# Input: root = []
# Output: 0
#
#
# Example 3:
#
#
# Input: root = [1]
# Output: 1
#
#
#
# Constraints:
#
#
# The number of nodes in the tree is in the range [0, 5 * 10^4].
# 0 <= Node.val <= 5 * 10^4
# The tree is guaranteed to be complete.
#
#
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def countNodes(self, root: Optional[TreeNode]) -> int:
        def get_tree_height(node):
            if not node:
                # base case
                return 0

            else:
                # general case
                return 1 + get_tree_height(node.left)

        def counting(node):
            h = get_tree_height(node)
            if h == 0:
                return 0
            if (h-1) == get_tree_height(node.right):
                return 2**(h-1) + counting(node.right)
            else:
                return 2**(h-2) + counting(node.left)
        return counting(root)
# @lc code=end
