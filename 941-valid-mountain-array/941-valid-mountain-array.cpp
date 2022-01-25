class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i] < arr[i-1]){
                for(int j=i+1;j<n;j++){
                    if(arr[j] >= arr[j-1]){
                        return false;
                    }
                }
                return i > 1;
            }else if(arr[i] == arr[i-1]){
                return false;
            }
        }
        return false;
    }
};