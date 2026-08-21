// using ll = long long;
// class Solution {
//     bool check(ll num, int k, vector<int> &coins){
//         ll total = 0;
//         for(int x:coins){
//             total += (num/x);
//             if(total >= k){
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     long long findKthSmallest(vector<int>& coins, int k) {
//         sort(coins.begin(), coins.end());
//         ll high = *min_element(coins.begin(), coins.end())*k, low = 1, ans = high;
//         while(low <= high){
//             ll mid = (low + high)/2;
//             if(check(mid,k,coins)){
//                 ans = mid;
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        ranges::sort(coins);
        vector<int> A;

        for (auto& c : coins)
            if (ranges::none_of(A, [&](int x) { return !(c % x); }))
                A.push_back(c);

        int n = A.size();

        auto check = [&](ll mid) {
            ll tot = 0;
            for (int i = 1; i <= n; i++) {
                int q = (1 << i) - 1;

                while (q < 1 << n) {
                    ll x = 1;
                    for (int j = 0; j < n; j++)
                        if ((q >> j) & 1)
                            x = lcm(x, A[j]);

                    tot += (mid / x) * (((i & 1) << 1) - 1);

                    int c = q & -q;
                    int r = q + c;
                    q = (((r ^ q) >> 2) / c) | r;
                }
            }
            return tot >= k;
        };

        ll low = k, high = 1ll * A[0] * k;
        return *ranges::lower_bound(views::iota(low, high + 1), true, {},
                                    [&](ll mid) { return check(mid); });
    }
};