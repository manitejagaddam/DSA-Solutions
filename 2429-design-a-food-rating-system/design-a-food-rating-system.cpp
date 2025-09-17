class FoodRatings {
private:
    // cuisine -> (rating -> set of foods)
    unordered_map<string, map<int, set<string>>> mpp;

    // food -> (rating, cuisine)
    unordered_map<string, pair<int, string>> food_mpp;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int len = foods.size();

        for (int idx = 0; idx < len; idx++) {
            string food = foods[idx];
            string cuisine = cuisines[idx];
            int rating = ratings[idx];

            mpp[cuisine][rating].insert(food);
            food_mpp[food] = {rating, cuisine};
        }
    }

    void changeRating(string food, int newRating) {
        auto [old_rating, cuisine] = food_mpp[food];

        mpp[cuisine][old_rating].erase(food);
        if (mpp[cuisine][old_rating].empty()) {
            mpp[cuisine].erase(old_rating); 
        }

        mpp[cuisine][newRating].insert(food);

        
        food_mpp[food] = {newRating, cuisine};
    }

    string highestRated(string cuisine) {
        if (mpp.find(cuisine) == mpp.end()) return "";
        
        auto it = mpp[cuisine].rbegin();
        
        return *it->second.begin();
    }
};
