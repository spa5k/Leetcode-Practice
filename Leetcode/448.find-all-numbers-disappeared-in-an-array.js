/*
 * @lc app=leetcode id=448 lang=javascript
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[]}
 */
// Time - O(n) | Space - O(n)

// const findDisappearedNumbers = (nums) => {
//   const arr = new Array(nums.length + 1).fill(-1);

//   for (const element of nums) {
//     arr[element] = element;
//   }

//   let indexes = [];
//   for (let index = 1; index < arr.length; index++) {
//     if (arr[index] === -1) {
//       indexes.push(index);
//     }
//   }

//   return indexes;
// };
const findDisappearedNumbers = (nums) => {
  nums.forEach((n) => {
    const indexBasedOnThisValue = Math.abs(n) - 1;

    if (nums[indexBasedOnThisValue] > 0) {
      nums[indexBasedOnThisValue] = nums[indexBasedOnThisValue] * -1;
    }
  });

  const res = [];
  for (let index = 0; index < nums.length; index++) {
    const element = nums[index];
    if (element > 0) {
      res.push(index + 1);
    }
  }
  return res;
};
// @lc code=end
