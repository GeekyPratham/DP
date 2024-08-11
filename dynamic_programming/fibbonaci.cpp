
// // top down dp solution -> recursive
// tc = O(2^n) and sc = O(n);
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> dp;

// int f(int n){
//     if(n==0 || n==1) return n; // base case
//     // dp check, to identify if problem was already solved earlier
//     if(dp[n] != -1) return dp[n];

//     return dp[n] = f(n-1)+f(n-2);// storing answer;
// }
// int main(){
//     int n = 5;
//     dp.clear();
//     dp.resize(n+1,-1); // dp vector of size  n+1; and intialay it store -1 it signifies it yet not computed
//     cout<<f(n)<<endl;
// }

// bottom up dp ->iterative
// tc = O(n) and sc = O(n);
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> dp;

// int f(int n){
//     dp.clear();
//     dp.resize(n+1,-1); // dp vector of size  n+1; and intialay it store -1 it signifies it yet not computed
    
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
        
//     }
//     return dp[n];
// }
// int main(){
//     int n = 7;
    
//     cout<<f(n)<<endl;
// }


// normal solution
// tc = O(n) and sc = O(1);

#include <iostream>

using namespace std;


int f(int n){
    int a = 0;
    int b = 1;
    if(n==0 || n==1) return n; // base case
    int i=2;
    int c;
    while(i<=n){
        c=a+b;
        a=b;
        b=c;
        i++;
    }
    return c;
}
int main(){
    int n = 7;
    
    cout<<f(n)<<endl;
}


