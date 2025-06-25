class Solution {
public:

    void insert(vector<int> &arr, int m, int n){
        reverse(arr.begin() + m, arr.begin() + n);
        reverse(arr.begin() + m + 1, arr.begin() + n);
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = 0;
        // int j = 0;
        // int k = 0;

        // if(m == 0){
        //     for(int i = 0; i < m ; i++){
        //         nums1[i] = nums2[i];
        //     }
        //     return;
        // }
        // if(n == 0){
        //     return;
        // }

        // for(int a = 0 ; a < m ; a++){
        //     if(nums1[a] == 0){
        //         i = a;
        //         break;
        //     }
        // }

        // while(j <= m){
        //     if(nums1[j] < nums2[k]){
        //         j++;
        //     }else if(nums1[j] >= nums2[k]){
        //         insert(nums1, j , i);
        //         nums1[j] = nums2[k];
        //         j++;
        //         k++;
        //     }
        // }



        // int i = m - 1;
        // int j = n - 1; 
        // int k = m + n - 1;

        // while (i >= 0 && j >= 0) {
        //     if (nums1[i] > nums2[j]) {
        //         nums1[k] = nums1[i];
        //         i--;
        //     } else {
        //         nums1[k] = nums2[j];
        //         j--;
        //     }
        //     k--;
        // }

        // while (j >= 0) {
        //     nums1[k] = nums2[j];
        //     j--;
        //     k--;
        // }



        if(n == 0) return;
        if(m == 0){
            nums1 = nums2;
            return;
        }

        int first_idx = m - 1;
        int second_idx = n - 1;
        int idx = nums1.size() - 1;

        while(first_idx >= 0 && second_idx >= 0){
            if(nums1[first_idx] > nums2[second_idx]){
                nums1[idx] = nums1[first_idx];
                first_idx--;
            }else{
                nums1[idx] = nums2[second_idx];
                second_idx--;
            }
            idx--;
        }

        while(second_idx >= 0){
            nums1[idx] = nums2[second_idx];
            second_idx--;
            idx--;
        }


        // int j = 0;
        // for(int i = m ; i < m + n ; i++){
        //     nums1[i] = nums2[j];
        //     j++;
        // }
        // sort(nums1.begin(), nums1.end());
    }
};