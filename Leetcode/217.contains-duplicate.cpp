/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (61.43%)
 * Likes:    8414
 * Dislikes: 1109
 * Total Accepted:    2.5M
 * Total Submissions: 4.1M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_map<int, int> mp{};
    for (auto &&num : nums)
    {
      if (mp[num])
      {
        return true;
      }
      mp[num]++;
    }
    return false;
  }
};
// @lc code=end
