class Solution {
    bool replaceOnce(int i,string &s,string &t,int ops){
        if(i == s.size() && i == t.size()){
            return ops == 0;
        }
        if(s[i] == t[i]){
            return replaceOnce(i+1,s,t,ops);
        }else if(ops > 0){
            return replaceOnce(i+1,s,t,ops-1);
        }
        return false;
    }
    bool deleteOnce(int i,string &s,int j,string &t,int ops){
        //cout<<i<<" "<<j<<" "<<ops<<"\n";
        if(i == s.size()){
            if((j == t.size() && ops == 0) || (j == (int)t.size()-1 && ops > 0)){
                return true;
            }
            return false;
        }
        if(s[i] == t[j]){
            return deleteOnce(i+1,s,j+1,t,ops);
        }else if(ops > 0){
            return deleteOnce(i,s,j+1,t,ops-1);
        }
        return false;
    }
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() > t.size()){
            return isOneEditDistance(t,s);
        }
        if(s.size() == t.size()){
            return replaceOnce(0,s,t,1);
        }else if(1+s.size() == t.size()){
            return deleteOnce(0,s,0,t,1);
        }
        return false;
    }
};