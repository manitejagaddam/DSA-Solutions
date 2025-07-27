class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int> vis(rooms.size());
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int key : rooms[node]){
                if(!vis[key]) {
                    q.push(key);
                    vis[key] = 1;
                }
            }
        }
        // for(int it : vis)
        //     cout << it << " ";
        // cout << endl;

        for(int it : vis) 
            if(it == 0)
                return false;
        return true;
    }
};