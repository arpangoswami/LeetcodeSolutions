class Solution {
private:
    // >0: need to stamp
    // 0: no need to stamp
    // -1: cannot stamp
    int needStamp(int index, const string& stamp, string& target) {
        int count = 0;
        for (int i = 0; i < stamp.length() && i+index < target.length(); i++) {
            if (target[i+index] == '?') {
                continue;
            } else if (target[i+index] == stamp[i]) {
                count ++;
            } else {
                count = -1;
                break;
            }
        }
        if (count > 0) {
            for(int i = 0; i < stamp.length() && i+index < target.length(); i++) {
                target[i+index] = '?';
            }
        }
        return count;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        queue<int> q; //record every index has not be stamped
        vector<int> order;
        for (int i = 0; i + stamp.length() <= target.length();i++) {
            q.push(i);
        }
        while (true) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                int index = q.front();
                q.pop();
                int status = needStamp(index, stamp, target);
                if (status > 0) { // need stamp
                    order.push_back(index);
                }
                else if (status < 0) { // cannot be stamped
                    q.push(index);
                }
            }
            if (length == q.size()) { //which means no index has been stamped
                break;
            }
        }
        
        if (q.size() > 0) { // is any index cannot be stamped, return empty array
            return vector<int>();
        }
        std::reverse(order.begin(),order.end()); 
        return order;
    }
};