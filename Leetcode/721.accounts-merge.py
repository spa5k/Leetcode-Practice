#
# @lc app=leetcode id=721 lang=python3
#
# [721] Accounts Merge
#

# @lc code=start
from typing import DefaultDict


class Solution:
    def accountsMerge(self, A):
        G, seen, ans = DefaultDict(list), set(), []

        for acc in A:
            for i in range(2, len(acc)):
                G[acc[i]].append(acc[i-1])
                G[acc[i-1]].append(acc[i])

        def dfs(email):
            seen.add(email)
            emailList = [email]
            for E in G[email]:
                if E not in seen:
                    emailList.extend(dfs(E))
            return emailList
        for acc in A:
            if acc[1] not in seen:
                ans.append([acc[0]] + sorted(dfs(acc[1])))
        return ans  # @lc code=end
