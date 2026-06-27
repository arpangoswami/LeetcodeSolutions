class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> freqMap;
        for(int x:nums){
            freqMap[x]++;
        }
        int ans = 1;
        if(freqMap.count(1)){
            ans = freqMap[1];
            if(ans % 2 == 0){
                ans--;
            }
        }
        freqMap.erase(1);
        for(auto it:freqMap){
            int currAns = 1;
            int req = sqrt(it.first);
            if(req * req != it.first){
                continue;
            }
            while(freqMap.count(req) && freqMap[req] >= 2){
                currAns += 2;
                int newReq = sqrt(req);
                if((newReq * newReq) != (req)){
                    break;
                }
                req = newReq;
            }
            ans = max(currAns, ans);
        }
        return ans;
    }
};