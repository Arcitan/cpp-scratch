#include "trie.h"

Trie::Trie(){};
Trie::~Trie(){};

void Trie::add_string(const string &s) {
    int v = 0;
    for (const char &ch : s) {
        int c = ch - 'a';
        if (_trie[v].next[c] == -1) {
            _trie[v].next[c] = _trie.size();
            _trie.emplace_back(v, ch);
        }
        v = _trie[v].next[c];
    }
    _trie[v].leaf = true;
}

bool Trie::contains_prefix(const string &s) const {
    int v = 0;
    for (const char &ch : s) {
        int c = ch - 'a';
        if (_trie[v].next[c] == -1) {
            return false;
        }
        v = _trie[v].next[c];
    }
    return true;
}

bool Trie::contains_string(const string &s) const {
    int v = 0;
    for (const char &ch : s) {
        int c = ch - 'a';
        if (_trie[v].next[c] == -1) {
            return false;
        }
        v = _trie[v].next[c];
    }
    return _trie[v].leaf;
}

int Trie::get_link(int v) {
    if (_trie[v].link == -1) {
        if (v == 0 || _trie[v].p == 0) {
            _trie[v].link = 0;
        } else {
            _trie[v].link = go(get_link(_trie[v].p), _trie[v].pch);
        }
    }
    return _trie[v].link;
}

int Trie::go(int v, char ch) {
    int c = ch - 'a';
    if (_trie[v].go[c] == -1) {
        if (_trie[v].next[c] != -1) {
            _trie[v].go[c] = _trie[v].next[c];
        } else {
            _trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
    }
    return _trie[v].go[c];
}

int main() {
    Trie trie;
    trie.add_string("hello");
    trie.add_string("hellbringer");
    cout << trie.contains_string("hello") << endl;
    cout << trie.contains_string("hellos") << endl;
    cout << trie.contains_string("heaps") << endl;
    cout << trie.contains_string("hell") << endl;
    cout << trie.contains_prefix("hello") << endl;
    cout << trie.contains_prefix("hellos") << endl;
    cout << trie.contains_prefix("heaps") << endl;
    cout << trie.contains_prefix("hell") << endl;
    return 0;
}
