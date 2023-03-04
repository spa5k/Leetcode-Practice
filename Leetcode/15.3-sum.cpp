/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (32.50%)
 * Likes:    24393
 * Dislikes: 2205
 * Total Accepted:    2.5M
 * Total Submissions: 7.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> res;
    if (nums.size() < 3)
    {
      return res;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
      if (nums[i] > 0)
      {
        break;
      }
      if (i > 0 && nums[i - 1] == nums[i])
      {
        continue;
      }

      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right)
      {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0)
        {
          left++;
        }
        else if (sum > 0)
        {
          right--;
        }
        else
        {
          res.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1])
          {
            left++;
          }
          while (left < right && nums[right] == nums[right - 1])
          {
            right--;
          }
          left++;
          right--;
        }
      }
    }
    return res;
  }
};
// @lc code=end
