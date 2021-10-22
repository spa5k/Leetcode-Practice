#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = dict()
        for i in range(len(nums)):
            if target - nums[i] in hash_map:
                return [hash_map[target-nums[i]], i]
            else:
                hash_map[nums[i]] = i
# @lc code=end