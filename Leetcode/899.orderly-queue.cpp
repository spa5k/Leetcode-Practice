/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 *
 * https://leetcode.com/problems/orderly-queue/description/
 *
 * algorithms
 * Hard (58.96%)
 * Likes:    1047
 * Dislikes: 490
 * Total Accepted:    42.4K
 * Total Submissions: 66.5K
 * Testcase Example:  '"cba"\n1'
 *
 * You are given a string s and an integer k. You can choose one of the first k
 * letters of s and append it at the end of the string..
 *
 * Return the lexicographically smallest string you could have after applying
 * the mentioned step any number of moves.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cba", k = 1
 * Output: "acb"
 * Explanation:
 * In the first move, we move the 1^st character 'c' to the end, obtaining the
 * string "bac".
 * In the second move, we move the 1^st character 'b' to the end, obtaining the
 * final result "acb".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "baaca", k = 3
 * Output: "aaabc"
 * Explanation:
 * In the first move, we move the 1^st character 'b' to the end, obtaining the
 * string "aacab".
 * In the second move, we move the 3^rd character 'c' to the end, obtaining the
 * final result "aaabc".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= s.length <= 1000
 * s consist of lowercase English letters.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  string orderlyQueue(string s, int k)
  {
    if (k > 1)
    {
      sort(s.begin(), s.end());
      return s;
    }
    else
    {
      string temp = s;
      s += s;
      for (int i = 1; i < temp.length(); i++)
      {
        temp = min(temp, s.substr(i, temp.size()));
      }
      return temp;
    }
  }
};
// @lc code=end
