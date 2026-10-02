class Solution {
public:
    void allPar(vector<string> &sol,string &s,int left,int right,int n){
        if(right == n){
            sol.push_back(s);
            return;
        }
        if(left == right){
            s.push_back('(');
            allPar(sol,s,left+1,right,n);
            s.pop_back();
        }else if(left == n){
            s.push_back(')');
            allPar(sol,s,left,right+1,n);
            s.pop_back();
        }else{
            s.push_back('(');
            allPar(sol,s,left+1,right,n);
            s.pop_back();
            s.push_back(')');
            allPar(sol,s,left,right+1,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string s="";
        allPar(sol,s,0,0,n);
        return sol;
    }
};