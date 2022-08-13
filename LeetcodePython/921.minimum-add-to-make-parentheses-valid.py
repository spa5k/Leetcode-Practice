#
# @lc app=leetcode id=921 lang=python3
#
# [921] Minimum Add to Make Parentheses Valid
#
# https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
#
# algorithms
# Medium (77.16%)
# Likes:    2460
# Dislikes: 141
# Total Accepted:    202.3K
# Total Submissions: 262.1K
# Testcase Example:  '"())"'
#
# A parentheses string is valid if and only if:
#
#
# It is the empty string,
# It can be written as AB (A concatenated with B), where A and B are valid
# strings, or
# It can be written as (A), where A is a valid string.
#
#
# You are given a parentheses string s. In one move, you can insert a
# parenthesis at any position of the string.
#
#
# For example, if s = "()))", you can insert an opening parenthesis to be
# "(()))" or a closing parenthesis to be "())))".
#
#
# Return the minimum number of moves required to make s valid.
#
#
# Example 1:
#
#
# Input: s = "())"
# Output: 1
#
#
# Example 2:
#
#
# Input: s = "((("
# Output: 3
#
#
#
# Constraints:
#
#
# 1 <= s.length <= 1000
# s[i] is either '(' or ')'.
#
#
#
# "()))(("
# @lc code=start


class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        balance = 0
        right_pending = 0
        for i in s:
            if i == "(":
                balance += 1
                right_pending += 1

            if i == ")" and right_pending > 0:
                balance -= 1
                right_pending -= 1
            elif i == ")":
                balance += 1

        return balance


# @lc code=end
