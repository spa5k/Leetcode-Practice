/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 *
 * https://leetcode.com/problems/search-suggestions-system/description/
 *
 * algorithms
 * Medium (66.85%)
 * Likes:    3691
 * Dislikes: 183
 * Total Accepted:    225.3K
 * Total Submissions: 337.4K
 * Testcase Example:  '["mobile","mouse","moneypot","monitor","mousepad"]\n"mouse"'
 *
 * You are given an array of strings products and a string searchWord.
 *
 * Design a system that suggests at most three product names from products
 * after each character of searchWord is typed. Suggested products should have
 * common prefix with searchWord. If there are more than three products with a
 * common prefix return the three lexicographically minimums products.
 *
 * Return a list of lists of the suggested products after each character of
 * searchWord is typed.
 *
 *
 * Example 1:
 *
 *
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
 * searchWord = "mouse"
 * Output: [
 * ["mobile","moneypot","monitor"],
 * ["mobile","moneypot","monitor"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"]
 * ]
 * Explanation: products sorted lexicographically =
 * ["mobile","moneypot","monitor","mouse","mousepad"]
 * After typing m and mo all products match and we show user
 * ["mobile","moneypot","monitor"]
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
 *
 *
 * Example 2:
 *
 *
 * Input: products = ["havana"], searchWord = "havana"
 * Output:
 * [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 *
 *
 * Example 3:
 *
 *
 * Input: products = ["bags","baggage","banner","box","cloths"], searchWord =
 * "bags"
 * Output:
 * [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= products.length <= 1000
 * 1 <= products[i].length <= 3000
 * 1 <= sum(products[i].length) <= 2 * 10^4
 * All the strings of products are unique.
 * products[i] consists of lowercase English letters.
 * 1 <= searchWord.length <= 1000
 * searchWord consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
  vector<vector<string>> suggestedProducts(vector<string> &P, string S)
  {
    sort(P.begin(), P.end());
    vector<vector<string>> ans;
    int left = 0, right = P.size() - 1;
    for (int i = 0; i < S.length(); i++)
    {
      vector<string> res;
      char c = S[i];
      while (left <= right && (P[left].length() == i || P[left][i] < c))
        left++;
      while (left <= right && (P[right].length() == i || P[right][i] > c))
        right--;
      for (int j = 0; j < 3 && left + j <= right; j++)
        res.push_back(P[left + j]);
      ans.push_back(res);
    }
    return ans;
  }
};
// @lc code=end
