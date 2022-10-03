/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (45.30%)
 * Likes:    11481
 * Dislikes: 441
 * Total Accepted:    1M
 * Total Submissions: 2.3M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 *
 * Return true if you can finish all courses. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 *
 *
 */

#include <headers.h>
// @lc code=start
class Solution
{
public:
  int WHITE = 0; // Unvisited
  int GREY = 1;  // Explore incomplete
  int BLACK = 2; // Fully explored

  // return true if no cycle otherwise return false
  bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited)
  {
    visited[node] = GREY;

    // go thourgh all parent nodes i.e., prerequisites courses
    for (int j = 0; j < graph[node].size(); j++)
    {
      // If end up in an unexplored node then it is a cycle and return false
      if (visited[graph[node][j]] == GREY)
        return false;

      // Explore all unvisited parent node
      if (visited[graph[node][j]] == WHITE)
        if (!dfs(graph[node][j], graph, visited))
          return false; // return false if find cycle
    }

    visited[node] = BLACK;

    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {

    // create graph for each course to prerequisites Adjacency List
    vector<vector<int>> graph(numCourses);

    // Visited track of each node
    vector<int> visited(numCourses, WHITE);

    // Populate graph
    for (int i = 0; i < prerequisites.size(); i++)
      graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

    // Run DFS on each unvisited node
    for (int i = 0; i < numCourses; i++)
    {
      if (visited[i] == WHITE)
        if (!dfs(i, graph, visited))
          return false; // return false if detect cycle
    }

    return true;
  }
};
// @lc code=end
