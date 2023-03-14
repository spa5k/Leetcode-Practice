/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (46.13%)
 * Likes:    18268
 * Dislikes: 624
 * Total Accepted:    1.8M
 * Total Submissions: 3.9M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    int n = intervals.size();
    if (n == 1)
    {
      return intervals;
    }

    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
         { return a[0] < b[0]; });
    vector<vector<int>> res;
    int i = 0;
    while (i < n - 1)
    {
      if (intervals[i][1] >= intervals[i + 1][0])
      {
        intervals[i + 1][0] = intervals[i][0];
        intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
      }
      else
      {
        res.push_back(intervals[i]);
      }
      i++;
    }
    res.push_back(intervals[i]);
    return res;
  }
};
// @lc code=end
