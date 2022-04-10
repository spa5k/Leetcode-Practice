/*
 * @lc app=leetcode id=643 lang=javascript
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function (nums, k) {
  let highestNum = -Infinity;
  let sum = 0;
  for (let i = 0; i <= nums.length; i++) {
    sum += nums[i];
    if (i === k - i) {
      max = sum;
    } else {
      sum -= nums[i - k];
      max = Math.max(sum, highestNum);
    }
  }
  return highestNum / k;
};
// @lc code=end
