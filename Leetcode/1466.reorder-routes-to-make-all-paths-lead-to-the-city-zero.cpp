/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 *
 * https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
 *
 * algorithms
 * Medium (61.72%)
 * Likes:    1887
 * Dislikes: 51
 * Total Accepted:    66.5K
 * Total Submissions: 107.7K
 * Testcase Example:  '6\n[[0,1],[1,3],[2,3],[4,0],[4,5]]'
 *
 * There are n cities numbered from 0 to n - 1 and n - 1 roads such that there
 * is only one way to travel between two different cities (this network form a
 * tree). Last year, The ministry of transport decided to orient the roads in
 * one direction because they are too narrow.
 *
 * Roads are represented by connections where connections[i] = [ai, bi]
 * represents a road from city ai to city bi.
 *
 * This year, there will be a big event in the capital (city 0), and many
 * people want to travel to this city.
 *
 * Your task consists of reorienting some roads such that each city can visit
 * the city 0. Return the minimum number of edges changed.
 *
 * It's guaranteed that each city can reach city 0 after reorder.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
 * Output: 3
 * Explanation: Change the direction of edges show in red such that each node
 * can reach the node 0 (capital).
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
 * Output: 2
 * Explanation: Change the direction of edges show in red such that each node
 * can reach the node 0 (capital).
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3, connections = [[1,0],[2,0]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 5 * 10^4
 * connections.length == n - 1
 * connections[i].length == 2
 * 0 <= ai, bi <= n - 1
 * ai != bi
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int minReorder(int n, vector<vector<int>> &connections)
  {
    vector<int> visited(n);
    vector<vector<int>> adj(n), back(n);
    queue<int> q;
    q.push(0);
    int ans = 0;

    for (auto c : connections)
    {
      adj[c[0]].push_back(c[1]);
      back[c[1]].push_back(c[0]);
    }

    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      visited[curr] = 1;

      // change dir for all arrows facing out
      for (auto a : adj[curr])
      {
        if (!visited[a])
        {
          ans++;
          q.push(a);
        }
      }
      // push other nodes so we visit everything
      for (auto b : back[curr])
      {
        if (!visited[b])
          q.push(b);
      }
    }
    return ans;
  }
};
// @lc code=end
