class NumArray {
private:
    vector<int> seg;
    int n = 0;
    void build(vector<int> & nums, int idx, int start, int end){
        if(start == end) {
            seg[idx] = nums[start];
            return;    
        }
        if(start > end) return;

        int mid = (start + end) / 2;
        build(nums, 2 * idx + 1, start, mid);
        build(nums, 2 * idx + 2, mid + 1, end);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void update(int idx, int left, int right, int pos, int val){
        if(left == right) {
            seg[idx] = val;
            return;
        }

        int mid = (left + right) / 2;
        if(pos <= mid) update(2 * idx + 1, left, mid, pos, val);
        else update(2 * idx + 2, mid + 1, right, pos, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int start, int end, int queryLeft, int queryRight){
        if(queryLeft >end || queryRight < start) return 0;
        if(queryLeft <= start && queryRight >=end) return seg[idx];

        int mid = (start + end) / 2;
        int leftSum = query(2 * idx + 1, start, mid, queryLeft, queryRight);
        int rightSum = query(2 * idx + 2, mid + 1, end, queryLeft, queryRight);
        return leftSum + rightSum;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();        
        seg.resize(4 * n);
        build(nums, 0, 0, n - 1);
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