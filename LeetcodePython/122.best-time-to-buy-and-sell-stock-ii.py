#
# @lc app=leetcode id=122 lang=python3
#
# [122] Best Time to Buy and Sell Stock II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        last, result = prices[0], 0

        for p in prices:
            if p > last:
                result += p - last
            last = p

        return result
# @lc code=end
