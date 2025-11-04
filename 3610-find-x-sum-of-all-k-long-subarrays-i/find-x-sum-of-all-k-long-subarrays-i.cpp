#include <bits/stdc++.h>
using namespace std;

class FrequencyArray {
private:
    unordered_map<int, int> freq;
    priority_queue<pair<int, int>> pq;

public:
    void add(int x) {
        freq[x]++;
        pq.push({freq[x], x});
    }

    void remove(int x) {
        if (freq.count(x)) {
            freq[x]--;
            if (freq[x] == 0)
                freq.erase(x);
            else
                pq.push({freq[x], x});
        }
    }

    vector<pair<int, int>> topK(int k) {
        vector<pair<int, int>> res;
        unordered_set<int> seen;
        while (!pq.empty() && res.size() < k) {
            auto [f, x] = pq.top();
            pq.pop();
            if (!freq.count(x) || freq[x] != f) continue;
            if (seen.count(x)) continue;
            res.push_back({x, f});
            seen.insert(x);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        // FrequencyArray fre;
        // vector<int> ans;
        // int len = nums.size();

        // for (int i = 0; i < k - 1; i++)
        //     fre.add(nums[i]);

        // for (int i = k - 1; i < len; i++) {
        //     fre.add(nums[i]);
        //     vector<pair<int, int>> top = fre.topK(x);
        //     // int sum = accumulate(top.begin(), top.end(), 0);
        //     int sum = 0;
        //     for(auto it : top) sum += it.first * it.second;
        //     ans.push_back(sum);
        //     fre.remove(nums[i - k + 1]);
        // }

        // return ans;



        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, int> cnt;
            for (int j = i; j < i + k; ++j) {
                ++cnt[nums[j]];
            }

            vector<pair<int, int>> freq;
            for (const auto& [key, value] : cnt) {
                freq.emplace_back(value, key);
            }
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());

            int xsum = 0;
            for (int j = 0; j < x && j < freq.size(); ++j) {
                xsum += freq[j].first * freq[j].second;
            }
            ans.push_back(xsum);
        }
        return ans;

        
    }
};
