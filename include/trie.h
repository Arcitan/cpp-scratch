#include <bits/stdc++.h>

using namespace std;

class Trie {
   public:
    Trie();
    ~Trie();

    void add_string(const string &s);

    bool contains_prefix(const string &s) const;

    bool contains_string(const string &s) const;

    int go(int v, char ch);

    int get_link(int v);

   private:
    static constexpr size_t _NCHARS = 26;

    struct TrieNode {
        int next[_NCHARS];  // next character edge
        int go[_NCHARS];    // finite state automata transition
        int link = -1;      // suffix link
        int p = -1;         // parent node;
        char pch;           // character edge from parent -> curr
        bool leaf = false;  // whether this is the end of a word

        TrieNode(int p = -1, char pch = '$') : p(p), pch(pch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };

    vector<TrieNode> _trie{1};
};
