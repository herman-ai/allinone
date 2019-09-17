#include "autocomplete.hpp"
#include <iostream>

int _main() {
    vector<string> strings = {"abc", "abbc", "def", "a", "acg"};
    auto a = autocomplete(strings);
    auto results = a.get_autocomplete("ab");
    cout << "doing autocomplete" << endl;
    for (auto w : results) {
        cout << w << endl;
    }
    return 0;
}

Node::~Node() {
    cout << "BEGIN Deleting " << this->prefix << endl;
    for (auto & p : children) {
        delete p.second;
    }
    cout << "END Deleting " << this->prefix << endl;
}


bool Node::get_isword() {
    return isword;
}

string Node::get_prefix() {
    return prefix;
}

unordered_map<char, Node*> Node::get_children() {
    return children;
}
void Node::add_child(string prefix, char c, bool isword) {
    children[c] = new Node(prefix+c, isword);
}

bool Node::has_child(char c) {
    return (children.find(c) != children.end());
}
Node * Node::operator[](char c) {
    return children[c];
}
void Node::set_word(char c) {
    auto itr = children.find(c);
    assert(itr != children.end());
    pair<char, Node *> _pair = *itr;
    _pair.second->isword = true;
}

void autocomplete::insert_string(string s) {
    auto curr = trie;
    string prefix="";
    for (int i=0; i<s.size(); i++) {
        char c = s[i];
        if (!curr->has_child(c)) {
            curr->add_child(prefix, c);
        }
        if (i==s.size()-1) {
            curr->set_word(c);
        }
        curr = curr->get_children()[c];
        prefix += s[i];
    }
}

autocomplete::autocomplete(vector<string> strings) {
    for (auto s : strings) {
        insert_string(s);
    }
}
vector<string> autocomplete::get_autocomplete(string prefix) {
    // First get to the node for this prefix
    Node * curr = trie;
    for (char c : prefix) {
        if (!curr->has_child(c)) {
            return {};  //empty list at this point
        }
        curr = (*curr)[c];
    }
    return find_all_words(curr);
}

vector<string> autocomplete::find_all_words(Node * curr) {
    vector<string> results;
    queue<Node *> unvisited;
    unvisited.push(curr);
    while (!unvisited.empty()) {
        curr = unvisited.front();
        unvisited.pop();
        if (curr->get_isword()) {
            results.push_back(curr->get_prefix());
        }
        for (pair<char, Node *> child : curr->get_children()) {
            unvisited.push(child.second);
        }
    }
    return results;
}

autocomplete::~autocomplete() {
    delete trie;
}
