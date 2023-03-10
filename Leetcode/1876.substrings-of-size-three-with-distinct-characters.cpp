/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 *
 * https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/
 *
 * algorithms
 * Easy (70.99%)
 * Likes:    1053
 * Dislikes: 28
 * Total Accepted:    72.4K
 * Total Submissions: 101.9K
 * Testcase Example:  '"xyzzaz"'
 *
 * A string is good if there are no repeated characters.
 *
 * Given a string s​​​​​, return the number of good substrings of length three
 * in s​​​​​​.
 *
 * Note that if there are multiple occurrences of the same substring, every
 * occurrence should be counted.
 *
 * A substring is a contiguous sequence of characters in a string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "xyzzaz"
 * Output: 1
 * Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and
 * "zaz".
 * The only good substring of length 3 is "xyz".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aababcabc"
 * Output: 4
 * Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc",
 * "bca", "cab", and "abc".
 * The good substrings are "abc", "bca", "cab", and "abc".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s​​​​​​ consists of lowercase English letters.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int countGoodSubstrings(string s)
  {
    int res = 0;

    unordered_map<char, int> map{};
    for (int i = 0; i < s.size(); i++)
    {
      if (i > 2 and --map[s[i - 3]] == 0)
      {
        map.erase(s[i - 3]);
      }
      map[s[i]]++;
      if (map.size() == 3)
        res++;
    }
    return res;
  }
};
// @lc code=end
