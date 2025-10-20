#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    std::less_equal<int>, // <--- Uses 'less_equal' for multiset (duplicate elements) behavior
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_multiset;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        ordered_multiset mset;
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for(int i=0;i<k;i++){
            if(nums[i] < 0){
                mset.insert(nums[i]);
            }
        }
        for(int i=k;i<n;i++){
            if(mset.size() >= x){
                int N = mset.size();
                ans[i-k] = *mset.find_by_order(x-1);
            }else{
                ans[i-k] = 0;
            }
            if(nums[i-k] < 0){
                int rank_of_first_instance = mset.order_of_key(nums[i-k]);
                // 2. Get an iterator to the element at that rank.
                auto it_to_erase = mset.find_by_order(rank_of_first_instance);
                // 3. Verify the element is present at the calculated rank before erasing.
                // This is a safety check to ensure we don't erase an element we shouldn't.
                if (it_to_erase != mset.end() && *it_to_erase == nums[i-k]) {
                    mset.erase(it_to_erase); 
                }
            }
            if(nums[i] < 0){
                mset.insert(nums[i]);
            }
        }
        if(mset.size() >= x){
            int N = mset.size();
            ans[n-k] = *mset.find_by_order(x-1);
        }else{
            ans[n-k] = 0;
        }
        return ans;
    }
};