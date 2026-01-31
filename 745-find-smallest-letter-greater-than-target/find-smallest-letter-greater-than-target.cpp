class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        set<char> st(letters.begin(),letters.end());
        auto it = st.upper_bound(target);
        return it == st.end() ? ans : *it;
    }
};