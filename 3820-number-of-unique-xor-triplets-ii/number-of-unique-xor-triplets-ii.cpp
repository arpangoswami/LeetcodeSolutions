class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        bitset<2048> pairXor,tripleXor;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pairXor[nums[i] ^ nums[j]] = 1;
            }
        }
        for(int i=0;i<2048;i++){
            if(!pairXor[i]){
                continue;
            }
            for(int j=0;j<n;j++){
                tripleXor[i ^ nums[j]] = 1;
            }
        }
        return tripleXor.count();
    }
};