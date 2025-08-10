// class Solution {
//     bool allCombinations(string &str, int idx){
//         if(idx == str.size()){
//             return false;
//         }
//         int num = stoi(str);
//         string copy = to_string(num);
//         if(copy.size() < str.size())
//     }
// public:
//     bool reorderedPowerOf2(int n) {
//         string str = to_string(n);
//         return allCombinations(str, 0);
//     }
// };


class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s = to_string(N);
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        int num = stoi(s);
        int power = 1;
        vector<int> freq(10);
        for(char c:s){
            freq[c - '0']++;
        }
        vector<vector<int>> st;
        while(power <= num){
            string temp = to_string(power);
            vector<int> f(10);
            for(char c:temp){
                f[c-'0']++;
            }
            st.push_back(f);
            power *= 2;
        }
        for(auto x:st){
            bool f = true;
            for(int i=0;i<10;i++){
                if(x[i] != freq[i]){
                    f = false;
                    break;
                }
            }
            if(f){
                return true;
            }
        }
        return false;
    }
};