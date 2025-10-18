class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int last = nums[0] - k;
        int distinct = 1;
        for(int i=1;i<n;i++){
            int minRange = nums[i] - k,maxRange = nums[i] + k;
            if(last < minRange){
                last = minRange;
                distinct++;
            }else if(last < maxRange){
                last = last+1;
                distinct++;
            }
        }
        return distinct;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();