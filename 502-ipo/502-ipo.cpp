class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> pq;
        vector<pair<int,int>> project(n);
        for(int i=0;i<n;i++){
           project[i] = {capital[i],profits[i]}; 
        }
        sort(project.begin(),project.end());
        for(int i=0;i<n;i++){
            while(!pq.empty() && project[i].first > w && k > 0){
                w += pq.top();
                pq.pop();
                k--;
            }
            if(project[i].first <= w){
                pq.push(project[i].second);
            }
        }
        while(!pq.empty() && k > 0){
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};