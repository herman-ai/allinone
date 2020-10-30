//Given a binary tree (Not balanced), write a method that returns if the tree is symmetric or not

#include <iostream>
#include <deque>

using namespace std;

class Node {
    private:
        int val;
        const Node *left = nullptr, *right=nullptr;
    public:
        Node(int val): val(val){}
        void add_left(const Node *left) {
            this->left = left;
        }
        void add_right(const Node *right) {
            this->right = right;
        }
        bool has_left() const{
            return left != nullptr;
        }
        bool has_right() const{
            return right != nullptr;
        }
        int get_val() const{
            return val;
        }
        const Node *get_left() const{
            return left;
        }
        const Node *get_right() const{
            return right;
        }
};

bool is_symmetric(const Node *root) {
    if (!root->has_left() && !root->has_right()) {
        return true;
    }
    deque<const Node*> lQ, rQ;
    lQ.push_back(root->get_left());
    rQ.push_back(root->get_right());

    while (lQ.size() > 0 && rQ.size() >0) {
        const Node* x = lQ.front();
        const Node* y = rQ.front();
        lQ.pop_front();
        rQ.pop_front();
        if ((x==nullptr) xor (y==nullptr))
            return false;
        if (x!=nullptr) {
            cout << "x val = " << x->get_val() << endl;
            cout << "y val = " << y->get_val() << endl;
            if (x->get_val() != y->get_val()) {
                return false;
            }
            lQ.push_back(x->get_left());
            lQ.push_back(x->get_right());

            rQ.push_back(y->get_right());
            rQ.push_back(y->get_left());
        }
    }
    return true;
}

int _main() {
    Node * root = new Node(0);
    root->add_left(new Node(3));
    root->add_right(new Node(3));
    bool result = is_symmetric(root);
    cout << "Is this a symmetric tree ?" << result << endl;
    return 0;
}