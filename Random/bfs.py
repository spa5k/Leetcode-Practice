import collections


class Node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def bfs(root):
    if not root:
        return root
    q = collections.deque()
    q.append(root)
    res = []

    while q:
        current = q.popleft()
        if current.val:
            res.append(current.val)

        if current.left:
            q.append(current.left)

        if current.right:
            q.append(current.right)
    return res


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

#      a
#    /   \
#   b     c
#  / \     \
# d   e     f
#    /       \
#   g         h
print(bfs(a))
