unordered_set<char> vowels = {'a','e','i','o','u'};
class Solution {
public:
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> original;
        map<string,string> lowerCase;
        map<string,string> vowelChange;
        auto vowelDummy = [](string low){
            string temp;
            for(char c:low){
                if(vowels.count(c)){
                    temp.push_back('$');
                }else{
                    temp.push_back(c);
                }
            }
            return temp;
        };
        auto to_lower = [](string s){
            string temp;
            for(char c:s){
                temp.push_back(tolower(c));
            }
            return temp;
        };
        for(int i=0;i<(int)wordlist.size();i++){
            original.insert(wordlist[i]);
            string low = to_lower(wordlist[i]);
            if(lowerCase.count(low) == 0){
                lowerCase[low] = wordlist[i];
            }
            string temp = vowelDummy(low);
            if(vowelChange.count(temp) == 0)
                vowelChange[temp] = wordlist[i];
        }
        // for(auto it:lowerCase){
        //     cout<<it.first<<" "<<it.second<<'\n';
        // }
        // for(auto it:vowelChange){
        //     cout<<it.first<<" "<<it.second<<'\n';
        // }
        int n = queries.size();
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            string qAns = "";
            string low = to_lower(queries[i]);
            string vow = vowelDummy(low);
            //cout << "low: "<<low<<" vow: "<<vow<<'\n';
            if(original.count(queries[i])){
                qAns = queries[i];
            }
            else if(lowerCase.count(low)){
                qAns = lowerCase[low];
            }
            else if(vowelChange.count(vow)){
                qAns = vowelChange[vow];
            }
            ans[i] = qAns;
            //cout << "qAns: "<<qAns<<'\n';
        }
        // for(string s:ans){
        //     cout << s << " ";
        // }
        return ans;
    }
};