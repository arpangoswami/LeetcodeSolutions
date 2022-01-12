typedef long long ll;
class Solution {
    ll squareDist(vector<int> &v1,vector<int> &v2){
        ll diffX = v1[0]-v2[0],diffY = v1[1]-v2[1];
        return diffX*diffX + diffY*diffY;
    }
    void dfs1(int sv,vector<vector<int>> &adj_list,stack<int> &st,vector<bool> &visited){
        visited[sv] = true;
        for(int x:adj_list[sv]){
            if(!visited[x]){
                dfs1(x,adj_list,st,visited);
            }
        }
        st.push(sv);
    }
    void dfs2(int sv,vector<vector<int>> &adj_list,vector<bool> &visited,int &cnt){
        cnt++;
        visited[sv] = true;
        for(int x:adj_list[sv]){
            if(!visited[x]){
                dfs2(x,adj_list,visited,cnt);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj_list(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j != i){
                    ll dist = bombs[i][2];
                    if(squareDist(bombs[i],bombs[j]) <= dist*dist){
                        adj_list[i].push_back(j);
                    }
                }
            }
        }
        // stack<int> st;
        // vector<bool> visited(n);
        // for(int i=0;i<n;i++){
        //     if(!visited[i]){
        //         dfs1(i,adj_list,st,visited);
        //     }
        // }
        // int ans = 1;
        // fill(visited.begin(),visited.end(),false);
        // while(!st.empty()){
        //     int v = st.top();
        //     st.pop();
        //     if(!visited[v]){
        //         int cnt = 0;
        //         dfs2(v,adj_list,visited,cnt);
        //         ans = max(ans,cnt);
        //     }
        // }
        int ans = 1;
        for(int i=0;i<n;i++){
            vector<bool> visited(n);
            int cnt = 0;
            dfs2(i,adj_list,visited,cnt);
            ans = max(ans,cnt);
        }
        return ans;
    }
};