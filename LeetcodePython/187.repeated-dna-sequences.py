#
# @lc app=leetcode id=187 lang=python3
#
# [187] Repeated DNA Sequences
#

# @lc code=start
from typing import List


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        ans, dic = [], {}

        for i in range(len(s)-9):
            if s[i:i+10] in dic and s[i:i+10] not in ans:
                ans.append(s[i:i+10])
            dic[s[i:i+10]] = 0
        return ans


# @lc code=end
