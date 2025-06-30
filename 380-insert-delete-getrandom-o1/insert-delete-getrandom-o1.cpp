class RandomizedSet {

vector<int> nums;
unordered_map<int, int> indexes;

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(indexes.find(val) != indexes.end()) return false;   
        nums.push_back(val);
        indexes[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(indexes.find(val) == indexes.end()) return false;
        int val_idx = indexes[val];
        int last_idx = nums.size() - 1;
        // swap(nums[last_idx], nums[val_idx]);
        nums[val_idx] = nums.back();
        indexes[nums.back()] = val_idx;
        
        nums.pop_back();
        indexes.erase(val);
        return true;
    }
    
    int getRandom() {
        int rand_idx = rand() % nums.size();
        return nums[rand_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */