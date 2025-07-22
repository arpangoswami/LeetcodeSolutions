class Solution {
public:
    string makeFancyString(string s) {
        char last = '#';
        int lastFreq = 0;
        string ans;
        for(char ch:s){
            if(ch != last){
                lastFreq = 1;
                ans.push_back(ch);
            }else{
                lastFreq++;
                ans.push_back(ch);
                if(lastFreq >= 3){
                    lastFreq--;
                    ans.pop_back();
                }
            }
            last = ch;
        }
        return ans;
    }
};