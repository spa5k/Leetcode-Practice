/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (63.12%)
 * Likes:    6359
 * Dislikes: 270
 * Total Accepted:    547.9K
 * Total Submissions: 866.3K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
  int n;
  void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &vis)
  {
    vis[i] = true;

    for (int j = 0; j < n; j++)
    {
      if (isConnected[i][j] == 1 && vis[j] == 0)
        dfs(j, isConnected, vis);
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    n = isConnected.size();

    int ans = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
      if (vis[i] == false)
      {
        dfs(i, isConnected, vis);
        ans++;
      }
    }

    return ans;
  }
};
// @lc code=end
