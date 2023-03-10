/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.82%)
 * Likes:    32491
 * Dislikes: 1416
 * Total Accepted:    4.3M
 * Total Submissions: 12.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_set<char> letters;

    int first = 0;
    int second = 0;

    int result = 0;

    while (second < s.size())
    {
      if (letters.find(s[second]) == letters.end())
      {
        letters.insert(s[second]);
        result = max(result, second - first + 1);
        second++;
      }
      else
      {
        letters.erase(s[first]);
        first++;
      }
    }

    return result;
  }
};
// @lc code=end
