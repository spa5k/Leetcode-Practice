/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (58.95%)
 * Likes:    7948
 * Dislikes: 316
 * Total Accepted:    515.8K
 * Total Submissions: 874.3K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 19
 *
 *
 */

// @lc code=start
// class Solution
// {
// public:
//   int dp[20]{};
//   int numTrees(int n)
//   {
//     // numTrees[4] =  numTrees[0]* numTrees[3] +
//     //                numTrees[1] * numTrees[2] +
//     //                numTrees[2] * numTrees[1] +
//     //                numTrees[3] * numTress[1]
//     if (n <= 1)
//       return 1;
//     if (dp[n])
//       return dp[n];
//     for (int i = 1; i <= n; i++)
//     {
//       dp[n] += numTrees(i - 1) * numTrees(n - i);
//     }
//     return dp[n];
//   }
// };

// class Solution
// {
// public:
//   int numTrees(int n)
//   {
//     vector<int> dp(n + 1);
//     dp[0] = dp[1] = 1;
//     for (int i = 2; i <= n; i++)
//       for (int j = 1; j <= i; j++)
//         dp[i] += dp[j - 1] * dp[i - j];
//     return dp[n];
//   }
// };
class Solution
{
public:
  int numTrees(int n)
  {
    long ans = 1;
    for (int i = 1; i < n; i++)
    {
      ans = ans * (n + i + 1) / i;
    }
    return ans / n;
  }
};

// @lc code=end
