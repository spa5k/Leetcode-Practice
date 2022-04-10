/*
 * @lc app=leetcode id=88 lang=javascript
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
  for (let p = n + m - 1, p1 = m - 1, p2 = n - 1; p >= -1, p2 > -1; p--) {
    nums1[p] = p1 >= 0 && nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
  }
};

// @lc code=end
