class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> hist;
        hist.push(0);
        int maxArea = 0;
        for(int i=1;i<n;i++){
            while(!hist.empty() && arr[i] < arr[hist.top()]){
                int tpIdx = hist.top();
                hist.pop();
                if(hist.empty()){
                    maxArea = max(maxArea,i*arr[tpIdx]);
                }else{
                    maxArea = max(maxArea,(i-hist.top()-1)*arr[tpIdx]);
                }
            }
            hist.push(i);
        }
        while(!hist.empty()){
            int tpIdx = hist.top();
            hist.pop();
            if(hist.empty()){
                maxArea = max(maxArea,n*arr[tpIdx]);
            }else{
                maxArea = max(maxArea,(n-hist.top()-1)*arr[tpIdx]);
            }
        }
        return maxArea;
    }
};