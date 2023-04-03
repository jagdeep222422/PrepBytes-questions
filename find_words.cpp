#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
};

void insert(TrieNode* root, string word) {
    TrieNode* node = root;
    for(char c: word) {
        if(!node->children.count(c))
            node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->endOfWord = true;
}

bool search(TrieNode* root, string word) {
    TrieNode* node = root;
    for(char c: word) {
        if(!node->children.count(c))
            return false;
        node = node->children[c];
    }
    return node != nullptr && node->endOfWord;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        TrieNode* root = new TrieNode();
        for(int i=0; i<n; i++) {
            string word;
            cin >> word;
            insert(root, word);
        }
        for(int i=0; i<m; i++) {
            string word;
            cin >> word;
            if(search(root, word))
                cout << "Present\n";
            else
                cout << "Not\n";
        }
    }
    return 0;
}
