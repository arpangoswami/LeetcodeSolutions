typedef long long ll;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        //Declaring a max heap of the array
        priority_queue<ll> maxHeap(target.begin(),target.end());
        int n = target.size();
        //Checking for size of array == 1
        if(n == 1){
            return target[0] == 1;
        }
        //Calculating sum of whole array
        ll sum = accumulate(target.begin(),target.end(),0LL);
        while(maxHeap.top() != 1){
            //Previous sum
            ll largestElement = maxHeap.top();
            maxHeap.pop();
            //Handling a case of [1,5] where 1 has been added a bunch of times
            if(sum - largestElement == 1){
                return true;
            }
            //new sum - previous sum = sum of all other elements
            //previous sum - (new sum - previous sum)
            ll previous = largestElement % (sum - largestElement);
            sum = sum - largestElement + previous;
            if(previous == 0LL || previous == largestElement){
                return false;
            }
            maxHeap.push(previous);
        }
        return true;
    }
};