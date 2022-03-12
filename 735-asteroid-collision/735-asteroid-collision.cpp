class Solution {
public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
        
//     }
    vector<int> asteroidCollision(vector<int> arr){
        int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                ans.push_back(arr[i]);
            }else{
                while(ans.size() > 0 && ans.back() > 0 && ans.back() < -arr[i]){
                    ans.pop_back();
                }
                if(ans.size() > 0 && ans.back() > 0 && ans.back() == -arr[i]){
                    ans.pop_back();
                }else if(!(ans.size() > 0 && ans.back() > 0 && ans.back() > -arr[i])){
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
};