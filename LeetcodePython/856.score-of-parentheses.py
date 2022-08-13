#
# @lc app=leetcode id=856 lang=python3
#
# [856] Score of Parentheses
#
# https://leetcode.com/problems/score-of-parentheses/description/
#
# algorithms
# Medium (65.43%)
# Likes:    4328
# Dislikes: 140
# Total Accepted:    135.7K
# Total Submissions: 207.4K
# Testcase Example:  '"()"'
#
# Given a balanced parentheses string s, return the score of the string.
#
# The score of a balanced parentheses string is based on the following
# rule:
#
#
# "()" has score 1.
# AB has score A + B, where A and B are balanced parentheses strings.
# (A) has score 2 * A, where A is a balanced parentheses string.
#
#
#
# Example 1:
#
#
# Input: s = "()"
# Output: 1
#
#
# Example 2:
#
#
# Input: s = "(())"
# Output: 2
#
#
# Example 3:
#
#
# Input: s = "()()"
# Output: 2
#
#
#
# Constraints:
#
#
# 2 <= s.length <= 50
# s consists of only '(' and ')'.
# s is a balanced parentheses string.
#
#
#

# @lc code=start


class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack=[]

        current=0
        previous=0

        for char in s:
          if char=="(":
            stack.append(current)
            previous,current=0,0
          else:
            top=stack.pop()
            if previous:
                current+=top+previous
            else:
                current+=top+1
          previous=current
        return current


# @lc code=end
