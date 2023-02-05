/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (49.08%)
 * Likes:    10423
 * Dislikes: 302
 * Total Accepted:    707.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6\item\li_v6v28sbyw938ntnihd is "bac", which is an anagram of "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> sHash(26, 0);
    vector<int> pHash(26, 0);
    vector<int> res;

    if (p.size() > s.size())
      return res;

    int left = 0, right = 0;
    while (right < p.size())
    {
      pHash[p[right] - 'a']++;
      sHash[s[right] - 'a']++;
      right++;
    }
    right--;
    while (right < s.size())
    {
      if (pHash == sHash)
        res.push_back(left);
      right++;
      if (right != s.size())
      {
        sHash[s[right] - 'a']++;
        sHash[s[left] - 'a']--;
      }
      left++;
    }
    return res;
  }
};
// @lc code=end
