class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int n1 = a.size(),n2 = b.size(),i = n1-1,j = n2-1,carry = 0;
        while(i >= 0 && j >= 0){
            int sum = a[i] - '0' + b[j] - '0' + carry;
            int val = sum%2;
            carry = sum / 2;
            ans.push_back(val+'0');
            i--;
            j--;
        }
        while(i >= 0){
            int sum = a[i] - '0' + carry;
            int val = sum%2;
            carry = sum / 2;
            ans.push_back(val+'0');
            i--;
        }
        while(j >= 0){
            int sum = b[j] - '0' + carry;
            int val = sum%2;
            carry = sum / 2;
            ans.push_back(val+'0');
            j--;
        }
        if(carry){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};