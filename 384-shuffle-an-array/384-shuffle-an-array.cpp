class Solution {
    vector<int> original;
    vector<int> copy;
public:
    Solution(vector<int>& nums) {
        srand(time(0));
        int n = nums.size();
        original.resize(n);
        copy.resize(n);
        for(int i=0;i<n;i++){
            original[i] = nums[i];
            copy[i] = nums[i];
        }
    }
    int randRange(int low,int high){
        return low + rand() % (high - low);
    }
    vector<int> reset() {
        int n = original.size();
        for(int i=0;i<n;i++){
            original[i] = copy[i];
        }
        return original;
    }
    
    vector<int> shuffle() {
        int n = original.size();
        for(int i=0;i<n;i++){
            swap(original[i],original[randRange(i,n)]);
        }
        return original;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */