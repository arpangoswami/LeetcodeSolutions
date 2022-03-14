class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        string s;
        vector<string> paths;
        while(getline(iss,s,'/')){
            if(s == ".."){
                if(paths.size() > 0){
                    paths.pop_back();
                }
            }else if(s != "." && s.size() > 0){
                paths.push_back(s);
            }
        }
        string ans = "/";
        int N = paths.size();
        for(int i=0;i<N;i++){
            if(paths[i].size() > 0){
                ans += paths[i];
                if(i < (N-1)){
                    ans.push_back('/');
                }
            }
        }
        while(ans.back() == '/'){
            ans.pop_back();
        }
        if(ans.size() == 0){
            return "/";
        }
        return ans;
    }
};