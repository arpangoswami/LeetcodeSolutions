class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for(int i=0;i<n;i++){
            int leftIdx = (startIndex - i + n)%n;
            int rightIdx = (startIndex + i)%n;
            if(words[leftIdx] == target || words[rightIdx] == target){
                return i;
            }
        }
        return -1;
    }
};