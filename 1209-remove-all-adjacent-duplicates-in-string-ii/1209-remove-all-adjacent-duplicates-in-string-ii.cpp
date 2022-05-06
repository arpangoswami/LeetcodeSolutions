class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int N = s.size();
        if(N == 0){
            return "";
        }
        st.push({s[0],1});
        for(int i=1;i<N;i++){
            if(!st.empty() && s[i] == st.top().first){
                pair<char,int> v = st.top();
                st.pop();
                v.second += 1;
                st.push(v);
            }else{
                st.push({s[i],1});
            }
            if(st.top().second >= k){
                st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            pair<char,int> v = st.top();
            for(int i=0;i<v.second;i++){
                ans.push_back(v.first);
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};