class LRUCache {
public:
    class Dll{
        public:
        int val;
        Dll *pre,*next;
        Dll()
        {
            val = -1;
            pre = NULL;
            next = NULL;
        }
    };
    int cap,curr;
    Dll *start,*end;
    unordered_map<int,pair<Dll*,int>> mpp;
    LRUCache(int capacity) {
        curr = 0;
        cap = capacity;
        Dll *n1 = new Dll();
        Dll *n2 = new Dll();
        start = n1;
        end = n2;
        start->next = end;
        end->pre = start;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())
            return -1;
        else
        {
            Dll *temp = mpp[key].first;
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            
            Dll *save = start->next;
            start->next = temp;
            temp->pre = start;
            temp->next = save;
            temp->next->pre = temp;
            
            // cout<<"get : "<<start->next->val<<"\n";
            return mpp[key].second;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end())
        {
            Dll *temp = mpp[key].first;
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            
            Dll *save = start->next;
            start->next = temp;
            temp->pre = start;
            temp->next = save;
            temp->next->pre = temp;
            
            mpp[key].second = value;
        }
        else
        {
            if(curr == cap)
            {
                Dll *temp = new Dll();
                temp->val = key;
                mpp[key] = {temp,value};
                
                Dll *save = start->next;
                start->next = temp;
                temp->pre = start;
                temp->next = save;
                temp->next->pre = temp;
                
                Dll *del = end->pre;
                int v = del->val;
                del->pre->next = end;
                end->pre = del->pre;
                
                mpp.erase(v);
            }
            else
            {
                Dll *temp = new Dll();
                temp->val = key;
                mpp[key] = {temp,value};
                
                Dll *save = start->next;
                start->next = temp;
                temp->pre = start;
                temp->next = save;
                temp->next->pre = temp;
                
                curr++;
            }
            // cout<<"put : "<<start->next->val<<"\n";
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */