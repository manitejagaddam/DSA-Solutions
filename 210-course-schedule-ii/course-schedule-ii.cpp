class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++)
            if(inDegree[i] == 0) 
                q.push(i);
        
        int coursesCompleted = 0;
        vector<int> ans;
        
        while(!q.empty()){
            int course = q.front();
            q.pop();
            coursesCompleted++;
            ans.push_back(course);


            for(int i : adj[course])
                if(--inDegree[i] == 0) 
                    q.push(i);
        }
        reverse(ans.begin(), ans.end());
        return numCourses == coursesCompleted ? ans : vector<int>{};
        // return ans;
    }
};