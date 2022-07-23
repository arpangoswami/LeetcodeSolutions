class Solution {
public:
    int BIT[20001];
    const int MAX_SIZE = 20000;
    const int offset = 10000;
    int sum(int idx){
        int ans = 0;
        for(int i=idx;i>0;i-=(i&(-i))){
            ans += BIT[i];
        }
        return ans;
    }
    void update(int idx){
        for(int i=idx;i<=MAX_SIZE;i+=(i&(-i))){
            BIT[i]++;
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        memset(BIT,0,sizeof(BIT));
        vector<int> sol(n);
        for(int i=n-1;i>=0;i--){
            sol[i] = sum(nums[i]+offset);
            update(nums[i]+offset+1);
        }
        return sol;
    }
};