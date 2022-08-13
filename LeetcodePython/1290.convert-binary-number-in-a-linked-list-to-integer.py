#
# @lc app=leetcode id=1290 lang=python3
#
# [1290] Convert Binary Number in a Linked List to Integer
#
# https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
#
# algorithms
# Easy (82.66%)
# Likes:    2616
# Dislikes: 129
# Total Accepted:    296.2K
# Total Submissions: 358.4K
# Testcase Example:  '[1,0,1]'
#
# Given head which is a reference node to a singly-linked list. The value of
# each node in the linked list is either 0 or 1. The linked list holds the
# binary representation of a number.
#
# Return the decimal value of the number in the linked list.
#
#
# Example 1:
#
#
# Input: head = [1,0,1]
# Output: 5
# Explanation: (101) in base 2 = (5) in base 10
#
#
# Example 2:
#
#
# Input: head = [0]
# Output: 0
#
#
#
# Constraints:
#
#
# The Linked List is not empty.
# Number of nodes will not exceed 30.
# Each node's value is either 0 or 1.
#
#
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        current = head
        res = ''

        while current:
            res += str(current.val)
            current = current.next

        return int(res, 2)
# @lc code=end
