#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        close_to_open = {"}": "{", ")": "(", "]": "["}
        stack = []
        for i in s:
            if i in close_to_open:
                # it means this is left hand side one
                # then check if the last letter in stack is
                # close_to_open[s]
                if stack and stack[-1] == close_to_open[i]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(i)
        if stack:
            return False
        return True


# @lc code=end
