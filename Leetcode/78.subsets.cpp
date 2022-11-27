/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (73.87%)
 * Likes:    12816
 * Dislikes: 182
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> output{};
    output.push_back(vector<int>{});

    for (auto &num : nums)
    {
      vector<vector<int>> newSubsets{};
      for (vector<int> curr : output)
      {
        vector<int> subset{curr};
        subset.push_back(num);
        newSubsets.push_back(subset);
      }
      for (vector<int> &curr : newSubsets)
      {
        output.push_back(curr);
      }
    }
    return output;
  }
};
// @lc code=end
