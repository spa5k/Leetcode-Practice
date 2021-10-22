/*
 * @lc app=leetcode id=70 lang=javascript
 *
 * [70] Climbing Stairs
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
const climbStairs = (n) => {
  let onlyOneSteps = n;
  let onlyTwoSteps = Math.floor(n / 2);

  return onlyOneSteps + onlyTwoSteps;
};
// @lc code=end
