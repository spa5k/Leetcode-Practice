/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (59.32%)
 * Likes:    6569
 * Dislikes: 565
 * Total Accepted:    312.4K
 * Total Submissions: 525.3K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * You are given an array of variable pairs equations and an array of real
 * numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
 * equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
 * single variable.
 *
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the
 * j^th query where you must find the answer for Cj / Dj = ?.
 *
 * Return the answers to all queries. If a single answer cannot be determined,
 * return -1.0.
 *
 * Note: The input is always valid. You may assume that evaluating the queries
 * will not result in division by zero and that there is no contradiction.
 *
 *
 * Example 1:
 *
 *
 * Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * Explanation:
 * Given: a / b = 2.0, b / c = 3.0
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 *
 *
 * Example 2:
 *
 *
 * Input: equations = [["a","b"],["b","c"],["bc","cd"]], values =
 * [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * Output: [3.75000,0.40000,5.00000,0.20000]
 *
 *
 * Example 3:
 *
 *
 * Input: equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * Output: [0.50000,2.00000,-1.00000,-1.00000]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
  unordered_map<string, vector<pair<string, double>>> adjList;
  unordered_map<string, bool> visited;
  double queryAns;

public:
  bool dfs(string startNode, string endNode, double runningProduct)
  {

    if (startNode == endNode and adjList.find(startNode) != adjList.end())
    {
      queryAns = runningProduct;
      return true;
    }

    bool tempAns = false;
    visited[startNode] = true;

    for (int i = 0; i < adjList[startNode].size(); i++)
    {
      if (!visited[adjList[startNode][i].first])
      {
        tempAns = dfs(adjList[startNode][i].first, endNode, runningProduct * adjList[startNode][i].second);
        if (tempAns)
        {
          break;
        }
      }
    }

    visited[startNode] = false;

    return tempAns;
  }

  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
  {

    int n = equations.size(), m = queries.size();
    vector<double> ans(m);

    for (int i = 0; i < n; i++)
    {

      adjList[equations[i][0]].push_back({equations[i][1], values[i]});
      adjList[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
      visited[equations[i][0]] = false;
      visited[equations[i][1]] = false;
    }

    for (int i = 0; i < m; i++)
    {

      queryAns = 1;
      bool pathFound = dfs(queries[i][0], queries[i][1], 1);
      if (pathFound)
        ans[i] = queryAns;
      else
        ans[i] = -1;
    }

    return ans;
  }
};
// @lc code=end
