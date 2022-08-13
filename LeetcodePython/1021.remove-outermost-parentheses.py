#
# @lc app=leetcode id=1021 lang=python3
#
# [1021] Remove Outermost Parentheses
#
# https://leetcode.com/problems/remove-outermost-parentheses/description/
#
# algorithms
# Easy (79.82%)
# Likes:    1242
# Dislikes: 1163
# Total Accepted:    169.4K
# Total Submissions: 212.2K
# Testcase Example:  '"(()())(())"'
#
# A valid parentheses string is either empty "", "(" + A + ")", or A + B, where
# A and B are valid parentheses strings, and + represents string
# concatenation.
#
#
# For example, "", "()", "(())()", and "(()(()))" are all valid parentheses
# strings.
#
#
# A valid parentheses string s is primitive if it is nonempty, and there does
# not exist a way to split it into s = A + B, with A and B nonempty valid
# parentheses strings.
#
# Given a valid parentheses string s, consider its primitive decomposition: s =
# P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
#
# Return s after removing the outermost parentheses of every primitive string
# in the primitive decomposition of s.
#
#
# Example 1:
#
#
# Input: s = "(()())(())"
# Output: "()()()"
# Explanation:
# The input string is "(()())(())", with primitive decomposition "(()())" +
# "(())".
# After removing outer parentheses of each part, this is "()()" + "()" =
# "()()()".
#
#
# Example 2:
#
#
# Input: s = "(()())(())(()(()))"
# Output: "()()()()(())"
# Explanation:
# The input string is "(()())(())(()(()))", with primitive decomposition
# "(()())" + "(())" + "(()(()))".
# After removing outer parentheses of each part, this is "()()" + "()" +
# "()(())" = "()()()()(())".
#
#
# Example 3:
#
#
# Input: s = "()()"
# Output: ""
# Explanation:
# The input string is "()()", with primitive decomposition "()" + "()".
# After removing outer parentheses of each part, this is "" + "" = "".
#
#
#
# Constraints:
#
#
# 1 <= s.length <= 10^5
# s[i] is either '(' or ')'.
# s is a valid parentheses string.
#
#
#

# @lc code=start
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        open_count = 0
        res = []

        for i in s:
            if i == ")":
                open_count -= 1
            if open_count > 0:
                res.append(i)
            if i == "(":
                open_count += 1
        return "".join(res)


# @lc code=end
