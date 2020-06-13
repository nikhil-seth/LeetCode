//  380. Insert Delete GetRandom O(1)

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int,int> m;
    RandomizedSet() {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)!=m.end()) return 0;
        v.emplace_back(val); // Emplace back bcoz, it doesn't increase size of array unnecesirally.
        m[val]=v.size()-1;
        return 1;
    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val){
        if(m.find(val)==m.end()) return 0;
        int x=m[val];
        m.erase(val);
        if(v.size()-1!=x){
            m[v.back()]=x;
            v[x]=v.back();
        }
        v.pop_back();
        return 1;
    }
        /** Get a random element from the set. */
    int getRandom(){
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */