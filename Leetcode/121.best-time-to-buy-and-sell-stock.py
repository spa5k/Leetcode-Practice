#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        left = 0  # buy
        right = 1  # sell

        while right < len(prices):
            # profitable?
            if prices[left] < prices[right]:
                profit = prices[right]-prices[left]
                max_profit = max(max_profit, profit)
            else:
                left = right
            right += 1
        return max_profit
# @lc code=end
