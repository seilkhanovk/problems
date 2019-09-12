class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode() {
        memset(children, 0, sizeof(children));
        isWord = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        clear(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char ch: word) {
            if (!node->children[ch - 'a']) node->children[ch - 'a'] = new TrieNode;
            node = node->children[ch - 'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = findString(word);
        if (node && node->isWord) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = findString(prefix);
        if (node) return true;
        return false;
    }
private:
    TrieNode* root;
    
    TrieNode* findString(string word) {
        TrieNode* node = root;
        for (char ch: word) {
            if (!node->children[ch - 'a'])  {
                node = NULL;
                break;
            }
            node = node->children[ch - 'a'];
        }
        return node;
    }
    
    void clear(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) clear(node->children[i]);
        }
        delete node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
