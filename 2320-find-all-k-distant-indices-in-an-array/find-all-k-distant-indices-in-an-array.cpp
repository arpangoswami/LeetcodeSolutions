class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int N = nums.size();
        for(int i=0;i<N;i++){
            if(nums[i] == key){
                int start = ans.size() == 0 ? max(0, i-k) : max(ans.back() + 1, i-k);
                int end = min(N-1, i+k);
                for(int j=start;j<=end;j++){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};