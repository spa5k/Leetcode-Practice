/*
 * @lc app=leetcode id=1344 lang=cpp
 *
 * [1344] Angle Between Hands of a Clock
 *
 * https://leetcode.com/problems/angle-between-hands-of-a-clock/description/
 *
 * algorithms
 * Medium (63.41%)
 * Likes:    1100
 * Dislikes: 221
 * Total Accepted:    101.4K
 * Total Submissions: 160K
 * Testcase Example:  '12\n30'
 *
 * Given two numbers, hour and minutes, return the smaller angle (in degrees)
 * formed between the hour and the minute hand.
 *
 * Answers within 10^-5 of the actual value will be accepted as correct.
 *
 *
 * Example 1:
 *
 *
 * Input: hour = 12, minutes = 30
 * Output: 165
 *
 *
 * Example 2:
 *
 *
 * Input: hour = 3, minutes = 30
 * Output: 75
 *
 *
 * Example 3:
 *
 *
 * Input: hour = 3, minutes = 15
 * Output: 7.5
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= hour <= 12
 * 0 <= minutes <= 59
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  double angleClock(int hour, int minutes)
  {
    double oneHour = 30;
    double oneMinute = 6;

    double angelForHour = (hour * oneHour) + (double)minutes / 2;
    double angelForMinute = minutes * oneMinute;
    double difference = abs(angelForHour - angelForMinute);
    return min(difference, 360 - difference);
  }
};
// @lc code=end
