class Solution {

private:
    void createShortestPath(vector<vector<int>> & mat){
        int len = mat.size();
        for(int k = 0 ; k < len ; k++){
            for(int i = 0 ; i < len ; i++){
                for(int j = 0 ; j < len ; j++){
                    if(mat[i][k] < INT_MAX && mat[k][j] < INT_MAX){
                        mat[i][j] = mat[i][j] > mat[i][k] + mat[k][j] ? mat[i][k] + mat[k][j] : mat[i][j];
                    }
                }
            }
        }
    }

    void printMat(vector<vector<int>> & mat){
        int len = mat.size();
        for(int row = 0 ; row < len ; row++){
            for(int col = 0 ; col < len ; col++){
                cout << mat[row][col] << " ";
            }cout << endl;
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n, vector<int> (n, INT_MAX));
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wei = it[2];
            adjMat[u][v] = wei;
            adjMat[v][u] = wei;
        }
        for(int dig_idx = 0 ; dig_idx < n ; dig_idx++) adjMat[dig_idx][dig_idx] = 0;
        createShortestPath(adjMat);
        // printMat(adjMat);
        int minNode = 0;
        int minCount = INT_MAX;
        for(int row = 0 ; row < n ; row++){
            int temp_count = 0;
            for(int col = 0 ; col < n ; col++){
                if(adjMat[row][col] <= distanceThreshold) temp_count++;
            }
            // minCount = minCount > = temp_count ? temp_count : minCount;
            if(temp_count <= minCount) {
                minCount = temp_count;
                minNode = row;
            }
        }

        return minNode;
    }
};