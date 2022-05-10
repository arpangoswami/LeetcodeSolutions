class Solution {
public:
    void allPossibleCombs(int num,vector<vector<int>> &sol,vector<int> &temp,int k,int sum){
        if(k == 0){
            if(sum == 0){
                sol.push_back(temp);
            }
            return;
        }
        if(num > 9){
            return;
        }
        if(sum < num){
            return;
        }
        temp.push_back(num);
        allPossibleCombs(num+1,sol,temp,k-1,sum-num);
        temp.pop_back();
        allPossibleCombs(num+1,sol,temp,k,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sol;
        if((k*(k+1))/2 > n){
            return sol;
        }
        vector<int> temp;
        allPossibleCombs(1,sol,temp,k,n);
        return sol;
    }
};