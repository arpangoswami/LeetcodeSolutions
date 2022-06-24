typedef long long ll;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<ll> pq(target.begin(),target.end());
        ll sum = 0;
        if(target.size() == 1){
            return target[0] == 1;
        }
        for(int x:target){
            sum += x;
        }
        if(pq.top() == sum){
            return false;
        }
        while(pq.top() != 1){
            ll largest = pq.top();
            pq.pop();
            ll nVal = 2*largest - sum;
            if(sum - largest == 1){
                return true;
            }
            if(nVal % (sum - largest) < 1){
                return false;
            }
            pq.push(nVal % (sum - largest));
            sum += (nVal % (sum - largest) - largest);
        }
        return true;
    }
};