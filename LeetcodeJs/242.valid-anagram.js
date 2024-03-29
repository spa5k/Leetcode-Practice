/*
 * @lc app=leetcode id=242 lang=javascript
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

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  const map = new Map();
  for (let index = 0; index < s.length; index++) {
    const element = s[index];
    const count = (map.get(element) || 0) + 1;
    map.set(element, count);
  }

  for (let index = 0; index < s.length; index++) {
    const element = t[index];
    const count = map.get(element) - 1;
    map.set(element, count);
  }
  for (const [char, count] of map) {
    if (count !== 0) {
      return false;
    }
  }
  return true;
};
// @lc code=end

