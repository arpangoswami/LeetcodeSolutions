class Solution {
public:
    long power(int a,int b){
        if(b==0) return 1;
        long smallProduct = power(a,b/2);
        if(b&1) return a*smallProduct*smallProduct;
        return smallProduct*smallProduct;
    }
    int myAtoi(string str) {
        int i=0,n = str.size();
        while(i<n && str[i]==' '){
            i++;
        }
        if(i==str.size()) return 0;
        if((str[i]>57 || str[i]<48)&&(str[i]!='-')&&(str[i]!='+')){
            return 0;
        }
        bool negative = false;
        if(str[i]=='-' || str[i]=='+'){
            if(str[i]=='-'){  
                negative = true;
                i++;
            }
            else{
                i++;
            }
        }
        int arr[str.size()],j=0;
        while(str[i]==48 && i<str.size()){
            i++;
        }
        while(str[i]>=48 && str[i]<=57 && i<str.size()){
            arr[j++] = str[i++]-48;
        }
        long num = 0;
        if(j>10){
            if(negative) return INT_MIN;
            else return INT_MAX;
        }
        int max_power = min(j,10),temp = max_power;
        for(int k=0;k<max_power;k++){
            num+=(arr[k]*power(10,(--temp)));
        }
        if(num==abs(INT_MIN) && negative) return INT_MIN;
        if(num>INT_MAX && negative){
            return (INT_MIN);
        }
        else if(num>INT_MAX && !negative){
            return INT_MAX;
        }
        if(negative){
            return ((int)num*(-1));
        }
        else{
            return (int)num;
        }
    }
};