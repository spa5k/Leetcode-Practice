/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (47.72%)
 * Likes:    2750
 * Dislikes: 2233
 * Total Accepted:    439K
 * Total Submissions: 892.2K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * lower and upper cases, more than once.
 *
 *
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  static bool isVowel(char ch)
  {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
  };
  string reverseVowels(string s)
  {
    string vowels;
    vowels.reserve(size(s));
    vector<int> idx;
    idx.reserve(size(s));

    for (int i = 0; i < size(s); ++i)
    {
      if (isVowel(s[i]))
      {
        vowels.push_back(s[i]);
        idx.push_back(i);
      }
    }
    reverse(begin(vowels), end(vowels));
    for (int i = 0; i < size(idx); ++i)
      s[idx[i]] = vowels[i];
    return s;
  }
};
// @lc code=end
