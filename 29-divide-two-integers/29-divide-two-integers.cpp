class Solution {
public:
    int num_bits(long long n){
        long long i;
        for(i = 1;i<32;i++){
            if((1<<i) == n){
                return (i+1);
            }
        }
        return ((int)log2(n)+1);
    }
    int divide(int dend, int disor) {
        long long dividend = dend,divisor = disor;
        long long result = 0;
        int neg = 1;
        
        if(!dividend)
            return 0;
        if(dend==INT_MIN && divisor==-1)
            return INT_MAX;
        if(dividend==-1 && divisor==1)
            return -1;
        if(dividend==1 && divisor==1)
            return 1;
        if(dividend==1 && divisor==-1)
            return -1;
        if(dividend==-1 && divisor==-1)
            return 1;
        if(dividend<0 && divisor>0){
            neg = -1;
            dividend = -dividend;
        }
        else if(dividend>0 && divisor<0){
            neg = -1;
            divisor = -divisor;
        }
        else if(dividend<0 && divisor<0){
            divisor = -divisor;
            dividend = -dividend;
        }
        bool flag = true;
        if(num_bits(dividend)==num_bits(divisor) && dividend>=divisor){
            result++;
            dividend-=divisor;
            flag = false;
        }
        
        if(divisor==1)
        {
            result = dividend;
            dividend = 0;
            flag = false;
        }
        if(disor==1 && dend==INT_MIN)
        {
            return INT_MIN;
        }
        if(flag)
        {
            while(dividend>divisor){
                int num_bits_dend = num_bits(dividend);
                int num_bits_sor = num_bits(divisor);
                int abs_bits = num_bits_dend - num_bits_sor;
                long long temp;
                if(abs_bits>0)
                {
                    temp = (divisor)<<(abs_bits - 1);
                }
                else{
                    result++;
                    break;
                }
                if(dividend>=(temp*2)){
                    result = result + (1<<abs_bits);
                   dividend -=(temp*2);
                }else if(dividend<(temp*2)){
                        result = result + (1<<(abs_bits - 1));
                        dividend -=(temp);
                }
                if(dividend == divisor){
                    result++;
                }
            }
        }
        //cout<<result<<endl;
        result = (neg)*result;
        return (int)result;
    }
};