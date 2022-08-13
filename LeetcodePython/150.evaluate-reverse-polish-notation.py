#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#
# https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#
# algorithms
# Medium (41.18%)
# Likes:    2876
# Dislikes: 614
# Total Accepted:    395.2K
# Total Submissions: 934.2K
# Testcase Example:  '["2","1","+","3","*"]'
#
# Evaluate the value of an arithmetic expression in Reverse Polish Notation.
#
# Valid operators are +, -, *, and /. Each operand may be an integer or another
# expression.
#
# Note that division between two integers should truncate toward zero.
#
# It is guaranteed that the given RPN expression is always valid. That means
# the expression would always evaluate to a result, and there will not be any
# division by zero operation.
#
#
# Example 1:
#
#
# Input: tokens = ["2","1","+","3","*"]
# Output: 9
# Explanation: ((2 + 1) * 3) = 9
#
#
# Example 2:
#
#
# Input: tokens = ["4","13","5","/","+"]
# Output: 6
# Explanation: (4 + (13 / 5)) = 6
#
#
# Example 3:
#
#
# Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
# Output: 22
# Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
# = ((10 * (6 / (12 * -11))) + 17) + 5
# = ((10 * (6 / -132)) + 17) + 5
# = ((10 * 0) + 17) + 5
# = (0 + 17) + 5
# = 17 + 5
# = 22
#
#
#
# Constraints:
#
#
# 1 <= tokens.length <= 10^4
# tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
# range [-200, 200].
#
#
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operations = ["+", "-", "*", "/"]

        for i in tokens:
            if i in operations:
                stack = self.handleLastTwo(stack, i)

            else:
                stack.append(int(i))

        return stack[0]

    def handleLastTwo(self,stack, operation):
        if len(stack) == 1:
            return stack
        second = stack.pop()
        first = stack.pop()

        if operation == "+":
            res = first + second
            stack.append(res)
        elif operation == "-":
            res = first - second
            stack.append(res)
        elif operation == "*":
            res = first * second
            stack.append(res)
        else:
            res = first / second
            stack.append(int(res))
        return stack
# @lc code=end
