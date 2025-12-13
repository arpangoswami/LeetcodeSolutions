class Solution {
    int getRank(std::string x) {
    if (x == "electronics") {
        return 1;
    } else if (x == "grocery") {
        return 2;
    } else if (x == "pharmacy") {
        return 3;
    } else if (x == "restaurant") {
        return 4;
    } 
    return -1;
    
}
    bool isValid(string couponCode, bool isActive, string businessLine) {
        for(char &ch:couponCode){
            if(!isalnum(ch) && ch != '_'){
                return false;
            }
        }
        return isActive && couponCode.size() > 0 && getRank(businessLine) > 0;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<tuple<string,string>> coupons;
        for(int i=0;i<n;i++){
            if(isValid(code[i], isActive[i], businessLine[i]))
                coupons.push_back(make_tuple(code[i], businessLine[i]));
        }
        sort(coupons.begin(), coupons.end(), [&](auto &t1, auto &t2){
            if(getRank(get<1>(t1)) == getRank(get<1>(t2))){
                return get<0>(t1) < get<0>(t2);
            }
            return getRank(get<1>(t1)) < getRank(get<1>(t2));
        });
        vector<string> ans;
        for(auto &t:coupons){
            ans.push_back(get<0>(t));
        }
        return ans;
    }
};