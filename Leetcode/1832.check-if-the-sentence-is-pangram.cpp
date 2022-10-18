/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 *
 * https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
 *
 * algorithms
 * Easy (81.12%)
 * Likes:    1779
 * Dislikes: 40
 * Total Accepted:    168.3K
 * Total Submissions: 200.9K
 * Testcase Example:  '"thequickbrownfoxjumpsoverthelazydog"'
 *
 * A pangram is a sentence where every letter of the English alphabet appears
 * at least once.
 *
 * Given a string sentence containing only lowercase English letters, return
 * true if sentence is a pangram, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
 * Output: true
 * Explanation: sentence contains at least one of every letter of the English
 * alphabet.
 *
 *
 * Example 2:
 *
 *
 * Input: sentence = "leetcode"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= sentence.length <= 1000
 * sentence consists of lowercase English letters.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
  bool checkIfPangram(string sentence)
  {
    vector<bool> freq(26, false);

    for (auto ch : sentence)
      freq[ch - 'a'] = true;

    for (auto it : freq)
    {
      if (it == false)
        return false;
    }
    return true;
  }
};
// @lc code=end
