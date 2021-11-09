class Trie{
    public:
    class Node{
        public:
        int end_sum;
        Node* next[2];
        Node()
        {
            end_sum = 0;
            next[0] = NULL;
            next[1] = NULL;
        }
    };
    Node *trie;
    Trie()
    {
        trie = new Node();
    }
    void insert(string s)
    {
        Node *it = trie;
        for(int i=0;i<s.length();i++)
        {
            if(it->next[s[i]-'0'] == NULL)
            {
                Node *new_node = new Node();
                it->next[s[i]-'0'] = new_node;
            }
            it = it->next[s[i]-'0'];
        }
        it->end_sum += 1;
        // cout<<it<<" | | ";
        // cout<<it->end_sum<<" ";
    }
    int func(Node *it,string &s,int skip,int ind)
    {
        if(ind>25)
            return 0;
        // cout<<"at ind: "<<ind<<" ";
        int x = s[ind]-'0';
        if(x == 0)
        {
            if(it->next[x] == NULL)
                return 0;
            else
            {
                int v1 = 0;
                // if(ind+1<=skip)
                // {
                //     v1 = func(it->next[x],s,skip,ind+1);
                // }
                // else
                // {
                    v1 = func(it->next[x],s,skip,ind+1) + it->next[x]->end_sum;
                // }
                // cout<<v1<<" "<<"ind : "<<ind<<" || ";
                return v1;
            }
        }
        else
        {
            // if(it->next[x] == NULL)
            //     return 0;
            // else
            // {
                int v1 = 0,v2 = 0;
                // if(ind+1<=skip)
                // {
                //     if(it->next[0] != NULL)
                //     v1 = func(it->next[0],s,skip,ind+1);
                //     if(it->next[1] != NULL)
                //     v2 = func(it->next[1],s,skip,ind+1);
                //     // cout<<v1+v2<<" v1+v2 "<<"ind : "<<ind<<" || ";
                // }
                    if(ind == skip)
                    {
                        if(it->next[1]!=NULL)
                        v2 = func(it->next[1],s,skip,ind+1) + it->next[1]->end_sum;
                    }
                else
                {
                    
                    if(it->next[0] != NULL)
                    v1 = func(it->next[0],s,skip,ind+1)+it->next[0]->end_sum;
                    if(it->next[1] != NULL)
                    v2 = func(it->next[1],s,skip,ind+1) + it->next[1]->end_sum;
                    // cout<<v1+v2<<"endsum : "<<"ind : "<<ind<<" || ";
                }
                return v1+v2;
            // }
        }
    }
    int find(string s,char first)
    {
        int ans = 0;
        int skip = first-'a';
        Node *it = trie;
        // cout<<skip<<first<<"\n";
        return func(it,s,skip,0);
        // for(int i=0;i<s.length();i++)
        // {
        //     if(it->next[s[i]-'0'] == NULL)
        //     {
        //         Node *new_node = new Node();
        //         it->next[s[i]-'0'] = new_node;
        //     }
        //     it = it->next[s[i]-'0'];
        //     if(i+1<=skip)
        //         continue;
        //     else
        //     {
        //         ans += it->end_sum;
        //     }
        // }
        return ans;
    }
};
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<string> w,p;
        int n = words.size();
        Trie *mytrie = new Trie();
        for(int i=0;i<n;i++)
        {
            set<char> temp;
            for(int j=0;j<words[i].length();j++)
                temp.insert(words[i][j]);
            string val = "";
            for(char j='a';j<='z';j++)
            {
                if(temp.find(j) != temp.end())
                    val += '1';
                else
                    val += '0';
            }
            mytrie->insert(val);
            // cout<<val<<" ";
            // cout<<mytrie->find(val,words[i][0])<<" ";
            // w.push_back(val);
        }
        // cout<<"\n";
        vector<int> res;
        n = puzzles.size();
        for(int i=0;i<n;i++)
        {
            set<char> temp;
            for(int j=0;j<puzzles[i].length();j++)
                temp.insert(puzzles[i][j]);
            string val = "";
            for(char j='a';j<='z';j++)
            {
                if(temp.find(j) != temp.end())
                    val += '1';
                else
                    val += '0';
            }
            int v1 = mytrie->find(val,puzzles[i][0]);
            res.push_back(v1);
            // cout<<val<<" "<<puzzles[i][0]<<" ";
            // p.push_back(val);
        }
        // cout<<"\n";
        return res;
    }
};