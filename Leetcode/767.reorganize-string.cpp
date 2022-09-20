/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (52.68%)
 * Likes:    5372
 * Dislikes: 190
 * Total Accepted:    237.8K
 * Total Submissions: 451.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, rearrange the characters of s so that any two adjacent
 * characters are not the same.
 *
 * Return any possible rearrangement of s or return "" if not possible.
 *
 *
 * Example 1:
 * Input: s = "aab"
 * Output: "aba"
 * Example 2:
 * Input: s = "aaab"
 * Output: ""
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 *
 *
 */

#include <headers.h>
// @lc code=start
class Solution
{
public:
  string reorganizeString(string s)
  {
    string res = "";
    unordered_map<char, int> map;
    priority_queue<pair<int, char>> pq{};
    for (auto i : s)
    {
      map[i] += 1;
    }
    for (auto m : map)
    {
      pq.push(make_pair(m.second, m.first));
    }

    while (pq.size() > 1)
    {
      auto top1 = pq.top();
      pq.pop();
      auto top2 = pq.top();
      pq.pop();
      res += top1.second;
      res += top2.second;

      top1.first -= 1;
      top2.first -= 1;

      if (top1.first)
      {
        pq.push(top1);
      }
      if (top2.first)
      {
        pq.push(top2);
      }
    }
    if (!pq.empty())
    {
      if (pq.top().first > 1)
      {
        return "";
      }
      else
      {
        res += pq.top().second;
      }
    }
    return res;
  }
};
// @lc code=end
