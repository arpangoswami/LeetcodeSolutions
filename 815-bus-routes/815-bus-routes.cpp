class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        int N = routes.size();
        int maxm = 0;
        for(vector<int> &v:routes){
            maxm = max(maxm,*max_element(v.begin(),v.end()));
        }
        vector<bool> busStops(maxm+1);
        vector<bool> buses(N+1);
        vector<vector<int>> busesRelatedToStops(maxm+1);
        for(int i=0;i<N;i++){
            for(int x:routes[i]){
                busesRelatedToStops[x].push_back(i);
            }
        }
        queue<int> q;
        q.push(source);
        busStops[source] = true;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz > 0){
                int src = q.front();
                q.pop();
                sz--;
                if(src == target){
                    return lvl;
                }
                vector<int> &v = busesRelatedToStops[src];
                for(int x:v){
                    if(!buses[x]){
                        vector<int> &stopsReachable = routes[x];
                        for(int &y:stopsReachable){
                            if(!busStops[y]){
                                q.push(y);
                                busStops[y] = true;
                            }
                        }
                        buses[x] = true;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};