# @before-stub-for-debug-begin
from typing import *

from python3problem101 import *

# @before-stub-for-debug-end

#
# @lc app=leetcode id=101 lang=python3
#
# [101] Symmetric Tree
#
# https://leetcode.com/problems/symmetric-tree/description/
#
# algorithms
# Easy (51.93%)
# Likes:    10183
# Dislikes: 243
# Total Accepted:    1.3M
# Total Submissions: 2.5M
# Testcase Example:  '[1,2,2,3,4,4,3]'
#
# Given the root of a binary tree, check whether it is a mirror of itself
# (i.e., symmetric around its center).
#
#
# Example 1:
#
#
# Input: root = [1,2,2,3,4,4,3]
# Output: true
#
#
# Example 2:
#
#
# Input: root = [1,2,2,null,3,null,3]
# Output: false
#
#
#
# Constraints:
#
#
# The number of nodes in the tree is in the range [1, 1000].
# -100 <= Node.val <= 100
#
#
#
# Follow up: Could you solve it both recursively and iteratively?
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        def symmtery(right, left):
            if right is None and left is None:
                return True
            if left is None or right is None:
                return False
            if left.val != right.val:
                return False
            out = symmtery(left.left, right.right)
            inside = symmtery(left.right, right.left)
            return out and inside

        return symmtery(root.right, root.left)
# @lc code=end
