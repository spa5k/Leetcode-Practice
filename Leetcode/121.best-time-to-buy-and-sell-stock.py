#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        if not prices:
            return 0

        highest_profit = 0

        current_lowest = prices[0]
        for item in prices:
            highest_profit = max(highest_profit, item - current_lowest)
            current_lowest = min(current_lowest, item)

        return highest_profit
# @lc code=end
