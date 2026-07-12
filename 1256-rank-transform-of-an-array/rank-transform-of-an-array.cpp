class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        unordered_map<int,int> rankMap;
        if(arr.size() == 0){
            return {};
        }
        rankMap[copy[0]] = 1;
        for(int i = 1;i<arr.size();i++){
            if(copy[i] > copy[i-1]){
                rankMap[copy[i]] = rankMap[copy[i-1]] + 1;
            }else{
                rankMap[copy[i]] = rankMap[copy[i-1]];
            }
        }
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[i] = rankMap[arr[i]];
        }
        return ans;
    }
};