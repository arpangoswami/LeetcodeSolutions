class Solution {
public:
    string digitSum(string s, int k) {
        string copy = string(s.begin(), s.end());
        while(copy.size() > k){
            string temp;
            int ptr = 0;
            for(int i=0;i<copy.size();i+=k){
                int sum = 0;
                int limit = min(ptr*k+k, (int)copy.size());
                for(int j=ptr*k;j<limit;j++){
                    sum += (copy[j] - '0');
                }
                ptr++;
                temp += to_string(sum);
            }
            copy = temp;
        }
        return copy;
    }
};