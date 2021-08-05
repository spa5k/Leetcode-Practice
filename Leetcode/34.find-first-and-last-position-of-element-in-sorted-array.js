/*
 * @lc app=leetcode id=34 lang=javascript
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const searchRange = (nums, target) => {
  if (nums.length === 1 && nums[0] === target) {
    return [0, 0];
  }
  const info = [];
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    if (info.length === 0 && num === target) {
      info[0] = info[1] = i;
      continue;
    }

    if (num === target) {
      info[1] = i;
    }
  }

  if (info.length === 0) {
    return [-1, -1];
  }
  return info;
};
// @lc code=end

console.log(searchRange([1], 0));
