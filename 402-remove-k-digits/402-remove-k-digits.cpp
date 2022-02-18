class Solution {
public:
    string removeKdigits(string s, int k) {
        if(s.size() == k || s == "0"){
            return "0";
        }
        stack<char> st;
        int N = s.size();
        st.push(s[0]);
        int removed = 0;
        for(int i=1;i<N;i++){
            while(!st.empty() && st.top() > s[i] && removed < k){
                st.pop();
                removed++;
            }
            st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() > (N-k)){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        while(ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans == ""){
            return "0";
        }
        return ans;
    }
};