#include "leetcode-definition.h"
/*
 * node
 * @lc app=leetcode id=2231 lang=cpp
 *
 * [2231] Largest Number After Digit Swaps by Parity
 *
 * https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/
 *
 * algorithms
 * Easy (60.07%)
 * Likes:    300
 * Dislikes: 210
 * Total Accepted:    25.1K
 * Total Submissions: 41.8K
 * Testcase Example:  '1234'
 *
 * You are given a positive integer num. You may swap any two digits of num
 * that have the same parity (i.e. both odd digits or both even digits).
 *
 * Return the largest possible value of num after any number of swaps.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 1234
 * Output: 3412
 * Explanation: Swap the digit 3 with the digit 1, this results in the number
 * 3214.
 * Swap the digit 2 with the digit 4, this results in the number 3412.
 * Note that there may be other sequences of swaps but it can be shown that
 * 3412 is the largest possible number.
 * Also note that we may not swap the digit 4 with the digit 1 since they are
 * of different parities.
 *
 *
 * Example 2:
 *
 *
 * Input: num = 65875
 * Output: 87655
 * Explanation: Swap the digit 8 with the digit 6, this results in the number
 * 85675.
 * Swap the first digit 5 with the digit 7, this results in the number 87655.
 * Note that there may be other sequences of swaps but it can be shown that
 * 87655 is the largest possible number.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 10^9
 *
 *
 */
#include <queue>
#include <vector>
using namespace std;
#include <string>

// @lc code=start
class Solution
{
public:
  int largestInteger(int num)
  {
    string s = to_string(num);
    int n = s.size();

    priority_queue<int> even{};
    priority_queue<int> odd{};
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      int temp = s[i] - '0';
      if (temp % 2)
      {
        odd.push(temp);
      }
      else
      {
        even.push(temp);
      }
    }

    for (int i = 0; i < n; i++)
    {
      result = result * 10;
      if ((s[i] - '0') % 2)
      {
        result += odd.top();
        odd.pop();
      }
      else
      {
        result += even.top();
        even.pop();
      }
    }
    return result;
  }
};
// @lc code=end
