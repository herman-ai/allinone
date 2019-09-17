#ifndef _autocomplete_hpp_
#define _autocomplete_hpp_
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Node {
    string prefix; // The prefix formed at this level
    bool isword = false;
    unordered_map<char, Node*> children;

    public:
    Node(string prefix="", bool isword=false): prefix(prefix), isword(isword) {};
    ~Node();

    bool get_isword();

    string get_prefix();

    unordered_map<char, Node*> get_children();
    void add_child(string prefix, char c, bool isword=false);

    bool has_child(char c);
    Node * operator[](char c);
    void set_word(char c);
    
};

class autocomplete {


    Node * trie = new Node();
    void insert_string(string s);
    public:
    autocomplete(vector<string> strings);
    ~autocomplete();
    vector<string> get_autocomplete(string prefix);
    vector<string> find_all_words(Node * curr);
};

int _main();

#endif