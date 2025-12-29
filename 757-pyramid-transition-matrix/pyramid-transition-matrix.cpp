class Solution {
    bool recSolve(string &bottom, unordered_map<string, bitset<6>> &prefixPairs, unordered_set<string> &badRows){
        if(bottom.size() == 1){
            return true;
        }
        if(badRows.count(bottom)){
            return false;
        }
        if(buildNextRow(bottom, "", 0, prefixPairs, badRows)){
            return true;
        }
        badRows.insert(bottom);
        return false;
    }
    bool buildNextRow(string &bottom, string nextRow, int idx, unordered_map<string, bitset<6>> &prefixPairs, unordered_set<string> &badRows){
        if(idx == bottom.size() - 1){
            return recSolve(nextRow, prefixPairs, badRows);
        }
        string key = bottom.substr(idx,2);
        if(!prefixPairs.count(key)){
            return false;
        }
        for(char ch='A';ch<='F';ch++){
            if(prefixPairs[key][ch - 'A']){
                nextRow.push_back(ch);
                if(buildNextRow(bottom, nextRow, idx+1, prefixPairs, badRows)){
                    return true;
                }
                nextRow.pop_back();
            }
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, bitset<6>> prefixPairs;
        for(string &s:allowed){
            prefixPairs[s.substr(0,2)][s[2] - 'A'] = 1;
        }
        unordered_set<string> badRows;
        return recSolve(bottom, prefixPairs, badRows);
    }
};