class Solution {
public:
    int minFlips(string s) {
        string newString = s + s;
        int n = s.size();
        int zeroOnes = 0, oneZeros = 0;
        for(int i=0;i<n;i++){
            if(i % 2 == 0){
                if(newString[i] == '1'){
                    zeroOnes++;
                }else{
                    oneZeros++;
                }
            }else{
                if(newString[i] == '0'){
                    zeroOnes++;
                }else{
                    oneZeros++;
                }
            }
        }
        int ans = min(zeroOnes, oneZeros);
        for(int i=n;i<(2*n - 1);i++){
            int prevIdx = i - n;
            if(prevIdx % 2 == 0){
                if(newString[prevIdx] == '1'){
                    zeroOnes--;
                }else{
                    oneZeros--;
                }
            }else{
                if(newString[prevIdx] == '0'){
                    zeroOnes--;
                }else{
                    oneZeros--;
                }
            }
            if(i % 2 == 0){
                if(newString[i] == '1'){
                    zeroOnes++;
                }else{
                    oneZeros++;
                }
            }else{
                if(newString[i] == '0'){
                    zeroOnes++;
                }else{
                    oneZeros++;
                }
            }
            ans = min({ans, zeroOnes, oneZeros});
        }
        return ans;
    }
};