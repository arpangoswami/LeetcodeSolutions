class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // int n = s1.size(), n2 = s2.size();
        // if(n != n2){
        //     return false;
        // }
        // vector<int> oddFreq(26), evenFreq(26);
        // for(int i=0;i<n;i+=2){
        //     evenFreq[s1[i] - 'a']++;
        //     evenFreq[s2[i] - 'a']--;
        // }
        // for(int i=1;i<n;i+=2){
        //     oddFreq[s1[i] - 'a']++;
        //     oddFreq[s2[i] - 'a']--;
        // }
        // for(int i=0;i<26;i++){
        //     if(oddFreq[i] || evenFreq[i]){
        //         return false;
        //     }
        // }
        // return true;
        if(s1 == s2){
            return true;
        }
        swap(s1[0], s1[2]);
        if(s1 == s2){
            return true;
        }
        swap(s1[1], s1[3]);
        if(s1 == s2){
            return true;
        }
        swap(s1[0], s1[2]);
        if(s1 == s2){
            return true;
        }
        return false;
    }
};