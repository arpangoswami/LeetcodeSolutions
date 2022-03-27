class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,int> freq;
        int n = adjacentPairs.size()+1;
        unordered_map<int,vector<int>> adj_list;
        
        for(auto &x:adjacentPairs){
            freq[x[0]]++;
            freq[x[1]]++;
            adj_list[x[0]].push_back(x[1]);
            adj_list[x[1]].push_back(x[0]);
        }
        int start;
        for(auto &it:freq){
            if(it.second == 1){
                start = it.first;
                break;
            }
        }
        vector<int> ans(n);
        ans[0] = start;
        for(int ptr=1;ptr < n;ptr++){
            int val = adj_list[ans[ptr-1]].back();
            adj_list[ans[ptr-1]].pop_back();
            if(ptr >= 2 && val == ans[ptr-2]){
                val = adj_list[ans[ptr-1]].back();
                adj_list[ans[ptr-1]].pop_back();
            }
            ans[ptr] = val;
        }
        return ans;
    }
};