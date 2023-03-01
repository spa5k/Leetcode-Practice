/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (48.61%)
 * Likes:    15103
 * Dislikes: 627
 * Total Accepted:    1M
 * Total Submissions: 2.2M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> s{nums.begin(), nums.end()};
    int longest = 0;
    for (auto &&num : nums)
    {
      if (!s.count(num - 1))
      {
        int length = 1;
        while (s.count(num + length))
        {
          ++length;
        }
        longest = max(length, longest);
      }
    }
    return longest;
  }
};
// @lc code=end
