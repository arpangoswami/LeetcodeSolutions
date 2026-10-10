class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int N = nums1.size(), mx = 0;
        long long k = (long long)k1 + k2;
        vector<long long> cnt(100002);
        for(int i=0;i<N;i++){
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            mx = max(mx, d);
        }
        for(int v = mx;v >= 1 && k > 0;v--){
            if(cnt[v] == 0){
                continue;
            }
            long long move = min(k, cnt[v]);
            cnt[v] -= move;
            cnt[v-1] += move;
            k -= move;
        }
        long long ans = 0;
        for(long long v = 0; v <= mx; v++){
            ans += cnt[v] * v * v;
        }
        return ans;
    }
};