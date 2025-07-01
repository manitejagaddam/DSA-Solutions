#include <bits/stdc++.h>
class Solution {
public:
    int lower(vector <int> arr, int target){
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(arr[mid] == target) {
                ans = mid;
                end = mid - 1;
            }else if(arr[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return ans;
    }

    int upper(vector <int> arr, int target){
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = (start  + end) / 2;
            if(arr[mid] == target){
                ans = mid;
                start = mid + 1;
            }else if(arr[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower(nums, target);
        int u = upper(nums, target);
        vector<int> result;
        // if(l == -1){
        //     return result; 
        // }
        // result[0] = l;
        // result[1] = u;
        result.push_back(l);
        result.push_back(u);
        return result;
    }
};