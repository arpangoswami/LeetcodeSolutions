class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream iss1(version1),iss2(version2);
        vector<int> q1,q2;
        string s;
        while(getline(iss1,s,'.')){
            q1.push_back(stoi(s));
        }
        while(getline(iss2,s,'.')){
            q2.push_back(stoi(s));
        }
        if(q1.size() > q2.size()){
            q2.resize(q1.size());
        }else{
            q1.resize(q2.size());
        }
        int N = q1.size();
        for(int i=0;i<N;i++){
            //cout<<q1[i]<<" "<<q2[i]<<"\n";
            if(q1[i] < q2[i]){
                return -1;
            }else if(q1[i] > q2[i]){
                return 1;
            }
        }
        return 0;
    }
};