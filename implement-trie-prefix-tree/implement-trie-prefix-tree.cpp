class Trie {
public:
    class Node
    {
        public:
        int end;
        Node* next[26];
        Node()
        {
            end = false;
            for(int i=0;i<26;i++)
                next[i] = NULL;
        }
    };
    Node* trie;
    Trie() {
        trie = new Node();
    }
    
    void insert(string word) {
        Node *it = trie;
        for(int i=0;i<word.length();i++)
        {
            if(it->next[word[i]-'a'] == NULL)
            {
                Node *new_node = new Node();
                it->next[word[i]-'a'] = new_node;
            }
            it = it->next[word[i]-'a'];
        }
        it->end = true;
    }
    
    bool search(string word) {
        Node *it = trie;
        for(int i=0;i<word.length();i++)
        {
            if(it->next[word[i]-'a'] == NULL)
            {
                return false;
            }
            it = it->next[word[i]-'a'];
        }
        if(it->end == true)
            return true;
        else
            return false;
    }
    
    bool startsWith(string word) {
        Node *it = trie;
        for(int i=0;i<word.length();i++)
        {
            if(it->next[word[i]-'a'] == NULL)
            {
                return false;
            }
            it = it->next[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */