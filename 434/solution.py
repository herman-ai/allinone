class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def find_floor(node):
    rval = None
    if node.left is not None:
        curr = node.left
        while curr.right is not None:
            curr = curr.right
        rval = curr.value
    return rval

def find_ceiling(node):
    rval = None
    if node.right is not None:
        curr = node.right
        while curr.left is not None:
            curr = curr.left
        rval = curr.value
    return rval


def find_floor_and_ceiling(root, value):
    curr = root
    floor, ceiling = (None, None)
    f, c = False, False
    while not f and not c:
        if curr.value == value:
            floor, ceiling = find_floor(curr), find_ceiling(curr)
            c, f = True, True
        elif value < curr.value:
            ceiling = curr.value
            if curr.left is not None:
                curr = curr.left
            else:
                c = True
        elif value > curr.value:
            floor = curr.value
            if curr.right is not None:
                curr = curr.right
            else:
                f = True
    return floor, ceiling


def make_bst():
    leafs = [Node(-3), Node(-1), Node(1), Node(3)]
    level2 = [Node(-2), Node(2)]
    root = Node(0)
    root.left = level2[0]
    root.right = level2[1]
    level2[0].left = leafs[0]
    level2[0].right = leafs[1]
    level2[1].left = leafs[2]
    level2[1].right = leafs[3]
    return root

if __name__ == "__main__":
    root = make_bst()
    val = 2.1
    f, c = find_floor_and_ceiling(root, val)
    print(f'floor = {f}, ceiling = {c} for {val}')

    

