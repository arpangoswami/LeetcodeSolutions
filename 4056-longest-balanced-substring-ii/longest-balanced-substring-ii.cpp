class Solution {
    int getMaxLengthSingleChar(string &s, char ch){
        int maxLength = 0, n = s.size();
        for(int i=0;i<n;){
            if(s[i] != ch){
                i++;
                continue;
            }
            int prev = i;
            while(i < n && s[i] == ch){
                i++;
            }
            maxLength = max(maxLength, i - prev);
        }
        return maxLength;
    }
    int getMaxLengthDoubleChar(string &s, char ch1, char ch2){
        int n = s.size(), maxLength = 0;
        // Diff can reach a max value of 2*n (if all values are ch1, because diff starts from n)
        // Diff can reach a min value of 0 (if all values are ch2, because diff starts from n)
        vector<int> first(2*n+1, -2);
        int diff = n, clearIdx = -1;
        first[diff] = -1;
        for(int i=0;i<n;i++){
            if(s[i] != ch1 && s[i] != ch2){
                clearIdx = i;
                diff = n;
                first[diff] = i; // Reset if we see the third character
            } else {
                if (s[i] == ch1){
                    diff++;
                }else{
                    diff--;
                }
                // This difference is not seen after reset
                if(first[diff] < clearIdx){
                    first[diff] = i;
                }else{
                    maxLength = max(maxLength, i - first[diff]);
                }
            }
        }
        return maxLength;
    }
    int getMaxLengthTripleChar(string &s, char ch1, char ch2, char ch3){
        long long state = LLONG_MAX/2;
        unordered_map<long long, int> first;
        first[state] = -1;
        int n = s.size(), maxLength = 0;
        for(int i=0;i<n;i++){
            // 1e6 + 1, 1e6, 1 are co prime integers.
            // we will get back to the previous state only if between currIdx i and previous state, the count of ch1,ch2 and ch3 are equal.
            if(s[i] == ch1){
                state += (1000001);
            }else if(s[i] == ch2){
                state -= (1000000);
            }else{
                state--;
            }
            if(first.count(state)){
                maxLength = max(maxLength, i - first[state]);
            }else{
                first[state] = i;
            }
        }
        return maxLength;
    }
public:
    int longestBalanced(string s) {
        int maxLength = max({getMaxLengthSingleChar(s, 'a'), getMaxLengthSingleChar(s, 'b'), getMaxLengthSingleChar(s, 'c')});
        maxLength = max(maxLength, max({getMaxLengthDoubleChar(s, 'a', 'b'), getMaxLengthDoubleChar(s, 'a', 'c'), getMaxLengthDoubleChar(s, 'c', 'b')}));
        maxLength = max(maxLength, getMaxLengthTripleChar(s, 'a', 'b', 'c'));
        return maxLength;
    }
};