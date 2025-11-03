class Solution {

private:
    int findMinCost(int start, int end, vector<int> & time){
        // cout << end << " " << start << " ";
        if(end - start == 1) return min(time[start], time[end]);
        int minCost1 = 0;
        int minCost2 = 0;
        int startIdx = start;
        int endIdx = end;
        while(startIdx <= endIdx){
            minCost1 += time[startIdx];
            startIdx += 2;            
        }
        startIdx = start + 1;
        while(startIdx <= endIdx){
            minCost2 += time[startIdx];
            startIdx += 2;            
        }
        // cout << minCost1 << " " << minCost2 << endl;
        return min(minCost1, minCost2);        
    }

public:
    int minCost(string colors, vector<int>& neededTime) {
        // int cost = 0;
        // int idx = 1;
        // int end = colors.length();
        // int prevIdx = 0;
        // while(idx < end){
        //     bool sameColorFound = false;
        //     while(colors[idx] == colors[prevIdx]){
        //         sameColorFound = true;
        //         idx++;
        //     }
        //     if(sameColorFound) cost += findMinCost(prevIdx, idx - 1, neededTime);
        //     prevIdx = idx; 
        //     idx++;           
        // }
        // return cost;

        int cost = 0;
        int len = colors.size();
        for(int idx = 1 ; idx < len ; idx++){
            if(colors[idx] == colors[idx - 1]){

                cost += min(neededTime[idx], neededTime[idx - 1]);
                
                neededTime[idx] = max(neededTime[idx], neededTime[idx - 1]);
            
            }
        }
        return cost;

    }
};