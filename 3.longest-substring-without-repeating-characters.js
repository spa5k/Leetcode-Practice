/*
 * @lc app=leetcode id=3 lang=javascript
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
const lengthOfLongestSubstring = (s) => {
  let temp = [];
  let maxLength = 0;

  for (let i = 0; i < s.length; i++) {
    if (temp.indexOf(s[i]) === -1) {
      temp.push(s[i]);
      maxLength = Math.max(temp.length, maxLength);
    } else {
      temp = temp.slice(temp.indexOf(s[i]) + 1, temp.length);
      temp.push(s[i]);
    }
  }
  return maxLength;
};
// @lc code=end
