#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> coins;
vector<int> dp(1000006,-2);

int f(int x) {
    if(x==0) return 0;  // base case;

    if(dp[x]!=-2) return dp[x];

    int result = INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(coins[i]>x) continue; // we dont call recursion 
        result = min(result,f(x-coins[i]));
    }
    if(result == INT_MAX) dp[x] = INT_MAX;
    else dp[x] = 1+result;

    return dp[x];

}
int main(){
    int n;
    int target;
    cin>>n>>target;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        coins.push_back(num);
    }
    int ans = f(target);
    if(ans == INT_MAX) cout<<"-1\n";
    else cout<<ans;

    return 0;

}