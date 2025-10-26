class Bank {
    vector<long long> balance;
    inline bool isValidAccount(int accountNum){
        return (balance.size() > accountNum && accountNum >= 0);
    }
public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if(!isValidAccount(account1) || !isValidAccount(account2) || money > balance[account1]){
            return false;
        }
        balance[account1] -= money;
        balance[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        account--;
        if(!isValidAccount(account)){
            return false;
        }
        balance[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if(!isValidAccount(account) || balance[account] < money){
            return false;
        }
        balance[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */