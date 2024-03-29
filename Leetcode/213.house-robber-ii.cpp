/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (40.69%)
 * Likes:    7161
 * Dislikes: 105
 * Total Accepted:    505.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it
 * will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2), because they are adjacent houses.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.size() == 1)
    {
      return nums[0];
    }
    int r1 = helper(nums, 0, nums.size() - 2);
    int r2 = helper(nums, 1, nums.size() - 1);
    return max(r1, r2);
  }
  int helper(vector<int> &nums, int start, int end)
  {
    int rob1 = 0;
    int rob2 = 0;
    for (int i = start; i <= end; i++)
    {
      int curr = nums[i];
      int temp = max(rob1 + curr, rob2);
      rob1 = rob2;
      rob2 = temp;
    }

    return rob2;
  }
};
// @lc code=end
