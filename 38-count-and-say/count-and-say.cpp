class Solution {
    string say(string previous){
        string ans;
        char ch = previous[0];
        int count = 1,n = previous.size();
        for(int i=1;i<n;i++){
            if(previous[i] != ch){
                ans += to_string(count);
                ans.push_back(ch);
                count = 1;
                ch = previous[i];
            }else{
                count++;
            }
        }
        ans += to_string(count);
        ans.push_back(ch);
        return ans;
    }
public:
    string countAndSay(int n) {
        string prev = "1";
        for(int i=2;i<=n;i++){
            prev = say(prev);
            //cout<<"prev: "<<prev<<"\n";
        }
        return prev;
    }
};