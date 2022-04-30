class Solution {
    void dfs(string source,string destination,double &ans,double tillNow,unordered_set<string> &visited,unordered_map<string,vector<pair<string,double>>> &adj_list){
        visited.insert(source);
        if(source == destination){
            ans = tillNow;
            return;
        }
        for(pair<string,double> &value:adj_list[source]){
            if(!visited.count(value.first)){
                dfs(value.first,destination,ans,tillNow*value.second,visited,adj_list);
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj_list;
        int N = equations.size();
        for(int i=0;i<N;i++){
            string first = equations[i][0],second = equations[i][1];
            adj_list[first].push_back({second,values[i]});
            adj_list[second].push_back({first,1.00/values[i]});
        }
        vector<double> solution;
        for(vector<string> &v:queries){
            unordered_set<string> visited;
            double ans = -1.00;
            if(adj_list.count(v[0])){
                dfs(v[0],v[1],ans,1.00,visited,adj_list);
            }
            solution.push_back(ans);
        }
        return solution;
    }
};