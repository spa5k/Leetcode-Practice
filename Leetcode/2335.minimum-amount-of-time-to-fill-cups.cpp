/*
 * @lc app=leetcode id=2335 lang=cpp
 *
 * [2335] Minimum Amount of Time to Fill Cups
 *
 * https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/
 *
 * algorithms
 * Easy (55.07%)
 * Likes:    321
 * Dislikes: 50
 * Total Accepted:    26.5K
 * Total Submissions: 48.1K
 * Testcase Example:  '[1,4,2]'
 *
 * You have a water dispenser that can dispense cold, warm, and hot water.
 * Every second, you can either fill up 2 cups with different types of water,
 * or 1 cup of any type of water.
 *
 * You are given a 0-indexed integer array amount of length 3 where amount[0],
 * amount[1], and amount[2] denote the number of cold, warm, and hot water cups
 * you need to fill respectively. Return the minimum number of seconds needed
 * to fill up all the cups.
 *
 *
 * Example 1:
 *
 *
 * Input: amount = [1,4,2]
 * Output: 4
 * Explanation: One way to fill up the cups is:
 * Second 1: Fill up a cold cup and a warm cup.
 * Second 2: Fill up a warm cup and a hot cup.
 * Second 3: Fill up a warm cup and a hot cup.
 * Second 4: Fill up a warm cup.
 * It can be proven that 4 is the minimum number of seconds needed.
 *
 *
 * Example 2:
 *
 *
 * Input: amount = [5,4,4]
 * Output: 7
 * Explanation: One way to fill up the cups is:
 * Second 1: Fill up a cold cup, and a hot cup.
 * Second 2: Fill up a cold cup, and a warm cup.
 * Second 3: Fill up a cold cup, and a warm cup.
 * Second 4: Fill up a warm cup, and a hot cup.
 * Second 5: Fill up a cold cup, and a hot cup.
 * Second 6: Fill up a cold cup, and a warm cup.
 * Second 7: Fill up a hot cup.
 *
 *
 * Example 3:
 *
 *
 * Input: amount = [5,0,0]
 * Output: 5
 * Explanation: Every second, we fill up a cold cup.
 *
 *
 *
 * Constraints:
 *
 *
 * amount.length == 3
 * 0 <= amount[i] <= 100
 *
 *
 */
#include <vector>
using namespace std;
#include <queue>;

// @lc code=start
class Solution
{
public:
  int fillCups(vector<int> &arr)
  {
    priority_queue<int> pq;

    for (int i = 0; i < 3; i++)
    {
      if (arr[i])
        pq.push(arr[i]);
    }

    int ans = 0;

    while (pq.size() > 2)
    {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();

      if (a-- > 0)
        pq.push(a);
      if (b-- > 0)
        pq.push(b);

      ans++;
    }

    if (pq.size())
      ans += pq.top();

    return ans;
  }
};
// @lc code=end
