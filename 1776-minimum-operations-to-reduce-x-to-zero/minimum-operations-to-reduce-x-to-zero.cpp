class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefix(n+1),suffix(n+1);
        prefix[0] = 0;
        suffix[0] = 0;
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            suffix[n-i] = suffix[n-i-1] + nums[i];
        }
        int ans = (n+1);
        for(int i=1;i<=n;i++){
            if(prefix[i] > x){
                break;
            }
            else if(prefix[i] < x){
                int n1 = i;
                auto it = lower_bound(suffix.begin(),suffix.end(),x-prefix[i]);
                if(it != suffix.end()){
                    int n2 = it - suffix.begin();
                    if(suffix[n2] + prefix[i] == x){
                        ans = min(ans,n1 + n2);
                    }
                }
                
            }else{
                ans = min(ans,i);
            }
        }
        for(int i=1;i<=n;i++){
            if(suffix[i] > x){
                break;
            }
            else if(suffix[i] < x){
                int n1 = i;
                auto it = lower_bound(prefix.begin(),prefix.end(),x-suffix[i]);
                if(it != prefix.end()){
                   int n2 = it - prefix.begin();
                    if(prefix[n2] + suffix[i] == x){
                        ans = min(ans,n1 + n2);
                    } 
                }
            }else{
                ans = min(ans,i);
            }
        }
        return (ans == (n+1) ? -1 : ans);
    }
};