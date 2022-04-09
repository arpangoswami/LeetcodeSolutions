typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pii> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int> sol;
        for(int i=0;i<k;i++){
            pii temp = pq.top();
            pq.pop();
            sol.push_back(temp.second);
        }
        return sol;
    }
};