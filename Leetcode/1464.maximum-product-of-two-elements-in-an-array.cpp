/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 *
 * https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/
 *
 * algorithms
 * Easy (79.04%)
 * Likes:    1197
 * Dislikes: 169
 * Total Accepted:    154.3K
 * Total Submissions: 195.1K
 * Testcase Example:  '[3,4,5,2]'
 *
 * Given the array of integers nums, you will choose two different indices i
 * and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 *
 * Example 1:
 *
 *
 * Input: nums = [3,4,5,2]
 * Output: 12
 * Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you
 * will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) =
 * 3*4 = 12.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,5,4,5]
 * Output: 16
 * Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get
 * the maximum value of (5-1)*(5-1) = 16.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,7]
 * Output: 12
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 500
 * 1 <= nums[i] <= 10^3
 *
 *
 */

// @lc code=start
class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    priority_queue<int> mh;
    for (auto curr : nums)
    {
      mh.push(curr);
    }
    int a = mh.top();
    mh.pop();
    int b = mh.top();
    return (a - 1) * (b - 1);
  }
};
// @lc code=end
