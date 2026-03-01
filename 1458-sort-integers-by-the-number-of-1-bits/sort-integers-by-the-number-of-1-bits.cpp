class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int,int> numOnes;
        for(int &x:arr){
            numOnes[x] = __builtin_popcount(x);
        }
        sort(arr.begin(), arr.end(), [&](int x,int y){
            if(numOnes[x] == numOnes[y]){
                return (x < y);
            }
            return numOnes[x] < numOnes[y];
        });
        return arr;
    }
};