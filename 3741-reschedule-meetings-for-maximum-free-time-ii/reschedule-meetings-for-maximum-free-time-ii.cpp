// class Solution {
// public:
//     int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
//         int N = startTime.size();
//         vector<int> freeTimeRight(N);
//         freeTimeRight[N-1] = eventTime - endTime.back();
//         for(int i=N-2;i>=0;i--){
//             freeTimeRight[i] = max(startTime[i+1] - endTime[i], freeTimeRight[i+1]);
//         }
//         int maxFreeTimeLeft = startTime[0];
//         int ans = 0;
//         for(int i=0;i<N;i++){
//             int prevEndTime = (i == 0) ? 0 : endTime[i-1];
//             int nextStartTime = (i == N-1) ? eventTime : startTime[i+1];
//             int duration = endTime[i] - startTime[i];
//             if(maxFreeTimeLeft >= duration || freeTimeRight[i] >= duration){
//                 ans = max(nextStartTime - prevEndTime, ans);
//             }
//             cout << "i: " << i << " ans: " << ans << '\n';
//             maxFreeTimeLeft = max(maxFreeTimeLeft, startTime[i] - prevEndTime);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<bool> q(n);
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
            if (endTime[i] - startTime[i] <= t1) {
                q[i] = true;
            }
            t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                q[n - i - 1] = true;
            }
            t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) -
                             endTime[n - i - 1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = i == 0 ? 0 : endTime[i - 1];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            if (q[i]) {
                res = max(res, right - left);
            } else {
                res = max(res, right - left - (endTime[i] - startTime[i]));
            }
        }
        return res;
    }
};