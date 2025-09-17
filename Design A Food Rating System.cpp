class FoodRatings {
    unordered_map<string,pair<string,int>>foodInfo;
    unordered_map<string,set<pair<int,string>>>cuisineMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0;i < foods.size();i++){
            foodInfo[foods[i]] = {cuisines[i],ratings[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = foodInfo[food];
        cuisineMap[cuisine].erase({-oldRating,food});
        cuisineMap[cuisine].insert({-newRating,food});
        oldRating = newRating;
    }
    
    string highestRated(string cuisine) {
        return  cuisineMap[cuisine].begin()->second;
    }
};
