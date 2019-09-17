#ifndef _autocomplete_hpp_
#define _autocomplete_hpp_
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class autocomplete {
    class Node {
        string prefix; // The prefix formed at this level
        bool isword = false;
        unordered_map<char, Node*> children;

        public:
        Node(string prefix="", bool isword=false): prefix(prefix), isword(isword) {};

        bool get_isword() {
            return isword;
        }

        string get_prefix() {
            return prefix;
        }

        unordered_map<char, Node*> get_children() {
            return children;
        }
        void add_child(string prefix, char c, bool isword=false) {
            children[c] = new Node(prefix+c, isword);
        }

        bool has_child(char c) {
            return (children.find(c) != children.end());
        }
        Node * operator[](char c) {
            return children[c];
        }
        void set_word(char c) {
            auto itr = children.find(c);
            assert(itr != children.end());
            pair<char, Node *> _pair = *itr;
            _pair.second->isword = true;
        }
    };

    Node * trie = new Node();
    void insert_string(string s) {
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
    public:
    autocomplete(vector<string> strings) {
        for (auto s : strings) {
            insert_string(s);
        }
    }
    vector<string> get_autocomplete(string prefix) {
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

    vector<string> find_all_words(Node * curr) {
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
};

int _main();

#endif