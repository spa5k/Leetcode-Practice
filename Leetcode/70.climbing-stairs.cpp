// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem70.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (51.72%)
 * Likes:    15088
 * Dislikes: 443
 * Total Accepted:    2M
 * Total Submissions: 3.8M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 45
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int climbStairs(int n)
  {
    int one = 1;
    int two = 1;
    for (int i = 0; i < n - 1; i++)
    {
      int temp = one;
      one = one + two;
      two = temp;
    }
    return one;
  }
};
// @lc code=end
