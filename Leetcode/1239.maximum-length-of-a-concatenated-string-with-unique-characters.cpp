/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 *
 * https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * algorithms
 * Medium (50.54%)
 * Likes:    2922
 * Dislikes: 206
 * Total Accepted:    148.2K
 * Total Submissions: 285.8K
 * Testcase Example:  '["un","iq","ue"]'
 *
 * You are given an array of strings arr. A string s is formed by the
 * concatenation of a subsequence of arr that has unique characters.
 *
 * Return the maximum possible length of s.
 *
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = ["un","iq","ue"]
 * Output: 4
 * Explanation: All the valid concatenations are:
 * - ""
 * - "un"
 * - "iq"
 * - "ue"
 * - "uniq" ("un" + "iq")
 * - "ique" ("iq" + "ue")
 * Maximum length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = ["cha","r","act","ers"]
 * Output: 6
 * Explanation: Possible longest valid concatenations are "chaers" ("cha" +
 * "ers") and "acters" ("act" + "ers").
 *
 *
 * Example 3:
 *
 *
 * Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
 * Output: 26
 * Explanation: The only string in arr has all 26 characters.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 16
 * 1 <= arr[i].length <= 26
 * arr[i] contains only lowercase English letters.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
  int len{0};

public:
  int maxLength(vector<string> &arr)
  {
    checkLen("", arr, 0);
    return len;
  }

  void checkLen(string str, vector<string> &arr, int itr)
  {
    if (!isUnique(str))
      return;
    if (str.size() > len)
      len = str.size();
    for (int i = itr; i < arr.size(); i++)
      checkLen(str + arr[i], arr, i + 1);
  }

  bool isUnique(string word)
  {
    set<char> st;
    for (auto ele : word)
    {
      if (st.find(ele) != st.end())
        return false;
      st.insert(ele);
    }
    return true;
  }
};
// @lc code=end
