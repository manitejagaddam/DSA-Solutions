class Solution {

private:
    double area(vector<int> p1, vector<int> p2, vector<int> p3){
        double x1 = p1[0];
        double y1 = p1[1];
        double x2 = p2[0];
        double y2 = p2[1];
        double x3 = p3[0];
        double y3 = p3[1];
        return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int len = points.size();
        for(int p1 = 0 ; p1 < len - 2 ; p1++){
            for(int p2 = p1 + 1 ; p2 < len - 1 ; p2++){
                for(int p3 = p2 + 1 ; p3 < len ; p3++){
                    if(points[p1][0] == points[p2][0] && points[p1][0] == points[p3][0]) continue;
                    if(points[p1][1] == points[p2][1] && points[p1][1] == points[p3][1]) continue;
                    ans = max(ans, area(points[p1], points[p2], points[p3]));
                }
            }
        }
        // sort(points.begin(), points.end());
        // if(len % 2 == 0) return max(area(points[0], points[len / 2], points[len - 1]), area(points[0], points[(len + 1) / 2], points[len - 1]));
        // return area(points[0], points[len / 2], points[len - 1]);
        return ans;
        
    }
};