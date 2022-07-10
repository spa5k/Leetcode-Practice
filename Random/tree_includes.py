import collections


class Node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def tree_include2(root, target):
    if not root:
        return False
    q = collections.deque()
    q.append(root)
    res = []

    while q:
        current = q.popleft()

        if current.val:
            if current.val == target:
                return True
            res.append(current.val)

        if current.left:
            q.append(current.left)

        if current.right:
            q.append(current.right)
    return False


def recurse(root, target):
    if not root:
        return False

    if root.val == target:
        return True

    right = recurse(root.right, target)
    if right:
        return True
    left = recurse(root.left, target)
    if left:
        return True
    return False


a = Node('a')
b = Node('b')
c = Node('c')
d = Node('d')
e = Node('e')
f = Node('f')
g = Node('g')
h = Node('h')
i = Node(None)

a.left = b
a.right = c
b.left = d
b.right = e
c.right = f
e.left = g
f.right = h
h.left = i

print(tree_include2(a, 'as'))
print(recurse(a, 'h'))
