class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for(string &x:ops){
            if(x[0] == '+'){
                int N = record.size();
                record.push_back(record[N-1]+record[N-2]);
            }else if(x[0] == 'D'){
                int N = record.size();
                record.push_back(2*record[N-1]);
            }else if(x[0] == 'C'){
                record.pop_back();
            }else{
                record.push_back(stoi(x));
            }
        }
        return accumulate(record.begin(),record.end(),0);
    }
};