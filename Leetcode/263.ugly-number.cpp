/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (41.64%)
 * Likes:    2380
 * Dislikes: 1390
 * Total Accepted:    378.2K
 * Total Submissions: 892.4K
 * Testcase Example:  '6'
 *
 * An ugly number is a positive integer whose prime factors are limited to 2,
 * 3, and 5.
 *
 * Given an integer n, return true if n is an ugly number.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 6
 * Output: true
 * Explanation: 6 = 2 × 3
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: true
 * Explanation: 1 has no prime factors, therefore all of its prime factors are
 * limited to 2, 3, and 5.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 14
 * Output: false
 * Explanation: 14 is not ugly since it includes the prime factor 7.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
  bool isUgly(int n)
  {
    if (n <= 0)
      return false;
    while (n > 1)
    {
      if (n % 2 == 0)
        n = n / 2;
      else if (n % 3 == 0)
        n = n / 3;
      else if (n % 5 == 0)
        n = n / 5;
      else
        break;
    }
    return (n == 1);
  }
};
// @lc code=end
