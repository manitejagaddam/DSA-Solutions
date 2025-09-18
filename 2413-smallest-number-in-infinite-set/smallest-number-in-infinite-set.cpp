class SmallestInfiniteSet {

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> st;

public:
    SmallestInfiniteSet() {
        for(int i = 1 ; i <= 1000 ; i++) addBack(i);       
    }
    
    int popSmallest() {
        int ele = pq.top();
        pq.pop();   
        st.erase(ele);
        return ele;        
    }
    
    void addBack(int num) {
        if(st.find(num) != st.end()) return;
        st.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */