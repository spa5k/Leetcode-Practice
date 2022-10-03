/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (52.33%)
 * Likes:    8476
 * Dislikes: 311
 * Total Accepted:    492.8K
 * Total Submissions: 940.8K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 *
 *
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 *
 *
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    int time = 0;
    int fresh = 0;
    queue<pair<int, int>> q;
    vector<int> dir = {-1, 0, 1, 0, -1};

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          fresh++;
        }
        else if (grid[i][j] == 2)
        {
          q.push({i, j});
        }
      }
    }

    while (!q.empty() && fresh > 0)
    {
      for (int i = 0; i < q.size(); i++)
      {
        auto p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
          int r = p.first + dir[i];
          int c = p.second + dir[i + 1];
          if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
          {
            grid[r][c] = 2;
            q.push({r, c});
            fresh--;
          }
        }
      }
      time += 1;
    }
    if (fresh > 0)
      return -1;
    return time;
  }
};
// @lc code=end
