class Bank {
public:
    unordered_map<int,long long>passBook;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size();
        for(int i = 0;i < balance.size();i++){
            passBook[i+1] = balance[i];
            
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account2 > n)return false;
        if(money > passBook[account1])return false;
        if(account1 == account2)return true;
        long long updated_bal1 = passBook[account1] - money;
        long long updated_bal2 = passBook[account2] + money;
        passBook[account1] = updated_bal1;
        passBook[account2] = updated_bal2;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n)return false;
        passBook[account] = passBook[account] + money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n)return false;
        if(money > passBook[account])return false;
        passBook[account] = passBook[account] - money;
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
