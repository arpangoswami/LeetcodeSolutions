class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int ptr = 0,n = pushed.size();
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty() && ptr < n && st.top() == popped[ptr]){
                st.pop();
                ptr++;
            }
        }
        return st.empty() && ptr == n;
    }
};