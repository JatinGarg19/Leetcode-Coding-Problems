class TrieNode {
public:
    char data;
    
    TrieNode* children[26];
    
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        
        isTerminal = false;
    }
};

class Trie {
    // Initialize root
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    // Utility function
    void insertUtil(TrieNode* root, string word) {
        //Base Case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        int idx = word[0] - 'a';
        
        TrieNode* child;
        
        // Present
        if(root->children[idx] != NULL) {
            child = root->children[idx];
        }
        
        // Absent
        else{
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }
        
        // Recursion
        insertUtil(child, word.substr(1));
    }
    
    void insert(string word) {
        return insertUtil(root, word);
    }
    
    bool searchutil(TrieNode* root, string word) {
        // Base Case
        if(word.length() == 0) {
            return root->isTerminal;
        }
        
        int idx = word[0] - 'a';
        
        TrieNode* child;
        
        // Present
        if(root->children[idx] != NULL) {
            child = root->children[idx];
        }
        
        // Absent
        else{
            return false;
        }
        
        // Recursion
        return searchutil(child, word.substr(1));
    }
    
    bool search(string word) {
        return searchutil(root, word);
    }
    
    bool prefixutil(TrieNode* root, string prefix) {
        // Base Case
        if(prefix.length() == 0) {
            return true;
        }
        
        int idx = prefix[0] - 'a';
        
        TrieNode* child;
        
        // Present
        if(root->children[idx] != NULL) {
            child = root->children[idx];
        }
        
        // Absent
        else{
            return false;
        }
        
        // Recursion
        return prefixutil(child, prefix.substr(1));
    }
    
    bool startsWith(string prefix) {
        return prefixutil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */