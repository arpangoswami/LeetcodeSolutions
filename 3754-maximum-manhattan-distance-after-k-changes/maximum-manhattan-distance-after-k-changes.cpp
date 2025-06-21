class Solution {
    int getMaxManhattanDistance(unordered_map<char,int> &mp, int k){
        int upDownChange = min(mp['N'],mp['S']), alreadyUpDown = max(mp['N'],mp['S']) - upDownChange;
        int sidewaysChange = min(mp['E'],mp['W']), alreadySideways = max(mp['E'],mp['W']) - sidewaysChange;
        int change = 0;
        if(upDownChange <= k){
            change += 2*upDownChange;
            k -= upDownChange;
        }else{
            change += 2*k;
            return alreadyUpDown + alreadySideways + change;
        }
        if(sidewaysChange <= k){
            change += 2*sidewaysChange;
            k -= sidewaysChange;
        } else {
            change += 2*k;
        }
        return alreadyUpDown + alreadySideways + change;
    }
public:
    int maxDistance(string s, int k) {
        unordered_map<char,int> mp;
        int N = s.size();
        int ans = 0;
        for(int i=0;i<N;i++){
            mp[s[i]]++;
            ans = max(ans, getMaxManhattanDistance(mp, k));
        }
        return ans;
    }
};