def findClosestValueInBst(tree, target):
    return bst_helper(tree, target, tree.value)


def bst_helper(tree, target, closest):
    if tree is None:
        return closest
    if abs(target-closest) > abs(target-tree.value):
        closest = tree.value
    if target < tree.value:
        return bst_helper(tree.left, target, closest)
    elif target > tree.value:
        return bst_helper(tree.right, target, closest)
    else:
        return closest

# This is the class of the input tree. Do not edit.


class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
