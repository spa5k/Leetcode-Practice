class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def dfs(root):
    if not root:
        return root
    left_values = dfs(root.left)
    right_values = dfs(root.right)
    res = []
    if root.val:
        res.append(root.val)
    if left_values:
        res.extend(left_values)
    if right_values:
        res.extend(right_values)
    return res


n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(4)
n4 = TreeNode(5)
n5 = TreeNode(6)
n6 = TreeNode(7)
#     1
# /       \
# 2          6
#   /   \       \
# 5   4       7
n1.left = n2
n2.right = n3
n2.left = n4
n1.right = n5
n5.right = n6
print(n1)

print(dfs(n1))
