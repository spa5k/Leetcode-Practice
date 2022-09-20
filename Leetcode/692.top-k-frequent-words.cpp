/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (55.08%)
 * Likes:    5170
 * Dislikes: 271
 * Total Accepted:    427.6K
 * Total Submissions: 776.1K
 * Testcase Example:  '["i","love","leetcode","i","love","coding"]\n2'
 *
 * Given an array of strings words and an integer k, return the k most frequent
 * strings.
 *
 * Return the answer sorted by the frequency from highest to lowest. Sort the
 * words with the same frequency by their lexicographical order.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["i","love","leetcode","i","love","coding"], k = 2
 * Output: ["i","love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 *
 *
 * Example 2:
 *
 *
 * Input: words =
 * ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
 * Output: ["the","is","sunny","day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 500
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * k is in the range [1, The number of unique words[i]]
 *
 *
 *
 * Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    map<string, int> cnt;
    vector<pair<int, string>> candidates;
    vector<string> res;
    priority_queue<pair<int, string>> h;
    for (string &word : words)
      cnt[word]++;
    for (auto &p : cnt)
    {
      h.push({-p.second, p.first});
      if (h.size() > k)
        h.pop();
    }
    while (!h.empty())
    {
      candidates.push_back(h.top());
      h.pop();
    }
    sort(candidates.begin(), candidates.end());
    for (auto &p : candidates)
      res.push_back(p.second);
    return res;
  }
};
// @lc code=end
