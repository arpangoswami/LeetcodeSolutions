class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasTank = 0,sum = 0,ans = 0,n = gas.size();
        for(int i=0;i<n;i++){
            sum += (gas[i] - cost[i]);
            gasTank += (gas[i] - cost[i]);
            if(gasTank < 0){
                ans = i+1;
                gasTank = 0;
            }
        }
        return sum < 0 ? -1 : ans;
    }
};