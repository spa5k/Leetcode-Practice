# @before-stub-for-debug-begin
from python3problem112 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode id=112 lang=python3
#
# [112] Path Sum
#
# https://leetcode.com/problems/path-sum/description/
#
# algorithms
# Easy (45.88%)
# Likes:    6089
# Dislikes: 814
# Total Accepted:    940.5K
# Total Submissions: 2M
# Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
#
# Given the root of a binary tree and an integer targetSum, return true if the
# tree has a root-to-leaf path such that adding up all the values along the
# path equals targetSum.
#
# A leaf is a node with no children.
#
#
# Example 1:
#
#
# Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
# Output: true
# Explanation: The root-to-leaf path with the target sum is shown.
#
#
# Example 2:
#
#
# Input: root = [1,2,3], targetSum = 5
# Output: false
# Explanation: There two root-to-leaf paths in the tree:
# (1 --> 2): The sum is 3.
# (1 --> 3): The sum is 4.
# There is no root-to-leaf path with sum = 5.
#
#
# Example 3:
#
#
# Input: root = [], targetSum = 0
# Output: false
# Explanation: Since the tree is empty, there are no root-to-leaf paths.
#
#
#
# Constraints:
#
#
# The number of nodes in the tree is in the range [0, 5000].
# -1000 <= Node.val <= 1000
# -1000 <= targetSum <= 1000
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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        def check_sum(node, current_sum):
            if not node:
                return
            current = node.val+current_sum
            if not node.left and not node.right:
                # its a leaf node
                if current == targetSum:
                    return True
            else:
                if node.left:
                    left = check_sum(node.left, current)
                    if left:
                        return True
                if node.right:
                    right = check_sum(node.right, current)
                    if right:
                        return True
        res = check_sum(root, 0)
        if res:
            return True
        return False
# @lc code=end
