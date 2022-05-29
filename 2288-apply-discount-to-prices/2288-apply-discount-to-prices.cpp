class Solution {
    bool isPrice( string myString ) {
        if(myString.size() == 0){
            return false;
        }
        if(myString[0] != '$'){
            return false;
        }
        myString = myString.substr(1);
        std::istringstream iss(myString);
        float f;
        iss >> noskipws >> f; // noskipws considers leading whitespace invalid
        // Check the entire string was consumed and if either failbit or badbit is set
        return iss.eof() && !iss.fail() && f >= 0.00; 
    }
    void modify(string &x,int discount){
        x = x.substr(1);
        istringstream iss(x);
        double d;
        iss >> d;
        double perc = discount/100.00;
        d = (1-perc)*d;
        ostringstream oss;
        oss << "$";
        oss << fixed << setprecision(2) << d;
        x = oss.str();
    }
public:
    string discountPrices(string sentence, int discount) {
        istringstream iss(sentence);
        vector<string> words;
        string s;
        while(iss >> s){
            words.push_back(s);
        }
        for(string &x:words){
            if(isPrice(x)){
                modify(x,discount);
            }
        }
        ostringstream oss;
        int N = words.size();
        for(int i=0;i<N;i++){
            oss << words[i];
            if(i != (N-1)){
                oss << " ";
            }
        }
        return oss.str();
    }
};