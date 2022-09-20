/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (65.52%)
 * Likes:    11881
 * Dislikes: 602
 * Total Accepted:    1.6M
 * Total Submissions: 2.4M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 *
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 *
 * You must solve it in O(n) time complexity.
 *
 *
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (count < k)
      {
        pq.push(nums[i]);
        count++;
      }
      else
      {
        if (nums[i] > pq.top())
        {
          pq.pop();
          pq.push(nums[i]);
        }
      }
    }
    return pq.top();
  }
};
// @lc code=end
