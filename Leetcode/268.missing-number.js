/*
 * @lc app=leetcode id=268 lang=javascript
 *
 * [268] Missing Number
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
const missingNumber = (nums) => {
  let len = nums.length;
  let sum = (len * (len + 1)) / 2;
  let sum2 = nums.reduce((a, c) => a + c);
  return sum - sum2;
};
// const missingNumber = (nums) => {
//   let arr = new Array(nums.length + 1).fill(-1);

//   for (const num of nums) {
//     arr[num] = nums;
//   }

//   return arr.indexOf(-1);
// };
console.log(missingNumber([0, 1, 3]));
// @lc code=end
