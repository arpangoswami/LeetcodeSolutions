struct myCmp {
    bool operator()(pair<int,string> &p1, pair<int,string> &p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }
};
class FoodRatings {
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,myCmp>> cuisineMap;
    unordered_map<string,int> foodRating;
    unordered_map<string,string> cuisineFoodMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            foodRating[foods[i]] = ratings[i];
            cuisineMap[cuisines[i]].push({ratings[i],foods[i]});
            cuisineFoodMap[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        if(newRating > foodRating[food]){
            string cuisine = cuisineFoodMap[food];
            cuisineMap[cuisine].push({newRating,food});
        }
        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto &pq = cuisineMap[cuisine];
        while(pq.top().first != foodRating[pq.top().second]){
            pair<int,string> food = pq.top();
            int oldRating = food.first;
            int newRating = foodRating[food.second];
            string foodName = food.second;
            pq.pop();
            if(newRating < oldRating){
                pq.push({newRating,foodName});
            }
        }
        return pq.top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */