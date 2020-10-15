#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <string>

using namespace std;

struct Node {
    char val;
    Node * left;
    Node * right;
};

string serialize(Node * root);
Node * deserialize(string s);

string serialize(Node * root) {
    string s;
    queue<Node *> fifo;
    Node * temp;

    fifo.push(root);

    while (!fifo.empty()) {
        temp = fifo.front();
        fifo.pop();

        s += root->val;
        s += 'L';
        if (root->left) {
            s += root->left->val;
            fifo.push(root->left);
        } else {
            s += '-';
        }
        s += 'R';
        if (root->right) {
            s += root->right->val;
            fifo.push(root->right);
        } else {
            s += '-';
        }
        s += "*";
    }

    return s;
}

Node * deserialize(string s) {
    map<char, pair<char, char>> tree;
    char * tok = strtok(const_cast<char *>(s.c_str()), "*");
    while (tok) {
        tree[tok[0]] = pair<char, char>(tok[2], tok[4]);
        tok = strtok(NULL, "*");
    }
    Node * tmp = new Node();
    tmp->val = s[0];
    while (true) {
        pair<char, char> sub = tree[s[0]];
        if (sub.first != '-') {
            Node * left = new Node();
            left->val = sub.first;
            tmp->left = left;
        }
        if (sub.second != '-') {
            Node * right = new Node();
            right->val = sub.second;
            tmp->right = right;
        }
    }
}

int _main() {
    return 0;
}

