/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 *
 * https://leetcode.com/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (65.91%)
 * Likes:    6527
 * Dislikes: 237
 * Total Accepted:    874.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * Given an array of points where points[i] = [xi, yi] represents a point on
 * the X-Y plane and an integer k, return the k closest points to the origin
 * (0, 0).
 *
 * The distance between two points on the X-Y plane is the Euclidean distance
 * (i.e., √(x1 - x2)^2 + (y1 - y2)^2).
 *
 * You may return the answer in any order. The answer is guaranteed to be
 * unique (except for the order that it is in).
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[1,3],[-2,2]], k = 1
 * Output: [[-2,2]]
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest k = 1 points from the origin, so the answer is just
 * [[-2,2]].
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[3,3],[5,-1],[-2,4]], k = 2
 * Output: [[3,3],[-2,4]]
 * Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= points.length <= 10^4
 * -10^4 < xi, yi < 10^4
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    priority_queue<vector<int>> pq{};
    vector<vector<int>> res(k);
    for (auto &&point : points)
    {
      int x = point[0];
      int y = point[1];
      int dist = calculate(x, y);
      pq.push({dist, x, y});
      if (pq.size() > k)
      {
        pq.pop();
      }
    }
    for (int i = 0; i < k; ++i)
    {
      vector<int> top = pq.top();
      pq.pop();
      res[i] = {top[1], top[2]};
    }
    return res;
  }
  int calculate(int x, int y)
  {
    return x * x + y * y;
  }
};
// @lc code=end
