using ll = long long;
class Solution {
    bool checkValidity(unordered_map<int,int> &freq1, unordered_map<int,int> &freq2){
        for(auto &it:freq1){
            if((it.second + freq2[it.first]) & 1){
                return false;
            }
        }
        for(auto &it:freq2){
            if((it.second + freq1[it.first]) & 1){
                return false;
            }
        }
        return true;
    }
    void populateUnbalancedFreq(vector<int> &unbalancedFreq, unordered_map<int,int> &freq1,unordered_map<int,int> &freq2) {
        for(auto &it:freq1){
            if(it.second > freq2[it.first]){
                int diff = (it.second - freq2[it.first])/2;
                for(int i=0;i<diff;i++){
                    unbalancedFreq.push_back(it.first);
                }
            }
        }
        for(auto &it:freq2){
            if(it.second > freq1[it.first]){
                int diff = (it.second - freq1[it.first])/2;
                for(int i=0;i<diff;i++){
                    unbalancedFreq.push_back(it.first);
                }
            }
        }
    }
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> freq1,freq2;
        int min_val = INT_MAX;
        for(int &x:basket1){
            freq1[x]++;
            min_val = min(min_val, x);
        }
        for(int &x:basket2){
            freq2[x]++;
            min_val = min(min_val, x);
        }
        if(!checkValidity(freq1, freq2)){
            return -1;
        }
        vector<int> unbalancedFreq;
        populateUnbalancedFreq(unbalancedFreq, freq1, freq2);
        sort(unbalancedFreq.begin(), unbalancedFreq.end());
        int left = 0,right = (int)unbalancedFreq.size()-1;
        ll ans = 0;
        while(left <= right){
            ans += min(unbalancedFreq[left], 2*min_val);
            left++;
            right--;
        }
        return ans;
    }
};