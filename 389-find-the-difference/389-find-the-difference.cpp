class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int N = s.size();
        for(int i=0;i<N;i++){
            if(s[i] != t[i]){
                return t[i];
            }
        }
        return t[N];
    }
};