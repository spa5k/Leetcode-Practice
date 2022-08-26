/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (53.41%)
 * Likes:    6745
 * Dislikes: 435
 * Total Accepted:    514.4K
 * Total Submissions: 962.2K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 *
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 *
 *
 * Example 1:
 *
 *
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 *
 *
 * Example 2:
 *
 *
 * Input: triangle = [[-10]]
 * Output: -10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 *
 *
 *
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */
#include <vector>;
using namespace std;

// @lc code=start
// class Solution
// {
// public:
//   int minimumTotal(vector<vector<int>> &triangle)
//   {
//     int n = triangle.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     for (int j = 0; j < n; j++)
//     {
//       dp[n - 1][j] = triangle[n - 1][j];
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//       for (int j = 0; j < i + 1; j++)
//       {
//         int lower_left = triangle[i][j] + dp[i + 1][j];
//         int lower_right = triangle[i][j] + dp[i + 1][j + 1];
//         dp[i][j] = min(lower_left, lower_right);
//       }
//     }
//     return dp[0][0];
//   }
// };
class Solution
{
public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
    int n = triangle.size();
    vector<int> next_row(triangle[n - 1]);
    vector<int> curr_row(n, 0);
    for (int i = n - 2; i >= 0; i--)
    {
      for (int j = 0; j < i + 1; j++)
      {
        int lower_left = triangle[i][j] + next_row[j];
        int lower_right = triangle[i][j] + next_row[j + 1];
        curr_row[j] = min(lower_left, lower_right);
      }
      swap(curr_row, next_row);
    }
    return next_row[0];
  }
};
// @lc code=end
