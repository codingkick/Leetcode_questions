class Trie{
    public:
    class Node{
        public:
        bool end;
        Node* next[26];
        Node()
        {
            end = false;
            for(int i=0;i<26;i++)
                next[i] = NULL;
        }
    };
    Node *trie;
    Trie()
    {
        trie = new Node();
    }
    void insert(string &w)
    {
        reverse(w.begin(),w.end());
        int n = w.length();
        Node *it = trie;
        for(int i=0;i<n;i++)
        {
            char temp = w[i]-'a';
            if(it->next[temp] == NULL)
            {
                Node *new_node = new Node();
                it->next[temp] = new_node;
            }
            it = it->next[temp];
        }
        it->end = true;
    }
    bool search(string &w)
    {
        int n = w.length();
        Node *it = trie;
        for(int i=n-1;i>=0;i--)
        {
            // cout<<w[i]<<" ";
            char temp = w[i]-'a';
            if(it->end == true)
                return true;
            if(it->next[temp] == NULL)
                return false;
            it = it->next[temp];
        }
        // cout<<"\n";
        return it->end;
    }
};
class StreamChecker {
public:
    string total_str = "";
    Trie *mytrie = new Trie();
    StreamChecker(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            string t = words[i];
            mytrie->insert(words[i]);
            // cout<<mytrie->search(t)<<" ";
        }
    }
    
    bool query(char letter) {
        total_str += letter;
        return mytrie->search(total_str);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */