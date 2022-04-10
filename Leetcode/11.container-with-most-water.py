#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1

        max_area = min(height[left], height[right]) * (right - left)

        while left < right:
            current_area = min(height[left], height[right]) * (right - left)
            max_area = max(current_area, max_area)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area


# @lc code=end
