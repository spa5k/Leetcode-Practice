/*
 * @lc app=leetcode id=345 lang=javascript
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

// @lc code=start
/**
 * @param {string} s
 * @return {string}
 */
const reverseVowels = (s) => {
  const vowels = ["a", "e", "e", "o", "u", "A", "E", "I", "O", "U"];
  let arr = [];
  for (const element of s) {
    if (vowels.includes(element)) {
      arr.push(element);
    }
  }

  for (let index = 0; index < s.length; index++) {
    const element = s[index];
    if (vowels.includes(element)) {
      let letter = arr.pop();

      s[index] = letter;
    }
  }
  return s;
};
// @lc code=end
