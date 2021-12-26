int calculateSquareDistance(pair<int,int> &p1){
    int dist = p1.first*p1.first+p1.second*p1.second;
    return dist;
}
class Solution {
    struct comparison{
        bool operator()(pair<int,int> &p1,pair<int,int> &p2){
            int dist1 = calculateSquareDistance(p1);
            int dist2 = calculateSquareDistance(p2);
            return dist1 < dist2;
        }  
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparison> pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            if(pq.size() < k){
                pq.push({points[i][0],points[i][1]});
            }else{
                pair<int,int> temp1 = pq.top();
                pair<int,int> temp2 = {points[i][0],points[i][1]};
                int d1 = calculateSquareDistance(temp1);
                int d2 = calculateSquareDistance(temp2);
                if(d1 > d2){
                    pq.pop();
                    pq.push(temp2);
                }
            }
        }
        vector<vector<int>> solution;
        while(!pq.empty()){
            vector<int> v = {pq.top().first,pq.top().second};
            solution.push_back(v);
            pq.pop();
        }
        return solution;
    }
};