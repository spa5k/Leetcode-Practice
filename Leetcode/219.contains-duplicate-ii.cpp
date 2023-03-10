/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (40.89%)
 * Likes:    3840
 * Dislikes: 2298
 * Total Accepted:    577.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an integer array nums and an integer k, return true if there are two
 * distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
 * - j) <= k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 *
 *
 */
// class Solution
// {
// public:
//   bool containsNearbyDuplicate(vector<int> &nums, int k)
//   {
//     unordered_map<int, int> m;
//     for (int i = 0; i < nums.size(); i++)
//     {
//       if (m[nums[i]] != 0 && i - m[nums[i]] < k)
//       {
//         return true;
//       }
//       else
//       {
//         m[nums[i]] = i + 1;
//       }
//     }
//     return false;
//   }
// };
#include <headers.h>
// @lc code=start
class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    unordered_map<int, int> map;
    int i = 0, j = 0;
    for (; j < nums.size(); j++)
    {
      if (j > k)
      {
        map[nums[i++]]--;
      }
      if (map[nums[j]] > 0)
      {
        return true;
      }
      map[nums[j]]++;
    }
    return false;
  }
};
// @lc code=end
