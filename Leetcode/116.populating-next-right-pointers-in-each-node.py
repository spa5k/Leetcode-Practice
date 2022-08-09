#
# @lc app=leetcode id=116 lang=python3
#
# [116] Populating Next Right Pointers in Each Node
#
# https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
#
# algorithms
# Medium (57.78%)
# Likes:    7288
# Dislikes: 248
# Total Accepted:    809.3K
# Total Submissions: 1.4M
# Testcase Example:  '[1,2,3,4,5,6,7]'
#
# You are given a perfect binary tree where all leaves are on the same level,
# and every parent has two children. The binary tree has the following
# definition:
#
#
# struct Node {
# ⁠ int val;
# ⁠ Node *left;
# ⁠ Node *right;
# ⁠ Node *next;
# }
#
#
# Populate each next pointer to point to its next right node. If there is no
# next right node, the next pointer should be set to NULL.
#
# Initially, all next pointers are set to NULL.
#
#
# Example 1:
#
#
# Input: root = [1,2,3,4,5,6,7]
# Output: [1,#,2,3,#,4,5,6,7,#]
# Explanation: Given the above perfect binary tree (Figure A), your function
# should populate each next pointer to point to its next right node, just like
# in Figure B. The serialized output is in level order as connected by the next
# pointers, with '#' signifying the end of each level.
#
#
# Example 2:
#
#
# Input: root = []
# Output: []
#
#
#
# Constraints:
#
#
# The number of nodes in the tree is in the range [0, 2^12 - 1].
# -1000 <= Node.val <= 1000
#
#
#
# Follow-up:
#
#
# You may only use constant extra space.
# The recursive approach is fine. You may assume implicit stack space does not
# count as extra space for this problem.
#
#
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


import collections


class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        q = collections.deque()
        q.append(root)

        while q:
            for i in range(1, len(q)):
                q[i-1].next = q[i]
            q[-1].next = None
            new_level = collections.deque()
            for node in q:
                if node.left:
                    new_level.append(node.left)
                if node.right:
                    new_level.append(node.right)
            q = new_level
        return root
# @lc code=end
