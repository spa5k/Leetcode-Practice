#
# @lc app=leetcode id=395 lang=python3
#
# [395] Longest Substring with At Least K Repeating Characters
#
# https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
#
# algorithms
# Medium (44.35%)
# Likes:    3818
# Dislikes: 317
# Total Accepted:    152.6K
# Total Submissions: 342.8K
# Testcase Example:  '"aaabb"\n3'
#
# Given a string s and an integer k, return the length of the longest substring
# of s such that the frequency of each character in this substring is greater
# than or equal to k.
#
#
# Example 1:
#
#
# Input: s = "aaabb", k = 3
# Output: 3
# Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
#
#
# Example 2:
#
#
# Input: s = "ababbc", k = 2
# Output: 5
# Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and
# 'b' is repeated 3 times.
#
#
#
# Constraints:
#
#
# 1 <= s.length <= 10^4
# s consists of only lowercase English letters.
# 1 <= k <= 10^5
#
#
#

# @lc code=start
class Solution:
    def longestSubstring(str: str, k: int):
        from collections import Counter

        total_uniques = len(Counter(str))
        ans = 0

        # At each iteration, we look for the lengthiest subsrtring with a specific length (no_uniques)
        for no_uniques in range(1, total_uniques + 1):
            # each iteration starts with an empty sub and start_index and end_index at 0
            s = 0
            e = 0
            curr_sub = Counter()
            while e < len(str):
                curr_sub[str[e]] += 1  # first add the element at right index to the sub

                while (
                    len(curr_sub) > no_uniques
                ):  # if the number of unique characters in current sub exceedes no_uniques
                    curr_sub[str[s]] -= 1  # removes elements from the left side
                    if curr_sub[str[s]] == 0:
                        del curr_sub[str[s]]
                    s += 1

                for key in curr_sub:
                    if curr_sub[key] < k:
                        break
                else:
                    ans = max(ans, e - s + 1)
                e += 1
        return ans


# @lc code=end
