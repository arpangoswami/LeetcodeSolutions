class Solution {

public:
    int rotatedDigits(int n) {
        int ans = 0;
        vector<char> mapping(10, '$');
        mapping[0] = '0';
        mapping[1] = '1';
        mapping[2] = '5';
        mapping[5] = '2';
        mapping[6] = '9';
        mapping[8] = '8';
        mapping[9] = '6';
        for(int i=1;i<=n;i++){
            string s = to_string(i);
            bool valid = true;
            string rotated;
            for(char &ch:s){
                if(mapping[ch - '0'] == '$'){
                    valid = false;
                    break;
                }
                rotated.push_back(mapping[ch - '0']);
            }
            if(valid && stoi(rotated) != i){
                ans++;
            }
        }
        return ans;
    }
};