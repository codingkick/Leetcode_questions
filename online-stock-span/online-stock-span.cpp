class StockSpanner {
public:
    stack<int> s;
    vector<int> v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int n = v.size();
        while(!s.empty() && v[s.top()]<=price)
        {
            s.pop();
        }
        int ans = 0;
        if(s.size() == 0)
        {
            ans = n;
        }
        else
        {
            ans = n - s.top()-1;
        }
        s.push(n-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */