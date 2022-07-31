class BIT{
    vector<int> fenwick;
    int n;
    public:
    BIT(){
        n = 0;
    }
    BIT(vector<int> &nums){
        int _n = nums.size();
        n = _n;
        fenwick.resize(n+1);
        fill(fenwick.begin(),fenwick.end(),0);
        for(int i=1;i<=n;i++){
            update(i,nums[i-1]);
        }
    }
    void update(int idx,int val){
        for(;idx<=n;idx+=(idx&(-idx))){
            fenwick[idx] += val;
        }
    }
    int sum(int idx){
        int ans = 0;
        for(;idx>0;idx-=(idx&(-idx))){
            ans += fenwick[idx];
        }
        return ans;
    }
    int sumRange(int left,int right){
        return sum(right)-sum(left-1);
    }
};

class NumArray {
    vector<int> tillNow;
    BIT bit;
public:
    NumArray(vector<int>& nums) {
        tillNow = nums;
        bit = BIT(nums);
    }
    void update(int index, int val) {
        int prevVal = tillNow[index];
        bit.update(index+1,val-prevVal);
        tillNow[index] = val;
    }
    
    int sumRange(int left, int right) {
        return bit.sumRange(left+1,right+1);   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */