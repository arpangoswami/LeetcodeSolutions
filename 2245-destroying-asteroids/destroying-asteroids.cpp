class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        //long long total = mass;
        for(int x:asteroids){
            if(mass >= 100000){
                return true;
            }
            if(mass >= x){
                mass += x;
            }else{
                return false;
            }
        }
        return true;
    }
};