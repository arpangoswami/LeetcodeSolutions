class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> lang;
        for(auto x:languages){
            for(int l:x){
                lang.insert(l);
            }
        }
        int m = languages.size();
        map<int,set<int>> mp;
        for(int i=1;i<=m;i++){
            vector<int> v = languages[i-1];
            for(int x:v){
                mp[i].insert(x);
            }
        }
        int N = friendships.size();
        unordered_set<int> dont;
        for(int i=0;i<N;i++){
            int f1 = friendships[i][0],f2 = friendships[i][1];
            bool f = false;
            for(int x:mp[f1]){
                if(mp[f2].count(x)){
                    f = true;
                }
            }
            if(f){
                dont.insert(i);
            }
        }
        int ans = m;
        for(int x:lang){
            unordered_set<int> taught;
            int curr = 0;
            for(int i=0;i<N;i++){
                if(dont.count(i)){
                    continue;
                }
                int l1 = friendships[i][0],l2 = friendships[i][1];
                if(mp[l1].count(x) == 0 && taught.count(l1) == 0){
                    curr++;
                    taught.insert(l1);
                }
                if(mp[l2].count(x) == 0 && taught.count(l2) == 0){
                    curr++;
                    taught.insert(l2);
                }
            }
            ans = min(ans,curr);
        }
        return ans;
    }
};