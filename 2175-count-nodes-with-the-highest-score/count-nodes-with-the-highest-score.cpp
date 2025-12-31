class Solution {
    vector<vector<int>> adj;
    vector<long long> score;
    vector<int> size;
public:
    int dfs1(int u,int par){
        int c=1;
        for(auto v:adj[u]){
            if(v==par) continue;
            c+=dfs1(v,u);
        }
        return size[u]=c;
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        adj.resize(n);
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
            adj[i].push_back(parents[i]);
        }
        score.resize(n,1);
        size.resize(n,0);
        dfs1(0,-1);
        long long maxi=0;
        for(int i=0;i<n;i++){
            for(auto v:adj[i]){
                if(v==parents[i]){
                    score[i]*=(n-size[i]);
                }else{
                    score[i]*=size[v];
                }
            }
            maxi=max(maxi,score[i]);
        }

        
        int ans=0;
        for(int i=0;i<n;i++){
            if(score[i]==maxi) ans++;
        }

        return ans;

    }
};