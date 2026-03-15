class Solution {
public:
    string getHappyString(int n, int k) {
        if (k > 3 * (1 << (n-1))){
            return "";
        }
        string ans;
        int blockSize = 1 << (n-1);
        ans += ('a' + (k - 1)/blockSize);
        k = (k-1)%blockSize + 1;
        for(int i=1;i<n;i++){
            blockSize >>= 1;
            vector<char> choices;
            for(char ch: {'a', 'b', 'c'}){
                if(ch == ans.back()){
                    continue;
                }
                choices.push_back(ch);
            }
            if(k <= blockSize){
                ans += choices[0];
            }else{
                k -= blockSize;
                ans += choices[1];
            }
        }
        return ans;
    }
};