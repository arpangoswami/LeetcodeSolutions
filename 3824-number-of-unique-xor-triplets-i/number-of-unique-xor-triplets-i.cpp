class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int steps = 0;
        while(n > 0){
            steps++;
            n /= 2;
        }
        return (1 << steps);
    }
};