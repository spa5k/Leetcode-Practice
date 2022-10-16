// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem797.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 *
 * https://leetcode.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (81.38%)
 * Likes:    5106
 * Dislikes: 121
 * Total Accepted:    344.1K
 * Total Submissions: 422.7K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1,
 * find all possible paths from node 0 to node n - 1 and return them in any
 * order.
 *
 * The graph is given as follows: graph[i] is a list of all nodes you can visit
 * from node i (i.e., there is a directed edge from node i to node
 * graph[i][j]).
 *
 *
 * Example 1:
 *
 *
 * Input: graph = [[1,2],[3],[3],[]]
 * Output: [[0,1,3],[0,2,3]]
 * Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 *
 *
 * Example 2:
 *
 *
 * Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
 * Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 *
 *
 *
 * Constraints:
 *
 *
 * n == graph.length
 * 2 <= n <= 15
 * 0 <= graph[i][j] < n
 * graph[i][j] != i (i.e., there will be no self-loops).
 * All the elements of graph[i] are unique.
 * The input graph is guaranteed to be a DAG.
 *
 *
 */
// #include <headers.h>
// @lc code=start
class Solution
{
public:
  int target;
  vector<vector<int>> res;
  vector<int> temp;
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    target = graph.size() - 1;
    dfs(graph);
    return res;
  }
  void dfs(vector<vector<int>> &graph, int currentNode = 0)
  {
    temp.push_back(currentNode);
    if (currentNode == target)
    {
      res.push_back(temp);
    }
    else
    {
      for (int node : graph[currentNode])
      {
        dfs(graph, node);
      }
    }
    temp.pop_back();
  }
};
// @lc code=end
