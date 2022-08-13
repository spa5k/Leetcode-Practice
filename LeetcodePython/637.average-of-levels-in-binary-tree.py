#
# @lc app=leetcode id=637 lang=python3
#
# [637] Average of Levels in Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        currentLevel=[root]
        result=[]

        if root==None:
            return result



        while currentLevel:
            nextLevel=[]
            sum=0
            for node in currentLevel:
                sum+=node.val
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            result.append(sum/len(currentLevel))
            currentLevel=nextLevel
# @lc code=end

