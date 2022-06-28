class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequency(26);
        for(const char &c:s){
            frequency[c-'a']++;
        }
        vector<pair<int,char>> freqSort;
        for(int i=0;i<26;i++){
            if(frequency[i] > 0){
                freqSort.push_back({frequency[i],'a'+i});
            }
        }
        sort(freqSort.begin(),freqSort.end(),greater<pair<int,char>>());
        int ans = 0;
        unordered_set<int> st;
        for(auto &x:freqSort){
            if(!st.count(x.first)){
                st.insert(x.first);
            }else{
                int freq = x.first;
                while(st.count(freq) && freq > 0){
                    freq--;
                    ans++;
                }
                if(freq > 0){
                    st.insert(freq);
                }
            }
        }
        return ans;
    }
};