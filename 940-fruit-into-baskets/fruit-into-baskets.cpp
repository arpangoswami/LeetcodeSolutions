class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(),left = 0,ans = 0;
        unordered_map<int,queue<int>> indicesPicked;
        for(int i=0;i<n;i++){
            indicesPicked[fruits[i]].push(i);
            while(indicesPicked.size() > 2){
                indicesPicked[fruits[left]].pop();
                if(indicesPicked[fruits[left]].size() == 0){
                    indicesPicked.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};