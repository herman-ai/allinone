#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
    private:
        unordered_map<char, Node*> children;
        bool isword;
        string prefix;
    public:
        ~Node();
        Node(string prefix, bool isword) {
            this->prefix = prefix;
            this->isword = isword;
        }
        bool get_isword();
        string get_prefix();
        unordered_map<char, Node*> get_children();
        void add_child(string prefix, char c, bool isword=false);
        bool has_child(char c);
        Node * operator[](char c);
        void set_word(char c);
        void insert_string(string s);
};

class autocomplete {
    private:
        Node* trie = nullptr;
        void insert_string(string);
        vector<string> find_all_words(Node *);
    public:
        ~autocomplete();
        autocomplete(vector<string> strings);
        vector<string> get_autocomplete(string prefix);
};