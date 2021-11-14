class CombinationIterator {
public:
    vector<string> s;
    int x;
    void gen(int n,string c,int ind,int cl,vector<string> &s,string cs)
    {
        if(ind == c.length())
        {
            if(cl == n)
            {
                s.push_back(cs);
            }
            else
                return;
        }
        else
        {
            if(cl<n)
            {
                gen(n,c,ind+1,cl+1,s,cs+c[ind]);
                gen(n,c,ind+1,cl,s,cs);
            }
            else
            {
                gen(n,c,ind+1,cl,s,cs);
            }
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        x = 0;
        gen(combinationLength,characters,0,0,s,"");
        // for(auto it:s)
        //     cout<<it<<" ";
        // cout<<s.size();
        sort(s.begin(),s.end());
    }
    
    string next() {
        return s[x++];
    }
    
    bool hasNext() {
        if(x<s.size())
            return true;
        else
            return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */