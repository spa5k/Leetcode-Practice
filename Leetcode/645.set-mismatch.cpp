/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (41.36%)
 * Likes:    2838
 * Dislikes: 686
 * Total Accepted:    217.9K
 * Total Submissions: 514K
 * Testcase Example:  '[1,2,2,4]'
 *
 * You have a set of integers s, which originally contains all the numbers from
 * 1 to n. Unfortunately, due to some error, one of the numbers in s got
 * duplicated to another number in the set, which results in repetition of one
 * number and loss of another number.
 *
 * You are given an integer array nums representing the data status of this set
 * after the error.
 *
 * Find the number that occurs twice and the number that is missing and return
 * them in the form of an array.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [1,2]
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  vector<int> findErrorNums(vector<int> &nums)
  {
    // support variables
    int len = nums.size(), tot = 0;
    bool seen[len + 1];
    vector<int> res(2);
    // preparing seen
    for (int i = 1; i <= len; i++)
      seen[i] = false;
    // parsing nums and finding the first part of res and to compute tot
    for (int i : nums)
    {
      tot += i;
      seen[i] = (!seen[i] || bool(1 + (res[0] = i)));
    }
    // computing the second part of res
    res[1] = len * (len + 1) / 2 - tot + res[0];
    return res;
  }
};
// @lc code=end
