#
# @lc app=leetcode id=680 lang=python3
#
# [680] Valid Palindrome II
#
# https://leetcode.com/problems/valid-palindrome-ii/description/
#
# algorithms
# Easy (38.24%)
# Likes:    5017
# Dislikes: 279
# Total Accepted:    454.2K
# Total Submissions: 1.2M
# Testcase Example:  '"aba"'
#
# Given a string s, return true if the s can be palindrome after deleting at
# most one character from it.
#
#
# Example 1:
#
#
# Input: s = "aba"
# Output: true
#
#
# Example 2:
#
#
# Input: s = "abca"
# Output: true
# Explanation: You could delete the character 'c'.
#
#
# Example 3:
#
#
# Input: s = "abc"
# Output: false
#
#
#
# Constraints:
#
#
# 1 <= s.length <= 10^5
# s consists of lowercase English letters.
#
#
#

# @lc code=start
class Solution:
    def validPalindrome(self, s: str) -> bool:
        if s == s[::-1]:
            return True

        l, r = 0, len(s) - 1
        while l <= r:
            if s[l] != s[r]:
                temp2 = s[:r] + s[r + 1 :]
                temp = s[:l] + s[l + 1 :]

                return temp == temp[::-1] or temp2 == temp2[::-1]

            l += 1
            r -= 1
        return False


# @lc code=end
