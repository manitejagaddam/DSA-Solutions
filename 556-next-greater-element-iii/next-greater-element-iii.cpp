class Solution {

private:
    vector<int> array(int n){
        vector<int> arr;
        while(n){
            arr.push_back(n % 10);
            n /= 10;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }

    int number(vector<int> nums){
        long long n = 0;
        for(int i : nums){

            n *= 10;
            n += i;
        }

        if(n > INT_MAX) return -1;

        return n;
    }


public:
    int nextGreaterElement(int num) {

        if (num > INT_MAX || num < INT_MIN) return -1;
        int bp = -1;
        vector<int> nums = array(num);
        int n = nums.size() - 1;

        for(int i : nums){
            cout << i << " ";
        }cout << endl;

        for(int i = n - 1 ; i >= 0 ; i--){
            if(nums[i] < nums[i + 1]){
                bp = i;
                break;
            }
        }
        cout << "bp : " << bp;

        if(bp == -1){
            return -1;
        }

        for(int i = n ; i >= bp + 1 ; i--){
            if(nums[i] > nums[bp]) {
                swap(nums[i], nums[bp]);
                break;
            }
        }

        reverse(nums.begin() + bp + 1, nums.end());

        int ans = number(nums);

        // if(ans > INT_MAX || ans < INT_MIN) return -1;
        return ans;
        
    }
};