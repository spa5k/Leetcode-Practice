/*
 * @lc app=leetcode id=989 lang=javascript
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
/**
 * @param {number[]} num
 * @param {number} k
 * @return {number[]}
 */
var addToArrayForm = function(A, K) {
  let flag = A.length - 1;
  while (K) {
    if (flag < 0) {
      A.unshift(K % 10);
    } else {
      K += A[flag];
      A[flag--] = K % 10;
    }
    K = Math.floor(K / 10);
  }
  return A;
};
// @lc code=end
