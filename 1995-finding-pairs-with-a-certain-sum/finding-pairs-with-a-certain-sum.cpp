class FindSumPairs {
    unordered_map<int,int> freqMap1;
    unordered_map<int,int> freqMap2;
    vector<int> nums1,nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int &x:nums1){
            freqMap1[x]++;
        }
        for(int &x:nums2){
            freqMap2[x]++;
        }
    }
    
    void add(int index, int val) {
        int present = nums2[index];
        freqMap2[present]--;
        int newVal = present + val;
        freqMap2[newVal]++;
        nums2[index] = newVal;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto &it:freqMap1){
            int otherFreq = freqMap2[tot - it.first];
            ans += (otherFreq * it.second);
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */