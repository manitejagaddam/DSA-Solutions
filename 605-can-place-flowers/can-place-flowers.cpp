class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(len < n) return false;
        if(len == 1 && flowerbed[0] == 0) return true;
        int idx = 1;
        if(len > 1 && flowerbed[0] == 0  && flowerbed[1] == 0) {
            n--;
            flowerbed[0] = 1;
        }
        for(; idx < len - 1 && n > 0; idx++){
            if(flowerbed[idx] == 0 && flowerbed[idx - 1] == 0 && flowerbed[idx + 1] == 0) {
                flowerbed[idx] = 1;
                n--;
            }
        }
        if(len > 1 && flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0){
            n--;
            flowerbed[len - 1] = 1;
        }
        return n <= 0;
    }
};