class Solution {
    int largestRectangleInHistogram(vector<int> &arr){
        stack<int> histogram;
        histogram.push(0);
        int ans = 0,n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i] >= arr[histogram.top()]){
                histogram.push(i);
            }else{
                while(!histogram.empty() && arr[i] < arr[histogram.top()]){
                    int idx = histogram.top();
                    histogram.pop();
                    if(histogram.empty()){
                        int area = arr[idx]*i;
                        ans = max(ans,area);    
                    }else{
                        int area = arr[idx]*(i-histogram.top()-1);
                        ans = max(ans,area);
                    }
                }
                histogram.push(i);
            }
        }
        while(!histogram.empty()){
            int idx = histogram.top();
            histogram.pop();
            if(histogram.empty()){
                int area = arr[idx]*n;
                ans = max(ans,area);    
            }else{
                int area = arr[idx]*(n-histogram.top()-1);
                ans = max(ans,area);
            }
        }
        return ans;
    }
    void modify(vector<int> &arr,vector<char> &histogram){
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(histogram[i] == '0'){
                arr[i] = 0;
            }else{
                arr[i]++;
            }
        }
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        if(n == 0){
            return 0;
        }
        vector<int> arr(n);
        modify(arr,matrix[0]);
        int ans = largestRectangleInHistogram(arr);
        for(int i=1;i<m;i++){
            modify(arr,matrix[i]);
            ans = max(ans,largestRectangleInHistogram(arr));
        }
        return ans;
    }
};