// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem200.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (55.90%)
 * Likes:    17109
 * Dislikes: 393
 * Total Accepted:    1.9M
 * Total Submissions: 3.4M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */
#include <headers.h>
// @lc code=start
// class Solution
// {
// public:
//   int DR[4] = {1, 0, -1, 0};
//   int DC[4] = {0, -1, 0, 1};

//   bool valid_index(int i, int j, vector<vector<char>> &grid)
//   {
//     if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
//       return false;
//     return true;
//   }
//   int numIslands(vector<vector<char>> &grid)
//   {
//     if (grid.size() == 0)
//     {
//       return 0;
//     }
//     int n = grid.size();
//     int m = grid[0].size();
//     int no_of_islands = 0;
//     for (int i = 0; i < n; i++)
//     {
//       for (int j = 0; j < m; j++)
//       {
//         if (grid[i][j] == '1')
//         {
//           no_of_islands++;
//           bfs(i, j, grid);
//         }
//       }
//     }
//     return no_of_islands;
//   }
//   void bfs(int r, int c, vector<vector<char>> &grid)
//   {
//     grid[r][c] = '0';
//     queue<pair<int, int>> q;
//     q.push({r, c});
//     while (!q.empty())
//     {
//       int i = q.front().first;
//       int j = q.front().second;
//       q.pop();
//       for (int k = 0; k < 4; k++)
//       {
//         int ci = DR[k] + i;
//         int cj = DC[k] + j;
//         if (!valid_index(ci, cj, grid))
//         {
//           continue;
//         }
//         if (grid[ci][cj] == '1')
//         {
//           q.push({ci, cj});
//           grid[ci][cj] = '0';
//         }
//       }
//     }
//   }
// };

class Solution
{
public:
  void dfs(int i, int j, vector<vector<char>> &grid)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
      return;
    grid[i][j] = '0';
    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
  }

  int numIslands(vector<vector<char>> &grid)
  {

    int islands = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == '1')
        {
          islands++;
          dfs(i, j, grid);
        }
      }
    }
    return islands;
  }
};
// @lc code=end
