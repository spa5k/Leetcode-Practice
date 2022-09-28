/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (53.64%)
 * Likes:    5634
 * Dislikes: 1060
 * Total Accepted:    300.7K
 * Total Submissions: 559.5K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * There is an m x n rectangular island that borders both the Pacific Ocean and
 * Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
 * and the Atlantic Ocean touches the island's right and bottom edges.
 *
 * The island is partitioned into a grid of square cells. You are given an m x
 * n integer matrix heights where heights[r][c] represents the height above sea
 * level of the cell at coordinate (r, c).
 *
 * The island receives a lot of rain, and the rain water can flow to
 * neighboring cells directly north, south, east, and west if the neighboring
 * cell's height is less than or equal to the current cell's height. Water can
 * flow from any cell adjacent to an ocean into the ocean.
 *
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 * denotes that rain water can flow from cell (ri, ci) to both the Pacific and
 * Atlantic oceans.
 *
 *
 * Example 1:
 *
 *
 * Input: heights =
 * [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * Explanation: The following cells can flow to the Pacific and Atlantic
 * oceans, as shown below:
 * [0,4]: [0,4] -> Pacific Ocean
 * [0,4] -> Atlantic Ocean
 * [1,3]: [1,3] -> [0,3] -> Pacific Ocean
 * [1,3] -> [1,4] -> Atlantic Ocean
 * [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
 * [1,4] -> Atlantic Ocean
 * [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
 * [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
 * [3,0]: [3,0] -> Pacific Ocean
 * [3,0] -> [4,0] -> Atlantic Ocean
 * [3,1]: [3,1] -> [3,0] -> Pacific Ocean
 * [3,1] -> [4,1] -> Atlantic Ocean
 * [4,0]: [4,0] -> Pacific Ocean
 * ⁠      [4,0] -> Atlantic Ocean
 * Note that there are other possible paths for these cells to flow to the
 * Pacific and Atlantic oceans.
 *
 *
 * Example 2:
 *
 *
 * Input: heights = [[1]]
 * Output: [[0,0]]
 * Explanation: The water can flow from the only cell to the Pacific and
 * Atlantic oceans.
 *
 *
 *
 * Constraints:
 *
 *
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 *
 *
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n));
    vector<vector<bool>> atlantic(m, vector<bool>(n));

    for (int i = 0; i < m; i++)
    {
      dfs(i, 0, heights, pacific);
      dfs(i, n - 1, heights, atlantic);
    }

    for (int j = 0; j < n; j++)
    {
      dfs(0, j, heights, pacific);
      dfs(m - 1, j, heights, atlantic);
    }

    vector<vector<int>> result;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (pacific[i][j] && atlantic[i][j])
        {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }
  void dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &visited)
  {
    visited[i][j] = true;
    int m = heights.size();
    int n = heights[0].size();

    if (i > 0 && !visited[i - 1][j] && heights[i - 1][j] >= heights[i][j])
    {
      dfs(i - 1, j, heights, visited);
    }
    if (i < m - 1 && !visited[i + 1][j] && heights[i + 1][j] >= heights[i][j])
    {
      dfs(i + 1, j, heights, visited);
    }
    if (j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j])
    {
      dfs(i, j - 1, heights, visited);
    }
    if (j < n - 1 && !visited[i][j + 1] && heights[i][j + 1] >= heights[i][j])
    {
      dfs(i, j + 1, heights, visited);
    }
  }
};
// @lc code=end
