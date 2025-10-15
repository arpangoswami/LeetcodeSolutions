class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = -1e9;
        vector<int> modSums(k);
        for(int i=n-1;i>=0;i--){
            modSums[i % k] += energy[i];
            ans = max(ans, modSums[i%k]);
        }
        return ans;
    }
};