/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> arr;
    int i;
    NestedIterator(vector<NestedInteger> &nestedList) {
        i = 0;
        rec(nestedList);
    }
    void rec(vector<NestedInteger> &nestedList){
        for(NestedInteger x:nestedList){
            if(x.isInteger()){
                int v = x.getInteger();
                arr.push_back(v);
            }else{
                vector<NestedInteger> v = x.getList();
                if(v.size())
                    rec(v);
            }
        }
    }
    int next() {
        return arr[i++];
    }
    
    bool hasNext() {
        return i < arr.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */