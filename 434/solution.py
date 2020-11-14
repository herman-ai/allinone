class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def find_floor(root, value):
    curr = root
    floor = None
    found = False
    while not found and curr is not None:
        if value <= curr.value:
            curr = curr.left
        elif value > curr.value:
            floor = curr.value
            curr = curr.right
    return floor


def find_ceiling(root, value):
    curr = root
    ceiling = None
    found = False
    while not found and curr is not None:
        if value < curr.value:
            ceiling = curr.value
            curr = curr.left
        elif value >= curr.value:
            curr = curr.right
    return ceiling


def make_bst():
    root = Node(1)
    root.left = Node(-10)
    root.right = Node(10)
    root.left.left = Node(-15)
    root.left.right = Node(-5)
    root.left.left.left = Node(-17)
    root.left.left.right = Node(-12)
    root.left.right = Node(-5)
    root.left.right.left = Node(-8)
    root.left.right.right = Node(-2)

    root.right.left = Node(5)
    root.right.right = Node(15)
    root.right.left.left = Node(2)
    root.right.left.right = Node(8)
    root.right.right.left = Node(12)
    root.right.right.right = Node(17)
    return root

if __name__ == "__main__":
    root = make_bst()
    val = -14
    f = find_floor(root, val)
    print(f'floor = {f}, for {val}')
    c = find_ceiling(root, val)
    print(f'ceiling = {c}, for {val}')

    

