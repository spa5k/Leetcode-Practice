/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (35.55%)
 * Likes:    5838
 * Dislikes: 1351
 * Total Accepted:    470.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that
 * are 4-directionally surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Notice that an 'O' should not be flipped if:
 * - It is on the border, or
 * - It is adjacent to an 'O' that should not be flipped.
 * The bottom 'O' is on the border, so it is not flipped.
 * The other three 'O' form a surrounded region, so they are flipped.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["X"]]
 * Output: [["X"]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  void DFS(vector<vector<char>> &board, int i, int j)
  {
    int columns = board.size();
    int rows = board[0].size();

    if (i < 0 || j < 0 || i >= columns || j >= rows || board[i][j] != 'O')
      return;
    board[i][j] = '#';
    DFS(board, i - 1, j);
    DFS(board, i + 1, j);
    DFS(board, i, j - 1);
    DFS(board, i, j + 1);
  }

  void solve(vector<vector<char>> &board)
  {
    int columns = board.size();
    if (columns == 0)
    {
      return;
    }
    int rows = board[0].size();
    for (int i = 0; i < columns; i++)
    {
      if (board[i][0] == 'O')
      {
        DFS(board, i, 0);
      };
      if (board[i][rows - 1] == 'O')
      {
        DFS(board, i, rows - 1);
      }
    }

    for (int j = 0; j < rows; j++)
    {
      if (board[0][j] == 'O')
      {
        DFS(board, 0, j);
      }
      if (board[columns - 1][j] == 'O')
      {
        DFS(board, columns - 1, j);
      }
    }

    for (int i = 0; i < columns; i++)
      for (int j = 0; j < rows; j++)
      {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        if (board[i][j] == '#')
          board[i][j] = 'O';
      }
  }
};
// @lc code=end
