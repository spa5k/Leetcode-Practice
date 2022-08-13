#
# @lc app=leetcode id=206 lang=python3
#
# [206] Reverse Linked List
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current_node = head

        prev_node = None

        while current_node:
            next = current_node.next
            current_node.next = prev_node
            prev_node = current_node
            current_node = next
        return prev_node
# @lc code=end
