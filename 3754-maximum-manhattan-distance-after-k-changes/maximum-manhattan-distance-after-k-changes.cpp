class Solution {
    int getMaxManhattanDistance(vector<int> &dir, int k){
        int upDownChange = min(dir[0],dir[1]), alreadyUpDown = max(dir[0],dir[1]) - upDownChange;
        int sidewaysChange = min(dir[2],dir[3]), alreadySideways = max(dir[2],dir[3]) - sidewaysChange;
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
        vector<int> dir(4);
        for(int i=0;i<N;i++){
            switch(s[i]) {
                case 'N':
                    dir[0]++;
                    break;
                case 'S':
                    dir[1]++;
                    break;
                case 'E':
                    dir[2]++;
                    break;
                case 'W':
                    dir[3]++;
                    break;
                default:
                    throw runtime_error("Other values not allowed");
            }
            ans = max(ans, getMaxManhattanDistance(dir, k));
        }
        return ans;
    }
};