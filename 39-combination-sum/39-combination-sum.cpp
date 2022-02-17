class Solution {
public:
    void allCombinations(vector<vector<int>> &sol,vector<int> &temp,vector<int> &candidates,int target,int idx){
        // if(idx == sol.size()){
        //     return;
        // }
        if(target == 0){
            sol.push_back(temp);
            return;
        }
        for(int i=idx;i<(int)candidates.size() && candidates[i] <= target;i++){
            temp.push_back(candidates[i]);
            allCombinations(sol,temp,candidates,target - candidates[i],i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> sol;
        vector<int> temp;
        allCombinations(sol,temp,candidates,target,0);
        return sol;
    }
};