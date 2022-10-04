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
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < prerequisites.size(); i++)
    {
      m[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    unordered_set<int> vistited;
    for (int i = 0; i < numCourses; i++)
    {
      if (!dfs(i, m, vistited))
      {
        return false;
      }
    }
    return true;
  }
  bool dfs(int course, unordered_map<int, vector<int>> &m, unordered_set<int> &visited)
  {
    if (visited.find(course) != visited.end())
    {
      return false;
    }
    if (m[course].empty())
    {
      return true;
    }
    visited.insert(course);
    for (int i = 0; i < m[course].size(); i++)
    {
      int nextCourse = m[course][i];
      if (!dfs(nextCourse, m, visited))
      {
        return false;
      };
    }
    m[course].clear();
    visited.erase(course);
    return true;
  }
};
// @lc code=end
