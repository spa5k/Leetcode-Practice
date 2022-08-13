#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#
# https://leetcode.com/problems/permutation-in-string/description /
#
# algorithms
# Medium (44.20%)
# Likes:    5547
# Dislikes: 160
# Total Accepted:    360.1K
# Total Submissions: 801.5K
# Testcase Example:  '"ab"\n"eidbaooo"'
#
# Given two strings s1 and s2, return true if s2 contains a permutation of s1,
# or false otherwise.
#
# In other words, return true if one of s1's permutations is the substring of
# s2.
#
#
# Example 1:
#
#
# Input: s1 = "ab", s2 = "eidbaooo"
# Output: true
# Explanation: s2 contains one permutation of s1 ("ba").
#
#
# Example 2:
#
#
# Input: s1 = "ab", s2 = "eidboaoo"
# Output: false
#
#
#
# Constraints:
#
#
# 1 <= s1.length, s2.length <= 10^4
# s1 and s2 consist of lowercase English letters.
#
#
#

# @lc code=start
# class Solution:
def checkInclusion(self, s1: str, s2: str) -> bool:
    n, m = len(s1), len(s2)
    if n > m:
        return False

    hash_s1 = hash_it(s1)

    hash_s2 = hash_it(s2)

    return False


def hash_it(str):
    hash1 = {}
    for i in range(len(str)):
        letter = str[i]
        if letter in hash1:
            hash1[letter] += 1
        else:
            hash1[letter] = 1
    return hash1


print(checkInclusion("", "adc", "dcda"))
# @lc code=end
