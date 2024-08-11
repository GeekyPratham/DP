#include <iostream>
#include <climits>
#include <vector>

using namespace std;


vector<int> get_digit(int n){
    vector<int> digits;
    while(n>0){
        if(n%10!=0){ // hamara last digit 0 nahi hona chaiya nahi toh infinite loop me chal jaiga
        
            digits.push_back(n%10);
        }
        n=n/10;
    }
    return digits;
}

vector<int> dp;
int f(int n){
    if(n==0) return 0;
    if(n<10) return 1;
    if(dp[n]!=-1) return dp[n];
    int result = INT_MAX;
    vector<int> d = get_digit(n);
    for(int i=0;i<d.size();i++){
        result=min(result,f(n-d[i]));
        
    }
    return dp[n] = 1+result;
   
}

int fbu(int num){ // tc=O(n);
    
    dp[0] = 0;
    for(int i=1;i<=9;i++){
        dp[i]  = 1;

    }
    for(int n=10;n<=num;n++){
        // order
        // dp[n] calculate
        vector<int> d = get_digit(n);
        int result = INT_MAX;
        for(int i=0;i<d.size();i++){
            result=min(result,dp[n-d[i]]);
        }
        dp[n]=1+result;
    }
    return dp[num];

}
int main(){
    
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1000006,-1);
    cout<<fbu(n)<<" "<<f(n);
    return 0;
}