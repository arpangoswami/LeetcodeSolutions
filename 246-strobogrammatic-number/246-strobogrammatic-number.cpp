class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<int,int> mp;
        mp[1] = 1;
        mp[6] = 9;
        mp[9] = 6;
        mp[8] = 8;
        mp[0] = 0;
        int n = num.size();
        for(int i=0;i<n;i++){
            int other = num[n-i-1] - '0';
            if(mp[num[i] - '0'] != other){
                return false;
            } 
        }
        return true;
    }
};