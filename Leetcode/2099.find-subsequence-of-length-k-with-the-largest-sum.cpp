/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 *
 * https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
 *
 * algorithms
 * Easy (42.66%)
 * Likes:    697
 * Dislikes: 64
 * Total Accepted:    24.7K
 * Total Submissions: 57.9K
 * Testcase Example:  '[2,1,3,3]\n2'
 *
 * You are given an integer array nums and an integer k. You want to find a
 * subsequence of nums of length k that has the largest sum.
 *
 * Return any such subsequence as an integer array of length k.
 *
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,1,3,3], k = 2
 * Output: [3,3]
 * Explanation:
 * The subsequence has the largest sum of 3 + 3 = 6.
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,-2,3,4], k = 3
 * Output: [-1,3,4]
 * Explanation:
 * The subsequence has the largest sum of -1 + 3 + 4 = 6.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,4,3,3], k = 2
 * Output: [3,4]
 * Explanation:
 * The subsequence has the largest sum of 3 + 4 = 7.
 * Another possible subsequence is [4, 3].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * -10^5 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 *
 *
 */
// #include <bits/stdc++.h>
#include <headers.h>
// @lc code=start
// typedef pair<int, int> pi;
// class Solution
// {
// public:
//   vector<int> maxSubsequence(vector<int> &nums, int k)
//   {
//     vector<int> ans;
//     int n = nums.size();
//     if (n == k)
//       return nums;

//     priority_queue<pi, vector<pi>, greater<pi>> pq;
//     for (int i = 0; i < n; i++)
//     { // sorting by value  (storing top k greater  value)
//       pq.push({nums[i], i});
//       if (pq.size() > k)
//         pq.pop();
//     }
//     priority_queue<pi, vector<pi>, greater<pi>> sort;
//     while (!pq.empty())
//     { // sorting by index for subsequences
//       sort.push({pq.top().second, pq.top().first});
//       pq.pop();
//     }
//     while (!sort.empty())
//     { // pushing in ans
//       ans.push_back(sort.top().second);
//       sort.pop();
//     }

//     return ans;
//   }
// };
class Solution
{
public:
  vector<int> maxSubsequence(vector<int> &a, int k)
  {
    priority_queue<pair<int, int>> pq;

    for (auto i = 0; i < a.size(); ++i)
    {
      pq.emplace(a[i], i);
    }

    vector<pair<int, int>> sorted;
    sorted.reserve(k);

    for (auto i = 0; i < k; ++i)
    {
      sorted.push_back(pq.top());
      pq.pop();
    }

    sort(sorted.begin(), sorted.end(), [](auto const &a, auto const &b)
         { return a.second < b.second; });

    vector<int> results;
    results.resize(k);

    transform(sorted.begin(), sorted.end(), results.begin(), [](auto const &x)
              { return x.first; });

    return results;
  }
};
// @lc code=end
