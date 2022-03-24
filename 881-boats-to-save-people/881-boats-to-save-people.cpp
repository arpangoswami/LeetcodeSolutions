class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size(),j = n-1,i = 0;
        int ans = 0;
        while(i <= j){
            if(i == j){
                ans++;
                i++;
            }
            else if(people[i] + people[j] <= limit){
                ans++;
                i++;
                j--;
            }else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};