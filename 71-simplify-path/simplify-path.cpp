class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (!curr.empty()) {
                    if (curr == "..") {
                        if (!stack.empty()) stack.pop_back();
                    } else if (curr != ".") {
                        stack.push_back(curr);
                    }
                    curr.clear();
                }
            } 
            else {
                curr += path[i];
            }
        }

        // handle last segment
        if (!curr.empty()) {
            if (curr == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (curr != ".") {
                stack.push_back(curr);
            }
        }

        // build result
        if (stack.empty()) return "/";

        string result = "";
        for (string &dir : stack) result += "/" + dir;

        return result;
    }
};