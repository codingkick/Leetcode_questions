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
        trie =  new Node();
    }
    void insert(string &w)
    {
        Node *it = trie;
        for(int i=0;i<w.length();i++)
        {
            if(it->next[w[i]-'a'] == NULL)
            {
                Node *new_node = new Node();
                it->next[w[i]-'a'] = new_node;
            }
            it = it->next[w[i]-'a'];
        }
        it->end = true;
    }
    bool search(string &w)
    {
        Node *it = trie;
        for(int i=0;i<w.length();i++)
        {
            if(it->next[w[i]-'a'] == NULL)
                return false;
            else
                it = it->next[w[i]-'a'];
        }
        return it->end;
    }
    bool prefix(string &w)
    {
        Node *it = trie;
        for(int i=0;i<w.length();i++)
        {
            if(it->next[w[i]-'a'] == NULL)
                return false;
            it = it->next[w[i]-'a'];
        }
        return true;
    }
};
class Solution {
public:
    void dfs(int x,int y,vector<vector<int>> &vis,vector<vector<char>> &board,set<string> &ans,int ind,string &curr,Trie *mytrie)
    {
        string c = curr+board[x][y];
        if(mytrie->prefix(c) == false)
            return;
        if(mytrie->search(c) == true)
        {
            ans.insert(c);
        }
        int m = board.size();
        int n = board[0].size();
        vis[x][y] = 1;
        if(x-1>=0 && vis[x-1][y] == 0)
        {
            curr.push_back((char)board[x][y]);
            dfs(x-1,y,vis,board,ans,ind+1,c,mytrie);
            curr.pop_back();
        }
        if(x+1<m && vis[x+1][y] == 0)
        {
            curr.push_back((char)board[x][y]);
            dfs(x+1,y,vis,board,ans,ind+1,c,mytrie);
            curr.pop_back();
        }
        if(y-1>=0 && vis[x][y-1] == 0)
        {
            curr.push_back((char)board[x][y]);
            dfs(x,y-1,vis,board,ans,ind+1,c,mytrie);
            curr.pop_back();
        }
        if(y+1<n && vis[x][y+1] == 0)
        {
            curr.push_back((char)board[x][y]);
            dfs(x,y+1,vis,board,ans,ind+1,c,mytrie);
            curr.pop_back();
        }
        vis[x][y] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<int> vec(n,0);
        vector<vector<int>> vis(m,vec);
        int s = words.size();
        Trie *mytrie = new Trie();
        for(int i=0;i<s;i++)
        {
            mytrie->insert(words[i]);
        }
        // mytrie->insert("oath");
        // cout<<mytrie->prefix("oath");
        set<string> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                string curr = "";
                dfs(i,j,vis,board,ans,0,curr,mytrie);
            }
        }
        
        vector<string> res;
        for(auto it:ans)
            res.push_back(it);
        return res;
    }
};