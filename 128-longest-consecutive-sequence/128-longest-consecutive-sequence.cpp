class Solution {
public:
    int find(int x,unordered_map<int,int> &parent){
        if(parent[x] == x){
            return x;
        }
        parent[x] = find(parent[x],parent);
        return parent[x];
    }
    void unionRank(int x,int y,unordered_map<int,int> &parent,unordered_map<int,int> &rank){
        int x_rep = find(x,parent),y_rep = find(y,parent);
        if(x_rep == y_rep){
            return;
        }
        if(rank[x_rep]>rank[y_rep]){
            parent[y_rep] = x_rep;
        }
        else if(rank[x_rep]<rank[y_rep]){
            parent[x_rep] = y_rep;
        }
        else{
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
    int longestConsecutive(vector<int>& nums) {
        //if(nums.size()==0) return 0;
        unordered_map<int,int> parent;
        unordered_map<int,int> rank;
        for(int i=0;i<nums.size();i++){
            parent[nums[i]] = nums[i];
            rank[nums[i]] = 1;
        }
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end() && s.find(nums[i]+1)==s.end()){
                s.insert(nums[i]);
            }
            else if(s.find(nums[i]-1)!=s.end() && s.find(nums[i]+1)!=s.end()){
                unionRank(nums[i],nums[i]-1,parent,rank);
                unionRank(nums[i],nums[i]+1,parent,rank);
                s.insert(nums[i]);
            }
            else if(s.find(nums[i]-1)==s.end() && s.find(nums[i]+1)!=s.end()){
                unionRank(nums[i],nums[i]+1,parent,rank);
                s.insert(nums[i]);
            }
            else if(s.find(nums[i]-1)!=s.end() && s.find(nums[i]+1)==s.end()){
                unionRank(nums[i],nums[i]-1,parent,rank);
                s.insert(nums[i]);
            }
        }
        unordered_map<int,int> parentOf;
        for(auto i=s.begin();i!=s.end();i++){
            parentOf[find(*i,parent)]++;
        }
        int maxi = 0;
        for(auto i=parentOf.begin();i!=parentOf.end();i++){
            maxi = max(maxi,i->second);
        }
        return maxi;
    }
};