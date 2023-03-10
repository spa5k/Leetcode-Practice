/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.39%)
 * Likes:    9442
 * Dislikes: 298
 * Total Accepted:    620.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    if (s2.size() < s1.size())
    {
      return false;
    }

    vector<int> hashS1(26, 0), hashS2(26, 0);
    for (int i = 0; i < s1.size(); i++)
    {
      hashS1[s1[i] - 'a'] += 1;
      hashS2[s2[i] - 'a'] += 1;
    }
    if (hashS1 == hashS2)
      return true;
    for (int i = s1.size(); i < s2.size(); i++)
    {
      hashS2[s2[i - s1.size()] - 'a']--;
      hashS2[s2[i] - 'a']++;
      if (hashS1 == hashS2)
        return true;
    }
    return false;
  }
};
// @lc code=end
