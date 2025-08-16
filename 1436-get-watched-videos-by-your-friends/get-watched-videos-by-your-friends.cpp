class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> mpp;
        queue<int> q;
        q.push(id);
        unordered_set<int> visited;
        visited.insert(id);
        int level_idx = 0;
        while(level_idx < level){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                int node = q.front();
                q.pop();
                for(int neighbourNode : friends[node]){
                    if(visited.find(neighbourNode) == visited.end()){
                        q.push(neighbourNode);
                        visited.insert(neighbourNode);
                    }
                }
            }
            level_idx++;
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(string vedio : watchedVideos[node]){
                mpp[vedio]++;
            }
        }
        vector<pair<string,int>> freqArr(mpp.begin(), mpp.end());
        sort(freqArr.begin(), freqArr.end(), [](auto &a, auto &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for(auto it : freqArr){
            ans.push_back(it.first);
        }

        return ans;

    }
};