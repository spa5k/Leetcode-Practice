/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (41.16%)
 * Likes:    4791
 * Dislikes: 364
 * Total Accepted:    348.4K
 * Total Submissions: 831.9K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing a valid expression, implement a basic
 * calculator to evaluate it, and return the result of the evaluation.
 *
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 *
 *
 * Example 1:
 *
 *
 * Input: s = "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: s = " 2-1 + 2 "
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is
 * invalid).
 * '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is
 * valid).
 * There will be no two consecutive operators in the input.
 * Every number and running calculation will fit in a signed 32-bit integer.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  int calculate(string s)
  {
    stack<int> nums;
    int answer = 0;
    long long current_val = 0, sign = 1;

    for (char c : s)
    {
      if (isdigit(c))
      {
        current_val = 10 * current_val + c - '0';
      }
      else if (c == '+')
      {
        answer += current_val * sign;
        current_val = 0;
        sign = 1;
      }
      else if (c == '-')
      {
        answer += current_val * sign;
        current_val = 0;
        sign = -1;
      }
      else if (c == '(')
      {
        nums.push(answer);
        nums.push(sign);
        answer = 0;
        sign = 1;
      }
      else if (c == ')')
      {
        answer += current_val * sign;
        current_val = 0;

        answer = answer * nums.top();
        nums.pop();
        answer = answer + nums.top();
        nums.pop();
      }
    }
    answer += current_val * sign;
    return answer;
  }
};
// @lc code=end
