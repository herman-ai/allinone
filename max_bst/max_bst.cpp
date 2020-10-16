/*
Given a tree, return the size of the largest tree/subtree that is a BST.
*/

#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node * left;
    Node * right;

    Node(int val, Node* left=nullptr, Node* right=nullptr): val(val), left(left), right(right) {}
    ~Node() {
        delete left;
        delete right;
        left = nullptr;
        right = nullptr;
    }
};

struct Result {
    bool is_bst;
    int size;
    Result(bool is_bst, int size=0):is_bst(is_bst), size(size) {}
};

Result larget_bst(const Node* root) {
    int size = 0;
    Result res = Result(false);

    if (root->left == nullptr && root->right == nullptr) {
        res = Result(true, 1);
    } else if (root->left == nullptr) {
        Result r = larget_bst(root->right);
        bool is_bst = r.is_bst && (root->val <= root->right->val);
        res = is_bst ? Result(true, r.size+1) : Result(false, r.size);
    } else if (root->right == nullptr) {
        Result l = larget_bst(root->left);
        bool is_bst = l.is_bst && (root->val >= root->left->val);
        res = is_bst ? Result(true, l.size+1) : Result(false, l.size);
    } else {
        Result r = larget_bst(root->right);
        Result l = larget_bst(root->left);
        bool is_bst = l.is_bst && (root->val >= root->left->val) && (root->val <= root->right->val);
        res = is_bst ? Result(true, r.size + l.size + 1) : Result(false, max(r.size, l.size));
    }
    return res;
}

int _main() {
    Node* root = new Node(0, new Node(0), new Node(1));
    root = new Node(2, root, nullptr);
    cout << larget_bst(root).size << endl;
    delete root;
    return 0;
}