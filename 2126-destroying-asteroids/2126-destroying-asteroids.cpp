class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long total = mass;
        for(int x:asteroids){
            if(total >= x){
                total += (long long)x;
            }else{
                return false;
            }
        }
        return true;
    }
};