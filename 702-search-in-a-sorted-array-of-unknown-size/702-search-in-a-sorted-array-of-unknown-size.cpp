/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0,high = 9999;
        while(low <= high){
            int mid = (low+high)/2;
            int val = reader.get(mid);
            if(val == target){
                return mid;
            }else if(val > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};