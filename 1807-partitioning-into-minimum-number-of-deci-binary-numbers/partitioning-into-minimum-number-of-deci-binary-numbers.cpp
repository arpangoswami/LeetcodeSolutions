class Solution {
public:
    int minPartitions(string n) {
        char maxChar = '0';
        for(char &c:n){
            if(c > maxChar){
                maxChar = c;
            }
        }
        return maxChar - '0';
    }
};