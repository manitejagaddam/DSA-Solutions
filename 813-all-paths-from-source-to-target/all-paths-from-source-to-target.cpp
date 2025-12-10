class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});
        vector<vector<int>> ans;
        int n = graph.size();

        while(!q.empty()){
            int node = q.front().first;
            vector<int> temp = q.front().second;
            q.pop();
            if(node == n - 1) ans.push_back(temp);
            for(auto node : graph[node]){
                temp.push_back(node);
                q.push({node, temp});
                temp.pop_back();
            }
        }

        return ans;
    }
};