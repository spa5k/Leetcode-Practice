#
# @lc app=leetcode id=234 lang=python3
#
# [234] Palindrome Linked List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


# class Solution:
#     def isPalindrome(self, head: Optional[ListNode]) -> bool:
#         nums = []

#         while head:
#             nums.append(head.val)
#             head = head.next

#         l, r = 0, len(nums)-1

#         while l <= r:
#             if nums[l] != nums[r]:
#                 return False

#             l += 1
#             r -= 1

#         return True
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast, slow = head, head

        # finding the middle.
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # reverse the second half of the list'
        prev = None
        while slow:
            tmp = slow.next
            slow.next = prev
            prev = slow
            slow = tmp

        # check palindrome
        left, right = head, prev

        while right:
            if left.val != right.val:
                return False

            left = left.next
            right = right.next

        return True
        # @lc code=end
