class NumArray {

private:
    vector<int> segTree;
    vector<int> arr;
    int n;

    void build(int idx, int left, int right){
        if(left == right) {
            segTree[idx] = arr[left];
            return;
        }
        if(left > right) return;

        int mid = (left + right) / 2;
        build(2 * idx + 1, left, mid);
        build(2 * idx + 2, mid + 1, right);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    void update(int idx, int start, int end, int index, int val){
        if(start == end){
            segTree[idx] = val;
            return;
        }
        int mid = (start + end) / 2;
        if(index <= mid) update(2 * idx + 1, start, mid, index, val);
        else update(2 * idx + 2, mid + 1, end, index, val);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    int query(int idx, int left, int right, int queryLeft, int queryRight){
        if(left > queryRight || right < queryLeft) return 0;
        if(left >= queryLeft && right <= queryRight) return segTree[idx];
        int mid = (left + right) / 2;
        int ans = 0;
        ans += query(2 * idx + 1, left, mid, queryLeft, queryRight);
        ans += query(2 * idx + 2, mid + 1, right, queryLeft, queryRight);
        return ans;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        segTree.resize(4 * n);
        build(0, 0, n - 1);        
    }
    
    void update(int index, int val) {
        update(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */