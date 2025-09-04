class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        
        while(!q.empty()){
            int course = q.front();
            q.pop();
            coursesCompleted++;

            for(int i : adj[course])
                if(--inDegree[i] == 0) 
                    q.push(i);
        }

        return numCourses == coursesCompleted;
    }
};