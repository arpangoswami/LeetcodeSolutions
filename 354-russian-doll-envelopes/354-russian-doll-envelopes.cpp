class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &v1,vector<int> &v2){
           if(v1[0] == v2[0]){
               return v1[1] > v2[1];
           } 
            return v1[0] < v2[0];
        });
        auto cmp = [](auto &v1,auto &v2){
            return (v1[0] < v2[0] && v1[1] < v2[1]);
        };
        vector<vector<int>> lis;
        int n = envelopes.size();
        for(int i=0;i<n;i++){
            auto it = lower_bound(lis.begin(),lis.end(),envelopes[i],cmp);
            if(it == lis.end()){
                lis.push_back(envelopes[i]);
            }else{
                *it = envelopes[i];
            }
        }
        return lis.size();
    }
};
/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](auto &v1,auto &v2){
            if(v1[0] == v2[0]){
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        });
        auto cmp = [](auto &v1,auto &v2){
            return (v1[0] < v2[0] && v1[1] < v2[1]);
        };
        vector<vector<int>> lis;
        int n = envelopes.size();
        for(int i=0;i<n;i++){
            auto it = lower_bound(lis.begin(),lis.end(),envelopes[i],cmp);
            if(it == lis.end()){
                lis.push_back(envelopes[i]);
            }else{
                *it = envelopes[i];
            }
        }
        return lis.size();
    }
};
*/