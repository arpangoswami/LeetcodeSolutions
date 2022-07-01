class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int> &v1,const vector<int> &v2){
            return v1[1] > v2[1];
        });
        int ans = 0;
        for(int i=0;i<boxTypes.size() && truckSize > 0;i++){
            int pick = min(boxTypes[i][0],truckSize);
            ans += pick*boxTypes[i][1];
            truckSize -= pick;
        }
        return ans;
    }
};