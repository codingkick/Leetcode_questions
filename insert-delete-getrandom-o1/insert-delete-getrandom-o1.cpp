class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int,int> mpp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val) != mpp.end())
            return false;
        else
        {
            arr.push_back(val);
            mpp[val] = arr.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(mpp.find(val) == mpp.end())
            return false;
        else
        {
            int ind = mpp[val];
            int val2 = arr[arr.size()-1];
            swap(arr[arr.size()-1],arr[ind]);
            mpp[val2] = ind;
            arr.pop_back();
            mpp.erase(val);
            return true;
            // int last = arr[arr.size()-1];
            // arr[mpp[val]] = arr[arr.size()-1];
            // mpp[last] = mpp[val];
            // arr.pop_back();
            // mpp.erase(val);
            // return true;
        }
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */