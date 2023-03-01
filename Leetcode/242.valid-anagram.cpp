/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (62.99%)
 * Likes:    8350
 * Dislikes: 272
 * Total Accepted:    2M
 * Total Submissions: 3.2M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */
#include <headers.h>
class SolutionA
{
public:
  bool isAnagram(string s, string t)
  {
    unordered_map<char, int> mp{};
    if (s.size() != t.size())
    {
      return false;
    }
    for (auto &&key : s)
    {
      mp[key]++;
    }
    for (auto &&key : t)
    {
      mp[key]--;
      if (mp[key] < 0)
        return false;
    }
    return true;
  }
};
// @lc code=start
class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s == t)
      return true;
    if (s.size() != t.size())
      return false;
    int mp[26] = {};
    for (int i = 0; i < s.size(); i++)
    {
      mp[s[i] - 'a']++;
      mp[t[i] - 'a']--;
    }
    for (auto &&i : mp)
    {
      if (i)
        return false;
    }

    return true;
  }
};
// @lc code=end
