class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for(string &x:ops){
            if(isdigit(x[0]) || x[0] == '-'){
                record.push_back(stoi(x));
            }else if(x[0] == '+'){
                int N = record.size();
                record.push_back(record[N-1]+record[N-2]);
            }else if(x[0] == 'D'){
                int N = record.size();
                record.push_back(2*record[N-1]);
            }else{
                record.pop_back();
            }
        }
        return accumulate(record.begin(),record.end(),0);
    }
};