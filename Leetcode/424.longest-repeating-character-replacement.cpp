/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (51.79%)
 * Likes:    7540
 * Dislikes: 310
 * Total Accepted:    418.8K
 * Total Submissions: 808.4K
 * Testcase Example:  '"ABAB"\n2'
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    vector<int> count(26);
    int maxCount = 0;

    int first = 0;
    int second = 0;

    int res = 0;

    while (second < s.size())
    {
      count[s[second] - 'A']++;
      maxCount = max(maxCount, count[s[second] - 'A']);
      if (second - first + 1 - maxCount > k)
      {
        count[s[first] - 'A']--;
        first++;
      }
      res = max(res, second - first + 1);
      second++;
    }

    return res;
  }
};
// @lc code=end
