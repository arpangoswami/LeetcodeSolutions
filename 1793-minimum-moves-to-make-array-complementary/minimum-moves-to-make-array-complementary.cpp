class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2*limit + 2);
        int n = nums.size(), mid = n/2;
        for(int i=0;i<mid;i++){
            int first = nums[i], second = nums[n-1-i];
            diff[min(first,second) + 1]--;
            diff[first+second]--;
            diff[first+second+1]++;
            diff[max(first,second) + limit + 1]++;
        }
        int ans = 2*mid;
        for(int i=1;i<=2*limit+1;i++){
            diff[i] += diff[i-1];
        }
        ans += *min_element(diff.begin()+2, diff.begin()+(2*limit+1));
        return ans;
    }
};