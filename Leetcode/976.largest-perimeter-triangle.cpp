/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 *
 * https://leetcode.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (52.51%)
 * Likes:    2205
 * Dislikes: 299
 * Total Accepted:    158.3K
 * Total Submissions: 289.8K
 * Testcase Example:  '[2,1,2]'
 *
 * Given an integer array nums, return the largest perimeter of a triangle with
 * a non-zero area, formed from three of these lengths. If it is impossible to
 * form any triangle of a non-zero area, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,1,2]
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^6
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int largestPerimeter(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    for (int edges = nums.size() - 1; edges > 1; --edges)
    {
      int first = nums[edges];
      int second = nums[edges - 1];
      int third = nums[edges - 2];
      if (first < second + third)
        return first + second + third;
    }
    return 0;
  }
};
// @lc code=end
