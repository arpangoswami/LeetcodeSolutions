class Solution {
    int check(string &answerKey,char ch,int k){
        int ans = 0,currWindowOther = 0,left = 0,n = answerKey.size();
        for(int i=0;i<n;i++){
            if(answerKey[i] == ch){
                currWindowOther++;
            }
            while(currWindowOther > k){
                if(answerKey[left] == ch){
                    currWindowOther--;
                }
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = check(answerKey,'F',k);
        ans = max(ans,check(answerKey,'T',k));
        return ans;
    }
};