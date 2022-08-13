#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#
# https://leetcode.com/problems/valid-palindrome/description/
#
# algorithms
# Easy (40.47%)
# Likes:    3429
# Dislikes: 5064
# Total Accepted:    1.2M
# Total Submissions: 2.9M
# Testcase Example:  '"A man, a plan, a canal: Panama"'
#
# A phrase is a palindrome if, after converting all uppercase letters into
# lowercase letters and removing all non-alphanumeric characters, it reads the
# same forward and backward. Alphanumeric characters include letters and
# numbers.
#
# Given a string s, return true if it is a palindrome, or false otherwise.
#
#
# Example 1:
#
#
# Input: s = "A man, a plan, a canal: Panama"
# Output: true
# Explanation: "amanaplanacanalpanama" is a palindrome.
#
#
# Example 2:
#
#
# Input: s = "race a car"
# Output: false
# Explanation: "raceacar" is not a palindrome.
#
#
# Example 3:
#
#
# Input: s = " "
# Output: true
# Explanation: s is an empty string "" after removing non-alphanumeric
# characters.
# Since an empty string reads the same forward and backward, it is a
# palindrome.
#
#
#
# Constraints:
#
#
# 1 <= s.length <= 2 * 10^5
# s consists only of printable ASCII characters.
#
#
#

# @lc code=start
# class Solution:
def isPalindrome(self, s: str) -> bool:
    left = 0
    right = len(s) - 1

    while left < right:

        left_letter = s[left].lower()
        right_letter = s[right].lower()

        if left_letter == " " or not s[left].isalnum():
            left += 1
            continue
        elif right_letter == " " or not s[right].isalnum():
            right -= 1
            continue

        if left_letter == right_letter:
            left += 1
            right -= 1
            continue
        else:
            return False
    return True


print(isPalindrome("", "0P"))


# @lc code=end
