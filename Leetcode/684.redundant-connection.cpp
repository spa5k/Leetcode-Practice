/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 *
 * https://leetcode.com/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (61.88%)
 * Likes:    4569
 * Dislikes: 323
 * Total Accepted:    241.3K
 * Total Submissions: 389.3K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a tree is an undirected graph that is connected and has no
 * cycles.
 *
 * You are given a graph that started as a tree with n nodes labeled from 1 to
 * n, with one additional edge added. The added edge has two different vertices
 * chosen from 1 to n, and was not an edge that already existed. The graph is
 * represented as an array edges of length n where edges[i] = [ai, bi]
 * indicates that there is an edge between nodes ai and bi in the graph.
 *
 * Return an edge that can be removed so that the resulting graph is a tree of
 * n nodes. If there are multiple answers, return the answer that occurs last
 * in the input.
 *
 *
 * Example 1:
 *
 *
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * Output: [1,4]
 *
 *
 *
 * Constraints:
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * There are no repeated edges.
 * The given graph is connected.
 *
 *
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();

    vector<int> parents;
    vector<int> ranks;
    for (int i = 0; i < n + 1; i++)
    {
      parents.push_back(i);
      ranks.push_back(1);
    }

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
      int n1 = edges[i][0];
      int n2 = edges[i][1];
      if (!doUnion(parents, ranks, n1, n2))
      {
        result = {n1, n2};
        break;
      }
    }
    return result;
  }

private:
  int doFind(vector<int> &parents, int n)
  {
    int p = parents[n];
    while (p != parents[p])
    {
      parents[p] = parents[parents[p]];
      p = parents[p];
    }
    return p;
  }

  bool doUnion(vector<int> &parents, vector<int> &ranks, int n1, int n2)
  {
    int p1 = doFind(parents, n1);
    int p2 = doFind(parents, n2);
    if (p1 == p2)
    {
      return false;
    }

    if (ranks[p1] > ranks[p2])
    {
      parents[p2] = p1;
      ranks[p1] += ranks[p2];
    }
    else
    {
      parents[p1] = p2;
      ranks[p2] += ranks[p1];
    }

    return true;
  }
};

// @lc code=end
