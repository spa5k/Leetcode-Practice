/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 *
 * https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
 *
 * algorithms
 * Medium (67.54%)
 * Likes:    1059
 * Dislikes: 78
 * Total Accepted:    52.6K
 * Total Submissions: 78K
 * Testcase Example:  '[2,2,2,2,5,5,5,8]\n3\n4'
 *
 * Given an array of integers arr and two integers k and threshold, return the
 * number of sub-arrays of size k and average greater than or equal to
 * threshold.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
 * Output: 3
 * Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6
 * respectively. All other sub-arrays of size 3 have averages less than 4 (the
 * threshold).
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
 * Output: 6
 * Explanation: The first 6 sub-arrays of size 3 have averages greater than 5.
 * Note that averages are not integers.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 10^4
 * 1 <= k <= arr.length
 * 0 <= threshold <= 10^4
 *
 *
 */
#include <headers.h>
// class Solution
// {
// public:
//   int numOfSubarrays(vector<int> &arr, int k, int threshold)
//   {
//     int res = 0;
//     int first = 0;
//     int j = k - 1;
//     while (j < arr.size())
//     {
//       vector<int> temp(k);
//       for (int i = first; i < k; i++)
//       {
//         temp.push_back(arr[i]);
//       }
//       int sum = accumulate(arr[first], arr[j], sum);
//       int average = sum / temp.size();
//       if (average >= threshold)
//       {
//         res++;
//       }
//       j++;
//       first++;
//     }
//     return res;
//   }
// };
// @lc code=start
class Solution
{
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold)
  {
    threshold *= k;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
      sum += arr[i];
    }
    if (sum >= threshold)
    {
      count++;
    }
    for (int i = k; i < arr.size(); i++)
    {
      sum += arr[i] - arr[i - k];
      if (sum >= threshold)
      {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
