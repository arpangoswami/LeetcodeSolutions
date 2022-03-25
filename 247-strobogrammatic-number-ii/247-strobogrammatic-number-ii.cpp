class Solution {
    int sz;
    void findAll(int i,string &possible,int j,vector<string> &ans){
        if((j-i+1) > sz){
            ans.push_back(possible);
            return;
        }
        
        reverse(possible.begin(),possible.end());
        possible.push_back('6');
        reverse(possible.begin(),possible.end());
        possible.push_back('9');
        
        findAll(i-1,possible,j+1,ans);
        
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        
        reverse(possible.begin(),possible.end());
        possible.push_back('9');
        reverse(possible.begin(),possible.end());
        possible.push_back('6');
        
        findAll(i-1,possible,j+1,ans);
        
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        
        reverse(possible.begin(),possible.end());
        possible.push_back('8');
        reverse(possible.begin(),possible.end());
        possible.push_back('8');
        
        findAll(i-1,possible,j+1,ans);
        
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        
        
        reverse(possible.begin(),possible.end());
        possible.push_back('0');
        reverse(possible.begin(),possible.end());
        possible.push_back('0');
        
        findAll(i-1,possible,j+1,ans);
        
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        
        reverse(possible.begin(),possible.end());
        possible.push_back('1');
        reverse(possible.begin(),possible.end());
        possible.push_back('1');
        
        findAll(i-1,possible,j+1,ans);
        
        possible.pop_back();
        reverse(possible.begin(),possible.end());
        possible.pop_back();
        reverse(possible.begin(),possible.end());
    }
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        if(n == 1){
            return {"0","1","8"};
        }
        sz = n;
        if(n % 2 == 1){
            string possible = "1";
            findAll(n/2-1,possible,n/2+1,ans);
            possible = "0";
            findAll(n/2-1,possible,n/2+1,ans);
            possible = "8";
            findAll(n/2-1,possible,n/2+1,ans);  
        }else{
            string possible = "";
            findAll(n/2-1,possible,n/2,ans);
        }
        vector<string> solution;
        for(string &x:ans){
            if(x[0] != '0'){
                solution.push_back(x);
            }
        }
        return solution;
    }
};