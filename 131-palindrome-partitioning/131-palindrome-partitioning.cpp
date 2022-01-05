class Solution {
    bool isPalindrome(string &s,int start,int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void allPossible(vector<vector<string>> &sol,vector<string> &possible,string &s,int idx){
        int N = s.size();
        if(idx >= N){
            sol.push_back(possible);
            return;
        }
        for(int i=idx;i<N;i++){
            if(isPalindrome(s,idx,i)){
                possible.push_back(s.substr(idx,i-idx+1));
                allPossible(sol,possible,s,i+1);
                possible.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol;
        vector<string> possible;
        allPossible(sol,possible,s,0);
        return sol;
    }
};