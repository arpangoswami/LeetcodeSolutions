class Solution {
    int binSearch(vector<int> &arr,int n){
        int low = 0,high = n-1,ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == 0){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        if(m == 0){
            return {};
        }
        int n = mat[0].size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<m;i++){
            int soldiers = binSearch(mat[i],n);
            if(pq.size() < k){
                pq.push({soldiers,i});
            }else if(soldiers < pq.top().first){
                pq.pop();
                pq.push({soldiers,i});
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};