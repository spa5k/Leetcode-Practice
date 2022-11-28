/*
 * @lc app=leetcode id=223 lang=javascript
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (40.85%)
 * Likes:    1463
 * Dislikes: 1428
 * Total Accepted:    175.7K
 * Total Submissions: 402.2K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Given the coordinates of two rectilinear rectangles in a 2D plane, return
 * the total area covered by the two rectangles.
 *
 * The first rectangle is defined by its bottom-left corner (ax1, ay1) and its
 * top-right corner (ax2, ay2).
 *
 * The second rectangle is defined by its bottom-left corner (bx1, by1) and its
 * top-right corner (bx2, by2).
 *
 *
 * Example 1:
 *
 *
 * Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2
 * = 2
 * Output: 45
 *
 *
 * Example 2:
 *
 *
 * Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2,
 * by2 = 2
 * Output: 16
 *
 *
 *
 * Constraints:
 *
 *
 * -10^4 <= ax1 <= ax2 <= 10^4
 * -10^4 <= ay1 <= ay2 <= 10^4
 * -10^4 <= bx1 <= bx2 <= 10^4
 * -10^4 <= by1 <= by2 <= 10^4
 *
 *
 */

// @lc code=start
/**
 * @param {number} ax1
 * @param {number} ay1
 * @param {number} ax2
 * @param {number} ay2
 * @param {number} bx1
 * @param {number} by1
 * @param {number} bx2
 * @param {number} by2
 * @return {number}
 */
const computeArea = (ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) => {
  const area1 = (ax2 - ax1) * (ay2 - ay1);
  const area2 = (bx2 - bx1) * (by2 - by1);

  const overlapx = Math.max(Math.min(ax2, bx2) - Math.max(ax1, bx1), 0);
  const overlapy = Math.max(Math.min(ay2, by2) - Math.max(ay1, by1), 0);
  return area1 + area2 - overlapx * overlapy;
};
// @lc code=end
